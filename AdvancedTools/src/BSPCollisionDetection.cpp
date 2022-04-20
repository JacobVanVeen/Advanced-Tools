#include "BSPCollisionDetection.h"

BSPCollisionDetection::BSPCollisionDetection(int pCubeSize,int pSubDivisions)
{
    cubeSize = pCubeSize;
    Subdivisions = pSubDivisions;

    // create cells
    float startpoint = (float)cubeSize /2.0;
    float step = (float)cubeSize / (float)Subdivisions;
    std::cout << "step: " << step << std::endl;

    for(int x=0;x<Subdivisions;x++)
    {
        for (int y=0;y<Subdivisions;y++)
        {
            for(int z=0;z<Subdivisions;z++)
            {
                BspCell* cell = new BspCell();
                float xp = (startpoint - (step*x)) - step/2.0;
                float yp = (startpoint - (step*y)) - step/2.0;
                float zp = (startpoint - (step*z)) - step/2.0;
                cell->SetPos(glm::vec3(xp,yp,zp));
                BoxColider* box = new BoxColider(cell);
                box->Scale = glm::vec3(step/2,step/2,step/2);
                BspCells.push_back(cell);
            }
        }
    }

    startTime = SDL_GetTicks();

}

BSPCollisionDetection::~BSPCollisionDetection()
{
    //dtor
}


void BSPCollisionDetection::collisionChecked(bool pIscolliding)
{
    currentMeasurementCollisionsChecked++;
    if (pIscolliding)
    {
        currentMeasurementCollisions++;
    }
}

/*
void BSPCollisionDetection::AddColidersToBsp(std::vector<Colider*>* pColiders)
{
    for (int i=0;i< BspCells.size();i++)
    {
        Colider* BspColider = BspCells.at(i);
        for (int j=0;j<pColiders->size();j++)
        {
            Colider* subjectColider = pColiders->at(j);
            if (BspColider->IsColiding(subjectColider))
            {
                BspColider->GetOwner->OnCollision(subjectColider->GetOwner());
                Collision col = {BspColider->GetOwner(),subjectColider->GetOwner()};
                collisions.push_back(col);
            }
        }
    }
}
*/

void BSPCollisionDetection::CheckCollisions(std::vector<Colider*>* pColiders)
{
    startTimeMeasurement = SDL_GetTicks();
//for now check all bspcells agains all coliders.
    for (int i=0;i<BspCells.size();i++)
    {
        Colider* BspColider = BspCells.at(i)->GetColider();
        for (int j=0;j<pColiders->size();j++)
        {
            int index=0;
            Colider* subjectColider = pColiders->at(j);
            if (BspColider->IsColiding(subjectColider))
            {
                collisionChecked(true);
                if (BspCells.at(i)->IsColliding(subjectColider->GetOwner()) == false)
                {
                    BspCells.at(i)->OnCollision(subjectColider->GetOwner());
                }
            }
            else if (BspCells.at(i)->IsColliding(subjectColider->GetOwner()))
            {
                collisionChecked(false);
                BspCells.at(i)->OnCollisionExit(subjectColider->GetOwner());
               // collisions.erase(collisions.begin() + index);
            }
        }
         //   std::cout << pjj << " new collisions,  in cell: "  << i<< std::endl;
    }


    //now check the individual cells:
    for (int i=0;i<BspCells.size();i++)
    {
        BspCell* cell = BspCells.at(i);
        cell->CheckCollisions();
        currentMeasurementCollisionsChecked += cell->GetTradColDet()->GetLatestCollisionsChecked();
        currentMeasurementCollisions += cell->GetTradColDet()->GetLatestCollisionsFound();

    }
    EndMeasurement();

}


void BSPCollisionDetection::EndMeasurement()
    {
    uint16_t timeTaken = SDL_GetTicks() - startTimeMeasurement;
    timeStamp = timeStamp + timeTaken;
    timestamps.push_back(timeStamp);
    timeMeasurements.push_back(timeTaken);
    collisionsChecked.push_back(currentMeasurementCollisionsChecked);
    collisionsFound.push_back(currentMeasurementCollisions);
    currentMeasurementCollisionsChecked=0;
    currentMeasurementCollisions=0;
    }


void BSPCollisionDetection::WriteReport()
{
        endTime = SDL_GetTicks() - startTime;
    uint32_t total;
    for (int i=0;i< timeMeasurements.size();i++)
    {
        total += timeMeasurements[i];
    }

    float averageTime = (float)total / (float)timeMeasurements.size();

    std::ofstream resultFile;
    resultFile.open("BSPCollisionDetectionResult.csv");
    resultFile << "Runtime (ms):," << std::to_string(endTime) << std::endl;
    resultFile << "Average checktime (ms):," << std::to_string(averageTime) << std::endl;
    resultFile << "Cubesize:," << std::to_string(cubeSize) << std::endl;
    resultFile << "Devisions:," << std::to_string(Subdivisions) << std::endl;
    resultFile << "Total cells:," << std::to_string(BspCells.size()) << std::endl;
    resultFile << std::endl << "Time per collision check(ms)," << "TimeStamp,"<< "Collisions Checked," << "Collisions" << std::endl;
    for (int i=0;i< timeMeasurements.size();i++)
    {
        resultFile << std::to_string(timeMeasurements.at(i)) << "," << std::to_string(timestamps.at(i)) <<","<< std::to_string(collisionsChecked.at(i)) << "," << std::to_string(collisionsFound.at(i)) <<  std::endl;
    }

    resultFile.close();
}
