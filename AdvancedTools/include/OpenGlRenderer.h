#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H
#include "Renderer.h"
#include "world.h"

class OpenGlRenderer : public Renderer
{
    public:
        OpenGlRenderer(World* pWorld);
        virtual ~OpenGlRenderer();
        void Render() override;
    protected:

    private:
};

#endif // OPENGLRENDERER_H
