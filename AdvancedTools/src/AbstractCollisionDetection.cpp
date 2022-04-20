#include "AbstractCollisionDetection.h"

AbstractCollisionDetection::AbstractCollisionDetection()
{
    //ctor
}

AbstractCollisionDetection::~AbstractCollisionDetection()
{
    //dtor
}

bool AbstractCollisionDetection::WasColliding(Gameobject* gameObjectA,Gameobject* GameobjectB,int* indexOutput)
{
    for(int i = 0; i < collisions.size(); i++)
    {
        if ((gameObjectA == collisions[i].gameobjectA && GameobjectB == collisions[i].gameobjectB) || (gameObjectA == collisions[i].gameobjectB && GameobjectB == collisions[i].gameobjectA))
        {
            *indexOutput = i;
            return true;
        }
    }
    return false;
}


void AbstractCollisionDetection::CheckCollisions(std::vector<Colider*>* pColiders)
{

}

void AbstractCollisionDetection::WriteReport()
{

}


uint16_t AbstractCollisionDetection::GetLatestCollisionsChecked()
{
    return collisionsChecked.back();
}

uint16_t AbstractCollisionDetection::GetLatestCollisionsFound()
{
    return collisionsFound.back();
}

