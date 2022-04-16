#include "Colider.h"
#include "Gameobject.h"

Colider::Colider(Gameobject* pOwner)
{
    owner = pOwner;
}

Colider::~Colider()
{
    //dtor
}

Gameobject* Colider::GetOwner()
{
    return owner;
}

//bool Colider::IsColiding(Colider* pOther)
//{
//
//}
