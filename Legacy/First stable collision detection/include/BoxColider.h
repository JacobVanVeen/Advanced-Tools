#ifndef BOXCOLIDER_H
#define BOXCOLIDER_H
#include "Colider.h"
#include "Gameobject.h"
#include <glm/glm.hpp>
class BoxColider : public Colider
{
    public:
        BoxColider(Gameobject* pOwner);
        virtual ~BoxColider();
        bool IsColiding(Colider* pOther) override;
        glm::vec3 Scale;
    protected:

    private:
        bool obbvobb(BoxColider* pBox);
        bool getSeparatingPlane( glm::vec3 RPos, glm::vec3 Plane, BoxColider* pBoxA, BoxColider* pBoxB);
     //   bool getSeparatingPlane( glm::vec3 RPos, glm::vec3 Plane, glm::mat4 pBoxAmat, glm::mat4 pBoxBmat);
};

#endif // BOXCOLIDER_H
