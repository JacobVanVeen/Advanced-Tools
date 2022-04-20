#ifndef RENDERER_H
#define RENDERER_H
#include "World.h"
#include <SDL.h>
#include <glew.h>


class Renderer
{
    public:
        Renderer();
        virtual ~Renderer();
        virtual void Render(World* pWorld);
        virtual void Render(Gameobject* pObject,glm::mat4& pViewMat,glm::mat4& pProjectionMat);

    protected:

    private:
        SDL_GLContext* ctx;
        GLuint shader_programme;

};

#endif // RENDERER_H
