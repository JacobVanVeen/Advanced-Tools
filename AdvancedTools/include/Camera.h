#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include "Gameobject.h"

class Camera : public Gameobject
{
    public:
        static Camera* MainCamera;
        Camera();
        virtual ~Camera();


    protected:

    private:
};

#endif // CAMERA_H
