#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include <glm/glm.hpp>
class Gameobject
{
    public:
        Gameobject();
        virtual ~Gameobject();
        void SetParent(Gameobject* pParent);
        void AddChild(Gameobject* pChild);
        glm::vec3 Position;
        glm::vec3 Rotation;
    protected:

    private:
    std::vector<Gameobject*> childeren;
    Gameobject* parent;
};

#endif // GAMEOBJECT_H
