#ifndef BSPCOLLISIONDETECTION_H
#define BSPCOLLISIONDETECTION_H

#include "AbstractCollisionDetection.h"
#include "BoxColider.h"
#include "BspCell.h"
class BSPCollisionDetection : public AbstractCollisionDetection
{
    public:
        BSPCollisionDetection(int pCubeSize,int pSubDivisions);
        virtual ~BSPCollisionDetection();
        void CheckCollisions(std::vector<Colider*>* pColiders) override;
        std::vector<BspCell*> BspCells;
        void WriteReport() override;
    protected:

    private:
        void collisionChecked(bool pIscolliding);
        int cubeSize;
        int Subdivisions;
        void EndMeasurement();
};

#endif // BSPCOLLISIONDETECTION_H
