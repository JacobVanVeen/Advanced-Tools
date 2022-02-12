#ifndef COLIDER_H
#define COLIDER_H
#include <glm/glm.hpp>
#include "BoxColider.h"
#include "Gameobject.h"
class Colider
{
    public:
        Colider(Gameobject* pOwner);
        virtual ~Colider();
        bool IsColiding(BoxColider* pBoxA,BoxColider* pBoxB);
    protected:

    private:
        Gameobject* owner;
};

#endif // COLIDER_H
