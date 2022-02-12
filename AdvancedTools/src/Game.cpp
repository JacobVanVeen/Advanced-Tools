#define GLEW_STATIC
#include "Game.h"
#include <SDL.h>
//#include <glew.h>
#include <SDL_opengl.h>
#include <iostream>



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


        //set the bits per pixel. Lets do 5 for now.
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    //set the depth buffer size.
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
   //SDL_GL_SetSwapInterval(1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_PROFILE_MASK,
        SDL_GL_CONTEXT_PROFILE_CORE);




    ctx = SDL_GL_CreateContext(window);
    if (ctx == NULL)
    {
        std::cout << "Error getting opengl context" << std::endl;
    }

    SDL_GL_MakeCurrent( window, ctx );
  /*  GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cout << "argh!" << std::endl;
        return;
    }*/

    glClearColor(1.0f,0.0f,1.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(window);
    glClearColor(0.0f,1.0f,1.0f,0.0f);

                glClear(GL_COLOR_BUFFER_BIT);
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

            //Render everything

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
