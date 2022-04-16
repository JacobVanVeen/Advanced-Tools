#include "BoxColider.h"
#include <stdio.h>
#include <iostream>


BoxColider::BoxColider(Gameobject* pOwner) : Colider(pOwner)
{
    //ctor
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
        std::cout << "Is another Box! :)" << std::endl;
        bool bisColiding = obbvobb(otherBox);
        std::cout << bisColiding << std::endl;
        return bisColiding;
    }
    else
    {
        std::cout << "is NOT another box :(" << std::endl;
    }
    return false;
}

bool BoxColider::obbvobb( BoxColider* pBox)
{
    glm::vec3 RPos;
    RPos = pBox->GetOwner()->GetPos() - GetOwner()->GetPos();
    glm::mat4 boxAmat = GetOwner()->GetMatrix();
    glm::mat4 boxBmat = pBox->GetOwner()->GetMatrix();

    return !(getSeparatingPlane(RPos, (glm::vec3) boxAmat[0], boxAmat, boxBmat) ||
        getSeparatingPlane(RPos, (glm::vec3) boxAmat[1], boxAmat, boxBmat) ||
        getSeparatingPlane(RPos, (glm::vec3) boxAmat[2], boxAmat, boxBmat) ||
        getSeparatingPlane(RPos, (glm::vec3) boxBmat[0], boxAmat, boxBmat) ||
        getSeparatingPlane(RPos, (glm::vec3) boxBmat[1], boxAmat, boxBmat) ||
        getSeparatingPlane(RPos, (glm::vec3) boxBmat[2], boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[0],(glm::vec3)boxBmat[0]), boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[0],(glm::vec3)boxBmat[1]), boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[0],(glm::vec3)boxBmat[2]), boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[1],(glm::vec3)boxBmat[0]), boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[1],(glm::vec3)boxBmat[1]), boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[1],(glm::vec3)boxBmat[2]), boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[2],(glm::vec3)boxBmat[0]), boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[2],(glm::vec3)boxBmat[1]), boxAmat, boxBmat) ||
         getSeparatingPlane(RPos, (glm::vec3) glm::cross((glm::vec3)boxAmat[2],(glm::vec3)boxBmat[2]), boxAmat, boxBmat));

    return true;
}

// check if there's a separating plane in between the selected axes
bool BoxColider::getSeparatingPlane( glm::vec3 RPos, glm::vec3 Plane, glm::mat4 pBoxAmat, glm::mat4 pBoxBmat)
{
    return (fabs(glm::dot(RPos,Plane)) >
        (fabs(glm::dot((glm::vec3)(pBoxAmat[0]*0.5f),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxAmat[1]*0.5f),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxAmat[2]*0.5f),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxBmat[0]*0.5f),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxBmat[1]*0.5f),Plane)) +
        fabs(glm::dot((glm::vec3)(pBoxBmat[2]*0.5f),Plane))
             ));
}

