#ifndef COLLISIONMEASURINGTOOL_H
#define COLLISIONMEASURINGTOOL_H
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <string>

class CollisionMeasuringTool
{
    public:
        CollisionMeasuringTool();
        virtual ~CollisionMeasuringTool();
        void StartMeasurement();
        void EndMeasurement();
        void WriteResults();
        void CollisionChecked(bool isColiding);
        void AddColider();
    protected:

    private:
        std::vector<uint32_t> timeMeasurements;
        std::vector<uint16_t> collisionsChecked;
        std::vector<uint16_t> Collisions;
        uint32_t startTimeMeasurement=0;
        uint32_t startTime=0;
        uint32_t endTime=0;
        uint16_t currentMeasurementCollisionsChecked=0;
        uint16_t currentMeasurementCollisions=0;
        uint16_t coliderCout=0;

};

#endif // COLLISIONMEASURINGTOOL_H
