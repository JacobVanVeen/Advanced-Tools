#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include "Renderer.h"
#include "Camera.h"
#include "BoxColider.h"
#include "KeyboardCube.h"
#include "Colider.h"
#include "CollisionMeasuringTool.h"


struct Collision
{
    Gameobject* gameobjectA;
    Gameobject* gameobjectB;
};


class Game
{
    public:
        Game(int pWidth,int pHeight,bool fullscreen);
        virtual ~Game();
        void Run();
        bool UnlockedFps = false;
        int TargetFps = 60;
        void RenderWorld();
    protected:

    private:
        void SetupOpenGlWindow();
        void RunTillClose(); // for debuging stuff
        int fps =0;
        Renderer* renderer;
        World* world;
        Camera* camera;
        std::vector<Colider*> coliders;
        void CheckColisions();
        std::vector<Collision> collisions;
        bool WasColliding(Gameobject* gameObjectA,Gameobject* GameobjectB,int* pIndex);
        CollisionMeasuringTool* mTool;

};

#endif // GAME_H
