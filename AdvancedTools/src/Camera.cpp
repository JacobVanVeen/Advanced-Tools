#include "Camera.h"
#include "Gameobject.h"
#include <string>
#include <iostream>


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
    //rotateObject(glm::vec3(1,0,0),0.01);
   // SetRot(GetRot() + glm::vec3(0,0.01,0));
}
