#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include <glm/glm.hpp>
#include <glew.h>
#include <string>
class Gameobject
{
    public:
        Gameobject();
        Gameobject(std::string pName);
        virtual ~Gameobject();
        void SetParent(Gameobject* pParent);
        void AddChild(Gameobject* pChild);
        std::vector<glm::vec3> Verts;
        glm::vec4 Color;
        std::string Name;
        std::vector<Gameobject*> GetChildren();



        GLuint buffNumber = NULL;
        GLuint vertexBuff = NULL;
        glm::vec3 GetPos() {return position;}
        glm::vec3 GetRot() {return rotation;}
        void SetPos(glm::vec3 pPos);
        void SetRot(glm::vec3 pRot);
        virtual void Update(int pDeltaTime);
    protected:
        void render();
    private:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::mat4 translationMatrix;
        std::vector<Gameobject*> childeren;
        Gameobject* parent;
};

#endif // GAMEOBJECT_H
