#define GLEW_STATIC
#include <iostream>
#include "Gameobject.h"
#include <glm/glm.hpp>
#include <algorithm>
#include "glm/ext.hpp"
#include "glm/gtx/string_cast.hpp"

Gameobject::Gameobject()
{
    //ctor
}

Gameobject::Gameobject(std::string pName)
{
    Name = pName;
    glGenVertexArrays(1, &buffNumber);
    glGenBuffers(1,&vertexBuff);
    translationMatrix = glm::mat4(1);
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
    position = pPos;
    //translationMatrix = glm::translate(translationMatrix,position);
    translationMatrix[3][0] = pPos[0];
    translationMatrix[3][1] = pPos[1];
    translationMatrix[3][2] = pPos[2];
}

void Gameobject::SetRot(glm::vec3 pRot)
{


   // translationMatrix = glm::mat4(1);
    translationMatrix = glm::rotate(translationMatrix,rotation[0] - pRot[0],glm::vec3(1,0,0));
    translationMatrix = glm::rotate(translationMatrix,rotation[1] - pRot[1],glm::vec3(0,1,0));
    translationMatrix = glm::rotate(translationMatrix,rotation[1] - pRot[2],glm::vec3(0,0,1));

    rotation = pRot;
}

void Gameobject::rotateObject(glm::vec3 pAxis,float degrees)
{
    translationMatrix = glm::rotate(translationMatrix,degrees,pAxis);
    //std::cout << glm::to_string(translationMatrix) << std::endl;
    //std::cout << glm::to_string(pAxis) << std::endl;
    //std::cout << degrees << std::endl;
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


glm::mat4 Gameobject::GetMatrix()
{
    return translationMatrix;
}

/*glm::mat4 SetMatrix(glm::mat4 pMat)
{
    translationMatrix = pMat
}*/
