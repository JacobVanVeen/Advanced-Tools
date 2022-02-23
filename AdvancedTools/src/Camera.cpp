#include "Camera.h"
#include "Gameobject.h"
#include <string>
#include <iostream>
#include <SDL.h>
#include "glm/gtx/string_cast.hpp"
#include "glm/gtx/rotate_vector.hpp"


Camera* Camera::MainCamera;

Camera::Camera() : Gameobject("Camera")
{
Camera::MainCamera = this;
}

Camera::~Camera()
{
    //dtor
}


glm::mat4 Camera::GetProjectionMatrix()
{
    return glm::perspective((float)45,(float)1,(float)0.1,(float)10000);
}

void Camera::Update(int pDetalTime)
{
   // rotateAround(glm::vec3(0,0,0),glm::vec3(0,1,0),0.01f);


    const Uint8 *KeyboardState = SDL_GetKeyboardState(NULL);
    if(KeyboardState[SDL_SCANCODE_A])
    {
        rotateAround(glm::vec3(0,0,0),glm::vec3(0,1,0),0.01f);
           // rotateObject(glm::vec3(0,1,0),0.01f);

       // rotateObject(glm::vec3(0,1,0),0.05f);
    }
    else if (KeyboardState[SDL_SCANCODE_D])
    {
         rotateAround(glm::vec3(0,0,0),glm::vec3(0,1,0),-0.01f);
      // rotateObject(glm::vec3(0,1,0),-0.01f);
    }

    if(KeyboardState[SDL_SCANCODE_W])
    {
         rotateAround(glm::vec3(0,0,0),glm::vec3(1,0,0),0.01f);
    }
    else if(KeyboardState[SDL_SCANCODE_S])
    {
         rotateAround(glm::vec3(0,0,0),glm::vec3(1,0,0),-0.01f);
    }

    LookAt(glm::vec3(0,0,0));

}

void Camera::LookAt(glm::vec3 pPoint)
{
    glm::vec3 z = glm::normalize(pPoint - GetPos());
    glm::vec3 x = glm::normalize(glm::cross(z,glm::vec3(0,1,0)));
    glm::vec3 y = glm::cross(x,z);
    z *= -1;

    translationMatrix[0] = glm::vec4(x,0);
    translationMatrix[1] = glm::vec4(y,0);
    translationMatrix[2] = glm::vec4(z,0);

}
