#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game(int pWidth,int pHeight,bool fullscreen);
        virtual ~Game();

    protected:

    private:
        void SetupOpenGlWindow();
        void RunTillClose();
};

#endif // GAME_H
