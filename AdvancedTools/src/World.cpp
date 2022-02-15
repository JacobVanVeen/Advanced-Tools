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

void World::Update(int deltaTime)
{
    root.Update(deltaTime);
}


Gameobject* World::GetRoot()
{
    return &root;
}
