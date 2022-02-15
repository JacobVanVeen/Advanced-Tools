#define GLEW_STATIC
#include "Gameobject.h"
#include <glm/glm.hpp>
#include <algorithm>
Gameobject::Gameobject()
{
    //ctor
}

Gameobject::Gameobject(std::string pName)
{
    Name = pName;
    glGenVertexArrays(1, &buffNumber);
    glGenBuffers(1,&vertexBuff);
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


void Gameobject::SetPos(glm::vec3 pPos)
{
    translationMatrix[3][0] = pPos[0];
    translationMatrix[3][1] = pPos[1];
    translationMatrix[3][2] = pPos[2];
}

void Gameobject::SetRot(glm::vec3 pRot)
{


}

void Gameobject::Update(int pDeltaTime)
{

    for (int i=0; i < childeren.size(); i++)
    {
       childeren[i]->Update(pDeltaTime);
    }
}


std::vector<Gameobject*> Gameobject::GetChildren()
{
    return childeren;
}
