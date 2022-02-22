#define GLEW_STATIC
#include "Renderer.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include "Camera.h"
#include "glm/ext.hpp"




Renderer::Renderer()
{

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

        glEnable(GL_DEPTH_TEST);
        glFrontFace(GL_CCW);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
	/*glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/

    const char* vertex_shader =
    "#version 400\n"
    "in vec3 vp;"
    "in vec4 vcolor;"
    "uniform mat4 projectionMatrix;"
    "uniform mat4 viewMatrix;"
    "uniform mat4 modelMatrix;"
    "out vec4 colorv;"
    "void main() {"
    //"  colorv = vcolor;"

   // "  gl_Position = vec4(vp, 1.0);"
    "  gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vp, 1.f);"
    "  float c = (1+gl_Position.y)/2;"
    "   c += 0.1;"
    "  colorv = vec4(c,c,0,1);"
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

    shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);





}

Renderer::~Renderer()
{
    //dtor
}

void Renderer::Render(World* pWorld)
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    //glClear(GL_COLOR_BUFFER_BIT); // clear screen
    glm::mat4 viewMatrix = glm::inverse(Camera::MainCamera->GetMatrix());
    glm::mat4 ProjectionMatrix = Camera::MainCamera->GetProjectionMatrix();



    Gameobject* root = pWorld->GetRoot();
    Render(root,viewMatrix,ProjectionMatrix);


}

void Renderer::Render(Gameobject* pObject,glm::mat4& pViewMat,glm::mat4& pProjectionMat)
{
    //Might wanna try this at some point: http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-9-vbo-indexing/
    if (!pObject->Verts.empty())
    {
    glUseProgram(shader_programme);
    glBindVertexArray(pObject->buffNumber);


    glBindBuffer(GL_ARRAY_BUFFER,pObject->vertexBuff);
    glBufferData(GL_ARRAY_BUFFER, pObject->Verts.size() * 3 * sizeof(float), &pObject->Verts[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, pObject->buffNumber);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);


    glUniformMatrix4fv ( glGetUniformLocation (shader_programme, "projectionMatrix"),   1, GL_FALSE, glm::value_ptr(pProjectionMat));
    glUniformMatrix4fv ( glGetUniformLocation (shader_programme, "viewMatrix"),         1, GL_FALSE, glm::value_ptr(pViewMat));
    glUniformMatrix4fv ( glGetUniformLocation (shader_programme, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(pObject->GetMatrix()));


    // draw points 0-3 from the currently bound VAO with current in-use shader
    glDrawArrays(GL_TRIANGLES, 0, pObject->Verts.size());
    }

     std::vector<Gameobject*> children = pObject->GetChildren();

    if (!children.empty())
    {
        for (int i=0; i < children.size(); i++)
        {
            Render(children[i],pViewMat,pProjectionMat);
        }
    }

}
