#include "BouncingCube.h"
#include "RandomNumber.h"
BouncingCube::BouncingCube() : Gameobject("BouncingCube")
{
    Verts.insert(Verts.end(),Cube::CUBEVERTS,Cube::CUBEVERTS + sizeof(Cube::CUBEVERTS) / sizeof(glm::vec3));
    Color = glm::vec4(1,0,0,1);
    velocity = glm::vec3(RandomNumber::GetRandom(-1,1),RandomNumber::GetRandom(-1,1),RandomNumber::GetRandom(-1,1));
    SetPos(glm::vec3(RandomNumber::GetRandom(-50,50),RandomNumber::GetRandom(-50,50),RandomNumber::GetRandom(-50,50)));
}

BouncingCube::~BouncingCube()
{
    //dtor
}

void BouncingCube::Update(int pDetalTime)
{
        float ms = pDetalTime/60;
    glm::vec3 newpos = GetPos() + velocity * ms;

    if (std::abs(newpos.y) > 50)
    {
        velocity.y = -velocity.y;
    }
    if (std::abs(newpos.x) > 50)
    {
        velocity.x = -velocity.x;
    }
    if (std::abs(newpos.z) > 50)
    {
        velocity.z = -velocity.z;
    }

    newpos = GetPos() + velocity;
    SetPos(newpos);

    rotateObject(glm::vec3(0,1,0),0.01);
    rotateObject(glm::vec3(1,0,0),0.01);

}


void BouncingCube::OnCollision(Gameobject* pOther)
{
    Color = glm::vec4(0,1,0,1);
}


void BouncingCube::OnCollisionExit(Gameobject* pOther)
{
    Color = glm::vec4(1,0,0,1);
}
