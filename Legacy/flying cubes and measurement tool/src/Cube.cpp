#include "Cube.h"
#include <iostream>
#include <vector>

constexpr glm::vec3 Cube::CUBEVERTS[];

Cube::Cube(std::string pName) : Gameobject(pName)
{
    Verts.insert(Verts.end(),Cube::CUBEVERTS,Cube::CUBEVERTS + sizeof(Cube::CUBEVERTS) / sizeof(glm::vec3));
    Color = glm::vec4(1,1,0,1);
}

Cube::~Cube()
{
    //dtor
}

void Cube::Update(int pDeltatime)
{
    rotateObject(glm::vec3(0,1,0),0.01);
    rotateObject(glm::vec3(1,0,0),0.01);
}
