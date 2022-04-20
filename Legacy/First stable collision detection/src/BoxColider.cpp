#include "BoxColider.h"
#include <stdio.h>
#include <iostream>


BoxColider::BoxColider(Gameobject* pOwner) : Colider(pOwner)
{
    //ctor
    Scale = glm::vec3(0.5f,0.5f,0.5f);
}

BoxColider::~BoxColider()
{
    //dtor
}

bool BoxColider::IsColiding(Colider* pOther)
{
    //find out what other colider we're dealing with:
    // Maybe interesting to test how much dynamic_cast costs?

    BoxColider* otherBox = dynamic_cast<BoxColider*> (pOther);
    if (otherBox != nullptr)
    {
        bool bisColiding = obbvobb(otherBox);
      //  std::cout << bisColiding << std::endl;
        return bisColiding;
    }
    return false;
}

bool BoxColider::obbvobb( BoxColider* pBox)
{
    glm::vec3 RPos;
    BoxColider* anotherPtr = pBox;
    RPos = pBox->GetOwner()->GetPos() - GetOwner()->GetPos();
    glm::mat4 boxAmat = GetOwner()->GetMatrix();
    glm::mat4 boxBmat = pBox->GetOwner()->GetMatrix();

    return !(getSeparatingPlane(RPos, (glm::vec3) boxAmat[0], this, pBox) ||
        getSeparatingPlane(RPos, (glm::vec3) boxAmat[1], this, pBox) ||
        getSeparatingPlane(RPos, (glm::vec3) boxAmat[2], this, pBox) ||
        getSeparatingPlane(RPos, (glm::vec3) boxBmat[0], this, pBox) ||
        getSeparatingPlane(RPos, (glm::vec3) boxBmat[1], this, pBox) ||
        getSeparatingPlane(RPos, (glm::vec3) boxBmat[2], this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[0],(glm::vec3)boxBmat[0]), this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[0],(glm::vec3)boxBmat[1]), this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[0],(glm::vec3)boxBmat[2]), this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[1],(glm::vec3)boxBmat[0]), this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[1],(glm::vec3)boxBmat[1]), this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[1],(glm::vec3)boxBmat[2]), this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[2],(glm::vec3)boxBmat[0]), this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[2],(glm::vec3)boxBmat[1]), this, pBox) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[2],(glm::vec3)boxBmat[2]), this, pBox));

    return true;
}

// check if there's a separating plane in between the selected axes
bool BoxColider::getSeparatingPlane( glm::vec3 RPos, glm::vec3 Plane, BoxColider* pBoxA, BoxColider* pBoxB)
{
    glm::mat4 pBoxAmat = pBoxA->GetOwner()->GetMatrix();
    glm::mat4 pBoxBmat = pBoxB->GetOwner()->GetMatrix();

    glm::vec3 scaleA = pBoxA->Scale;
    glm::vec3 scaleB = pBoxB->Scale;

    return (fabs(glm::dot(RPos,Plane)) >
        (fabs(glm::dot((glm::vec3)(pBoxAmat[0]*scaleA.x),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxAmat[1]*scaleA.y),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxAmat[2]*scaleA.z),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxBmat[0]*scaleB.x),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxBmat[1]*scaleB.y),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxBmat[2]*scaleB.z),Plane))
             ));
}

