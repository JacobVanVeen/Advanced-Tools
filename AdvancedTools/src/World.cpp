#include "World.h"
#include "Gameobject.h"
#include "Gameobject.h"
World::World()
{

}

World::~World()
{
    //dtor
}


void World::AddToWorld(Gameobject* pObject)
{
    root.AddChild(pObject);
}
