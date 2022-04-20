#include "BspCell.h"
#include "Cube.h"

BspCell::BspCell(std::string pName) : Gameobject(pName)
{

}


BspCell::BspCell() : Gameobject("BspCell")
{
    Verts.insert(Verts.end(),Cube::CUBEVERTS,Cube::CUBEVERTS + sizeof(Cube::CUBEVERTS) / sizeof(glm::vec3));
    Color = glm::vec4(0,0,1,0);
    TradColDect = new TraditionalCollisionDetection();
}

BspCell::~BspCell()
{
    //dtor
}

void BspCell::OnCollision(Gameobject* pOther)
{
    inhabitans.push_back(pOther->GetColider());
}

void BspCell::OnCollisionExit(Gameobject* pOther)
{

    Colider* col = pOther->GetColider();
    for (int i=0;i< inhabitans.size();i++)
    {
        if (inhabitans[i] == col)
        {
            inhabitans.erase(inhabitans.begin() + i); //not sure if this works;
            break;
        }
    }
}

void BspCell::CheckCollisions()
{
    TradColDect->CheckCollisions(&inhabitans);
}

TraditionalCollisionDetection* BspCell::GetTradColDet()
{
    return TradColDect;
}

bool BspCell::IsColliding(Gameobject* pObject)
{
    if (std::find(inhabitans.begin(),inhabitans.end(),pObject->GetColider() ) != inhabitans.end())
    {
        return true;
    }
    return false;
}


