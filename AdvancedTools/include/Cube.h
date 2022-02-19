#ifndef CUBE_H
#define CUBE_H

#include <string>
#include "Gameobject.h"

class Cube : public Gameobject
{
    public:
        Cube(std::string pName);
        virtual ~Cube();

    protected:

    private:
};

#endif // CUBE_H
