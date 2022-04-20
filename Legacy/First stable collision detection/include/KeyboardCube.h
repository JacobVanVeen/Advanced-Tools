#ifndef KEYBOARDCUBE_H
#define KEYBOARDCUBE_H
#include "Gameobject.h"
#include <glm/glm.hpp>
#include <SDL.h>

class KeyboardCube : public Gameobject
{
    public:
        KeyboardCube();
        virtual ~KeyboardCube();
        void Update(int pDetalTime) override;
        void OnCollision(Gameobject* Other) override;
        void OnCollisionExit(Gameobject* Other) override;
    protected:

    private:
        float movementSpeed = 0.1f;
};

#endif // KEYBOARDCUBE_H
