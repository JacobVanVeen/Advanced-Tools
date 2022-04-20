#include "TraditionalCollisionDetection.h"

TraditionalCollisionDetection::TraditionalCollisionDetection()
{
        startTime = SDL_GetTicks();
}

TraditionalCollisionDetection::~TraditionalCollisionDetection()
{
    //dtor
}


void TraditionalCollisionDetection::collisionChecked(bool pIscolliding)
{
    currentMeasurementCollisionsChecked++;
    if (pIscolliding)
    {
        currentMeasurementCollisions++;
    }
}

void TraditionalCollisionDetection::EndMeasurement()
{
    uint16_t timeTaken = SDL_GetTicks() - startTimeMeasurement;
    timeStamp = timeStamp + timeTaken;
    timestamps.push_back(timeStamp);
    timeMeasurements.push_back(timeTaken);
    collisionsChecked.push_back(currentMeasurementCollisionsChecked);
    //std::cout<< currentMeasurementCollisionsChecked << std::endl;
    collisionsFound.push_back(currentMeasurementCollisions);
    currentMeasurementCollisionsChecked=0;
    currentMeasurementCollisions=0;
}

void TraditionalCollisionDetection::CheckCollisions(std::vector<Colider*>* pColiders)
{
    startTimeMeasurement = SDL_GetTicks();
    std::vector<Colider*>* coliders = pColiders;
    coliderCount.push_back(coliders->size());
    for (int i=0;i< coliders->size();i++)
    {

        for (int j=i+1;j<coliders->size();j++)
        {
        int index =0; //used to get the index of a collision that already happend.
        Gameobject* gameObjectA = coliders->at(i)->GetOwner();
        Gameobject* gameObjectB = coliders->at(j)->GetOwner();
        if (coliders->at(i)->IsColiding(coliders->at(j)))
        {
            collisionChecked(true);
        //check if it was already colliding:
        if (WasColliding(gameObjectA,gameObjectB,&index))
        {
            //Fire OncollisionStay
           // std::cout << "On Collision Stay!" << std::endl;
           gameObjectA->OnCollisionStay(gameObjectB);
           gameObjectB->OnCollisionStay(gameObjectA);
     //      std::cout << i << "---" << j << " still coliding" << std::endl;
        }
        else
        {
     //   std::cout << "New collison!" << std::endl;
        gameObjectA->OnCollision(gameObjectB);
        gameObjectB->OnCollision(gameObjectA);
        //add to the collision list;
        Collision newCol;
        newCol.gameobjectA = gameObjectA;
        newCol.gameobjectB = gameObjectB;
        collisions.push_back(newCol);
        //std::cout << "On Collision Enter!" << std::endl;
     //       std::cout << i << "---" << j << " are now coliding" << std::endl;
        }


        }
        else
        {
   //         mTool->CollisionChecked(false);
            collisionChecked(false);
        //check if they were colliding and if so fire the OncollisionExit
        if (WasColliding(gameObjectA,gameObjectB,&index))
        {
           // std::cout << "On Collision Exit!!" << std::endl;
           gameObjectA->OnCollisionExit(gameObjectB);
           gameObjectB->OnCollisionExit(gameObjectA);
            //remove from list:
          //  std::cout << "Deleting collison" << std::endl;
            collisions.erase(collisions.begin() + index);
      //       std::cout << i << "---" << j << " are not coliding anymore" << std::endl;
        }
        else
        {
         //    std::cout << i << "---" << j << " are not coliding" << std::endl;
        }

        }

        }
    }
    EndMeasurement();


}



void TraditionalCollisionDetection::WriteReport()
{
        endTime = SDL_GetTicks() - startTime;
    uint32_t total;
    for (int i=0;i< timeMeasurements.size();i++)
    {
        total += timeMeasurements[i];
    }

    float averageTime = (float)total / (float)timeMeasurements.size();

    std::ofstream resultFile;
    resultFile.open("TraditionalCollisionDetectionResult.csv");
    resultFile << "Runtime (ms):," << std::to_string(endTime) << std::endl;
    resultFile << "Average checktime (ms):," << std::to_string(averageTime) << std::endl;
    resultFile << std::endl << "Time per collision check(ms)," << "TimeStamp,"<< "Collisions Checked," << "Collisions found" << std::endl;
    for (int i=0;i< timeMeasurements.size();i++)
    {
        resultFile << std::to_string(timeMeasurements.at(i)) << "," << std::to_string(timestamps.at(i)) << "," << std::to_string(collisionsChecked.at(i)) << "," << std::to_string(collisionsFound.at(i)) <<  std::endl;
    }

    resultFile.close();
}


