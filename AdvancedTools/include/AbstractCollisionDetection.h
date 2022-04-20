#ifndef ABSTRACTCOLLISIONDETECTION_H
#define ABSTRACTCOLLISIONDETECTION_H
#include <vector>;
#include "Colider.h";

struct Collision
{
    Gameobject* gameobjectA;
    Gameobject* gameobjectB;
};

class AbstractCollisionDetection
{
    public:
        AbstractCollisionDetection();
        virtual ~AbstractCollisionDetection();
        virtual void CheckCollisions(std::vector<Colider*>* pColiders);
        virtual void WriteReport();
        uint16_t GetLatestCollisionsChecked();
        uint16_t GetLatestCollisionsFound();
    protected:
        bool WasColliding(Gameobject* gameObjectA,Gameobject* GameobjectB,int* indexOutput);
        std::vector<Collision> collisions;

        std::vector<uint32_t> timeMeasurements;
        std::vector<uint16_t> collisionsChecked;
        std::vector<uint16_t> collisionsFound;
        std::vector<uint16_t> coliderCount;
        std::vector<uint16_t> timestamps;
        uint32_t startTimeMeasurement=0;
        uint32_t startTime=0;
        uint32_t endTime=0;
        uint16_t currentMeasurementCollisionsChecked=0;
        uint16_t currentMeasurementCollisions=0;
        uint16_t timeStamp=0;

    private:

};

#endif // ABSTRACTCOLLISIONDETECTION_H
