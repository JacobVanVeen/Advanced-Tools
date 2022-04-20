#ifndef TRADITIONALCOLLISIONDETECTION_H
#define TRADITIONALCOLLISIONDETECTION_H

#include "AbstractCollisionDetection.h"
#include "CollisionMeasuringTool.h"

class TraditionalCollisionDetection : public AbstractCollisionDetection
{
    public:
        TraditionalCollisionDetection();
        virtual ~TraditionalCollisionDetection();
        void CheckCollisions(std::vector<Colider*>* pColiders) override;
        void WriteReport() override;
    protected:

    private:
        bool measure;
        void collisionChecked(bool pIscolliding);
        void EndMeasurement();

        uint16_t coliderCout=0;
        std::vector<uint16_t> Collisions;
};

#endif // TRADITIONALCOLLISIONDETECTION_H
