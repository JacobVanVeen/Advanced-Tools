#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
        glm::vec4 Color;    // I know it's not very nice to add the color here, Should be in some shader class or something but I'm running low on time. :/
        std::string Name;
        std::vector<Gameobject*> GetChildren();



        GLuint buffNumber = NULL;
        GLuint vertexBuff = NULL;
        glm::vec3 GetPos();
        glm::vec3 GetRot() {return rotation;}
        void SetPos(glm::vec3 pPos);
        void SetRot(glm::vec3 pRot);
        glm::mat4 GetMatrix();
        virtual void Update(int pDeltaTime);
        virtual void OnCollision(Gameobject* other);
        virtual void OnCollisionStay(Gameobject* other);
        virtual void OnCollisionExit(Gameobject* other);
        void rotateObject(glm::vec3 pAxis,float degrees);
        void rotateAround(glm::vec3 pObject,glm::vec3 pAxis,float pRads);
    protected:
        void render();
        glm::mat4 translationMatrix;
    private:
        glm::vec3 position;
        glm::vec3 rotation;

        std::vector<Gameobject*> childeren;
        Gameobject* parent;
};

#endif // GAMEOBJECT_H
