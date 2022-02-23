#define GLEW_STATIC
#include "Game.h"
#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <iostream>
#include "MovingShape.h"
#include "cube.h"
#include "Camera.h"
#include "RandomNumber.h"


int windowHeight;
int windowWidth;
char* title;
SDL_Window* window;
SDL_GLContext ctx;

Game::Game(int pWidth,int pHeight,bool fullscreen)
{
    title = "Advanced Tools";
    windowHeight = pHeight;
    windowWidth = pWidth;

    Game::SetupOpenGlWindow();
}

Game::~Game()
{
    delete(title);
}



void Game::SetupOpenGlWindow()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error SDL Init" << std::endl;
        return;
    }



    int flags = SDL_WINDOW_OPENGL;
    window = SDL_CreateWindow(title,200,200,windowWidth,windowHeight,flags);
    if (window == NULL)
    {
        std::cout << "Can't create window" << std::endl;
        return;
    }
            SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,32);
        ctx = SDL_GL_CreateContext(window);

    if (ctx == NULL)
    {
        std::cout << "Error getting opengl context" << std::endl;
        return;
    }

    SDL_GL_MakeCurrent( window, ctx );


    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        std::cout << "Error initializing Glew, error: " << err << std::endl;
        return;
    }
    camera = new Camera();
    renderer = new Renderer();
    world = new World();
    world->AddToWorld(camera);

    camera->SetPos(glm::vec3(0,0,-10));
    camera->SetRot(glm::vec3(0,3.14f,0));
    //camera->SetRot(glm::vec3(-3.14f / 4,3.14f,0));
   // camera->SetRot(glm::vec3(0,3.14,0));

    Cube* tryout = new Cube("cube");
    world->AddToWorld(tryout);

    Cube* cube2 = new Cube("cube2");
    world->AddToWorld(cube2);
    cube2->SetPos(glm::vec3(-1,0,6));


        // change background color
    glClearColor(0.0f,0.0f,0.0f,0.0f);

    return;
        Gameobject* tryout2 = new Gameobject("Tryout2");
    tryout2->Verts.push_back(glm::vec3(1.0f,  1.0f,  0.0f));
    tryout2->Verts.push_back(glm::vec3(0.7f, 0.7f,  0.0f));
    tryout2->Verts.push_back(glm::vec3(1.0f, 0.0f,  0.0f));
    tryout->AddChild(tryout2);


            Gameobject* tryout3 = new MovingShape();
    tryout3->Verts.push_back(glm::vec3(-1.0f,  -1.0f,  0.0f));
    tryout3->Verts.push_back(glm::vec3(-0.7f, -0.7f,  0.0f));
    tryout3->Verts.push_back(glm::vec3(-1.0f, 0.0f,  0.0f));
    tryout->AddChild(tryout3);

    return;





    // expirimental stuff over here.
    // change background color
   // glClearColor(1.0f,0.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float trianglePoints[] = {
   0.0f,  0.5f,  0.0f,
   0.5f, -0.5f,  0.0f,
  -0.5f, -0.5f,  0.0f
    };


    float triangleColors[] = {
   1.0f,  0.0f,  0.0f, 1.0f,
   0.0f,  1.0f,  0.0f, 1.0f,
   0.0f,  0.0f,  1.0f, 1.0f,
    };


    GLuint vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vertexBuff =0;
    glGenBuffers(1,&vertexBuff);
    glBindBuffer(GL_ARRAY_BUFFER,vertexBuff);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), trianglePoints, GL_STATIC_DRAW);

    GLuint cbo = 0;
    glGenBuffers(1, &cbo);
    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), triangleColors, GL_STATIC_DRAW);


    glBindBuffer(GL_ARRAY_BUFFER, vao);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, cbo);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);

    const char* vertex_shader =
    "#version 400\n"
    "in vec3 vp;"
    "in vec4 vcolor;"
    "out vec4 colorv;"
    "void main() {"
    "  colorv = vcolor;"
    "  gl_Position = vec4(vp, 1.0);"
    "}";

    const char* fragment_shader =
    "#version 400\n"
    "out vec4 frag_colour;"
    "in vec4 colorv;"
    "void main() {"
    //"  frag_colour = vec4(1, 0.0, 0, 1.0);"
    "  frag_colour = colorv;"
    "}";

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    GLuint shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);

    glUseProgram(shader_programme);
    glBindVertexArray(vao);
    // draw points 0-3 from the currently bound VAO with current in-use shader
    glDrawArrays(GL_TRIANGLES, 0, 3);

    SDL_GL_SwapWindow(window); // call this at the end of every render.
}



uint32_t timebase=0;
uint32_t fpstimebase=0;
int TimePerFrameMs = 0;
int timeSinceLastUpdate=0;
int frameCount = 0;
uint32_t timeSinceFpsUpdate = 0;
void Game::Run()
{
    //setup timer stuff
   // timeAtStartOfFrame = SDL_GetTicks();
    TimePerFrameMs = 1000 / TargetFps;
    bool running = true;
    while (running)
    {
        uint32_t timeSinceLastFrame = (SDL_GetTicks() - timebase);
        if (timeSinceLastFrame != 0)
        {
            timebase = SDL_GetTicks();
        }
        timeSinceLastUpdate += timeSinceLastFrame;
        //check if it's time to update. Or if the framerate is unlocked always update;
        if (UnlockedFps || (timeSinceLastUpdate >= TimePerFrameMs))
        {
            //update world(DeltaTime)
            world->Update(timeSinceLastFrame);

           if (UnlockedFps)
           {
               timeSinceLastUpdate = 0;
           }
           else
           {
                timeSinceLastUpdate -= TimePerFrameMs;
           }


            SDL_Event event;
        while (SDL_PollEvent(&event))
        {
          if (event.type == SDL_KEYDOWN)
          {
            switch (event.key.keysym.sym)
            {
              case SDLK_ESCAPE:
                running = 0;
                break;
              default:
                break;
            }
          }
          else if (event.type == SDL_QUIT)
          {
            running = 0;
          }
        }
        if (running == false)
        {
            break;
        }


            RenderWorld();


            uint32_t timeSpanFps = (SDL_GetTicks() - fpstimebase);
            if (timeSpanFps !=0)
            {
            timeSinceFpsUpdate += timeSpanFps;
            fpstimebase = SDL_GetTicks();
            }

            frameCount++;
            if (timeSinceFpsUpdate >= 1000)
            {
                fps = (timeSinceFpsUpdate/1000) * frameCount;
                std::cout << "Count: " << frameCount << "TimeSinceFps: " << timeSinceFpsUpdate << std::endl;
                std::cout << "FPS: " << fps << std::endl;
                timeSinceFpsUpdate -= 1000;
                frameCount = 0;
            }
        }
    }

    //Game::RunTillClose();
    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void Game::RenderWorld()
{
    renderer->Render(world);
    SDL_GL_SwapWindow(window); // call this at the end of every render.
}


void Game::RunTillClose()
{
      bool running = 1;
      int timer = 0;
      bool red = true;
    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
          if (event.type == SDL_KEYDOWN)
          {
            switch (event.key.keysym.sym)
            {
              case SDLK_ESCAPE:
                running = 0;
                break;
              default:
                break;
            }
          }
          else if (event.type == SDL_QUIT)
          {
            running = 0;
          }
        }
        if (running == false)
        {
            break;
        }
        timer++;
        std::cout << timer << std::endl;
        if (timer >= 4000)
        {
            if (red)
            {
                glClearColor(0.0f,0.0f,1.0f,0.0f);
            }
            else
            {
              glClearColor(1.0f,0.0f,0.0f,0.0f);
            }
            red = !red;

        glClear(GL_COLOR_BUFFER_BIT);
        timer = 0;
        SDL_GL_SwapWindow(window);
        }
    }
}
