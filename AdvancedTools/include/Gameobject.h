#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
class Gameobject
{
    public:
        Gameobject();
        virtual ~Gameobject();
        void SetParent(Gameobject* pParent);
        void AddChild(Gameobject* pChild);
    protected:

    private:
    std::vector<Gameobject*> childeren;
    Gameobject* parent;
};

#endif // GAMEOBJECT_H
