#ifndef BOUNCINGCUBE_H
#define BOUNCINGCUBE_H
#include "Cube.h"
#include "Gameobject.h"
#include <glm/glm.hpp>
#include <SDL.h>

class BouncingCube : public Gameobject
{
    public:
        BouncingCube();
        virtual ~BouncingCube();
        void Update(int pDetalTime) override;
        void OnCollision(Gameobject* Other) override;
        void OnCollisionExit(Gameobject* Other) override;

    protected:

    private:
        glm::vec3 velocity;
};

#endif // BOUNCINGCUBE_H
