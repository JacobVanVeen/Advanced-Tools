#include "Gameobject.h"
#include <glm/glm.hpp>
#include <algorithm>
Gameobject::Gameobject()
{
    //ctor
}

Gameobject::~Gameobject()
{
    //dtor
}


void Gameobject::SetParent(Gameobject* pParent)
{
    parent = pParent;
    parent->AddChild(this);
}

void Gameobject::AddChild(Gameobject* pChild){
    if (std::find(childeren.begin(),childeren.end(),pChild) == childeren.end())
    {
        childeren.push_back(pChild);
    }
}
