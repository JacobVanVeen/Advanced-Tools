#ifndef COLIDER_H
#define COLIDER_H
#include <glm/glm.hpp>
#include "Gameobject.h"
class Colider
{
    public:
        Colider(Gameobject* pOwner);
        virtual ~Colider();
       virtual bool IsColiding(Colider* pOther) = 0;
       Gameobject* GetOwner();
    protected:

    private:
        Gameobject* owner;
};

#endif // COLIDER_H
