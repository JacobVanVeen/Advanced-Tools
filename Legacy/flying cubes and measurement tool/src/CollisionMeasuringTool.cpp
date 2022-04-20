#include "CollisionMeasuringTool.h"



CollisionMeasuringTool::CollisionMeasuringTool()
{
    startTime = SDL_GetTicks();
}

CollisionMeasuringTool::~CollisionMeasuringTool()
{
    //dtor
}

void CollisionMeasuringTool::AddColider()
{
    coliderCout++;
}

void CollisionMeasuringTool::StartMeasurement()
{
    startTimeMeasurement = SDL_GetTicks();
}

void CollisionMeasuringTool::EndMeasurement()
{
    timeMeasurements.push_back(SDL_GetTicks() - startTimeMeasurement);
    collisionsChecked.push_back(currentMeasurementCollisionsChecked);
    Collisions.push_back(currentMeasurementCollisions);
    currentMeasurementCollisionsChecked=0;
    currentMeasurementCollisions=0;
}

void CollisionMeasuringTool::CollisionChecked(bool IsColiding)
{
    currentMeasurementCollisionsChecked++;
    if (IsColiding)
    {
        currentMeasurementCollisions++;
    }
}

void CollisionMeasuringTool::WriteResults()
{

    endTime = SDL_GetTicks() - startTime;
    uint32_t total;
    for (int i=0;i< timeMeasurements.size();i++)
    {
        total += timeMeasurements[i];
    }

    float averageTime = (float)total / (float)timeMeasurements.size();

    std::ofstream resultFile;
    resultFile.open("test.csv");
    resultFile << "Runtime (ms):," << std::to_string(endTime) << std::endl;
    resultFile << "Average checktime (ms):," << std::to_string(averageTime) << std::endl;
    resultFile << std::endl << "Time per collision check(ms)," << "Collisions Checked," << "Collisions" << std::endl;
    for (int i=0;i< timeMeasurements.size();i++)
    {
        resultFile << std::to_string(timeMeasurements.at(i)) << "," << std::to_string(collisionsChecked.at(i)) << "," << std::to_string(Collisions.at(i)) <<  std::endl;
    }

    resultFile.close();


}
