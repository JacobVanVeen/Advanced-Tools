#ifndef CUBE_H
#define CUBE_H

#include <string>
#include "Gameobject.h"
#include <glm/glm.hpp>

class Cube : public Gameobject
{
    public:
        Cube(std::string pName);
        virtual ~Cube();
        void Update(int pDetalTime) override;

        static constexpr glm::vec3 CUBEVERTS[] =
        {
            glm::vec3(.5f,.5f,-0.5f),glm::vec3(.5f,-.5f,-0.5f),glm::vec3(-.5f,-.5f,-0.5f), //front
            glm::vec3(.5f,.5f,-0.5f),glm::vec3(-.5f,-.5f,-0.5f),glm::vec3(-.5f,.5f,-0.5f),
            glm::vec3(.5f,.5f,0.5f),glm::vec3(-.5f,-.5f,0.5f),glm::vec3(.5f,-.5f,0.5f), //back
            glm::vec3(.5f,.5f,0.5f),glm::vec3(-.5f,.5f,0.5f),glm::vec3(-.5f,-.5f,0.5f),
            glm::vec3(.5f,.5f,0.5f),glm::vec3(.5f,-.5f,0.5f),glm::vec3(.5f,-.5f,-0.5f), //left
            glm::vec3(.5f,.5f,0.5f),glm::vec3(.5f,-.5f,-0.5f),glm::vec3(.5f,.5f,-0.5f),
            glm::vec3(-.5f,.5f,0.5f),glm::vec3(-.5f,-.5f,-0.5f),glm::vec3(-.5f,-.5f,0.5f), //right
            glm::vec3(-.5f,.5f,0.5f),glm::vec3(-.5f,.5f,-0.5f),glm::vec3(-.5f,-.5f,-0.5f),
            glm::vec3(.5f,-.5f,-0.5f),glm::vec3(.5f,-.5f,0.5f),glm::vec3(-.5f,-.5f,-0.5f), //Bottom
            glm::vec3(.5f,-.5f,0.5f),glm::vec3(-.5f,-.5f,0.5f),glm::vec3(-.5f,-.5f,-0.5f),
            glm::vec3(-.5f,.5f,-0.5f),glm::vec3(.5f,.5f,0.5f),glm::vec3(.5f,.5f,-0.5f), //UP
            glm::vec3(-.5f,.5f,-0.5f),glm::vec3(-.5f,.5f,0.5f),glm::vec3(.5f,.5f,0.5f)
        };


    protected:

    private:
};



#endif // CUBE_H
