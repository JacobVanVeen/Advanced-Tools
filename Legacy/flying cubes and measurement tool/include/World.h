#ifndef WORLD_H
#define WORLD_H
#include "Gameobject.h"



class World
{
    public:
        World();
        virtual ~World();
        void AddToWorld(Gameobject* pObject);
        Gameobject* GetRoot();
        void Update(int pDeltaTime);
    protected:

    private:
        Gameobject root;
};

#endif // WORLD_H
