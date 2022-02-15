#include "Camera.h"
#include "Gameobject.h"
#include <string>


Camera* Camera::MainCamera;

Camera::Camera() : Gameobject("Camera")
{
Camera::MainCamera = this;
}

Camera::~Camera()
{
    //dtor
}
