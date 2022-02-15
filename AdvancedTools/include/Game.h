#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include "Renderer.h"

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

};

#endif // GAME_H
