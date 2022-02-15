#ifndef MOVINGSHAPE_H
#define MOVINGSHAPE_H
#include "Gameobject.h"

class MovingShape : public Gameobject
{
    public:
        MovingShape();
        virtual ~MovingShape();
        void Update(int pDetalTime) override;
    protected:

    private:
};

#endif // MOVINGSHAPE_H
