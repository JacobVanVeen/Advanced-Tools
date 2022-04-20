#include "Colider.h"

Colider::Colider(Gameobject* pOwner)
{
    owner = pOwner;
    owner->SetColider(this);
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
