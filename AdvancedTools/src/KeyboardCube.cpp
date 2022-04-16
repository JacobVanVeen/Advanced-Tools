#include "KeyboardCube.h"
#include "Cube.h"


KeyboardCube::KeyboardCube() : Gameobject("KeyboardCube")
{
    Verts.insert(Verts.end(),Cube::CUBEVERTS,Cube::CUBEVERTS + sizeof(Cube::CUBEVERTS) / sizeof(glm::vec3));
}

KeyboardCube::~KeyboardCube()
{
    //dtor
}


void KeyboardCube::Update(int pDetalTime)
{
    const Uint8 *KeyboardState = SDL_GetKeyboardState(NULL);
    if(KeyboardState[SDL_SCANCODE_UP])
    {
        SetPos(GetPos() + glm::vec3(0,0,movementSpeed));
    }
    else if (KeyboardState[SDL_SCANCODE_DOWN])
    {
         SetPos(GetPos() + glm::vec3(0,0,-movementSpeed));
      // rotateObject(glm::vec3(0,1,0),-0.01f);
    }

    if(KeyboardState[SDL_SCANCODE_LEFT])
    {
         SetPos(GetPos() + glm::vec3(movementSpeed,0,0));
    }
    else if(KeyboardState[SDL_SCANCODE_RIGHT])
    {
         SetPos(GetPos() + glm::vec3(-movementSpeed,0,0));
    }

}
