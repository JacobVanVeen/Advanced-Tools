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

bool Colider::IsColiding(BoxColider* pBoxA,BoxColider* pBoxB)
{

}
