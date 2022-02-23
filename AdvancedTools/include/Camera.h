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
        glm::mat4 GetProjectionMatrix();
        void Update(int pDetalTime) override;
        void LookAt(glm::vec3 pPoint);
    protected:

    private:
};

#endif // CAMERA_H
