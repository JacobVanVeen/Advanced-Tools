#include "MovingShape.h"
#include "Gameobject.h"
#include <iostream>
#include <math.h>

MovingShape::MovingShape() : Gameobject("movingShape")
{
    //ctor
}

MovingShape::~MovingShape()
{
    //dtor
}

bool blah = true;

void MovingShape::Update(int pDeltaTime)
{
    std::cout << pDeltaTime << std::endl;
    float v = Verts[0][1];
    //std::cout << v << "    ";
    if (blah)
    {
        v += (float)pDeltaTime / 1000.0;

    }
    else
    {
         v -= (float)pDeltaTime / 1000.0;
    }
  //  std::cout << v << std::endl;

    if (v >= 1.0 || v < -1.0)
    {
        blah = !blah;
        if (v > 0)
        {
            v =1;
        }
        else
        {

            v=-1;
        }
    }

    Verts[0][1] = v;
   // std::cout << Verts[1][1] << std::endl;
    //Gameobject::Update(pDeltaTime);
}
