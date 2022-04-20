#include "RandomNumber.h"
#include <cstdlib>
#include <ctime>

RandomNumber* RandomNumber::instance; //Not sure why I need to put this here.. Can't it get the ref from the Header file?


RandomNumber::RandomNumber()
{
    srand((unsigned int) time(NULL));
}

RandomNumber::~RandomNumber()
{
    //dtor
}

float RandomNumber::GetRandom()
{
    return GetRandom(RAND_MAX);
}

float RandomNumber::GetRandom(float pMax)
{
    if (instance == nullptr)
    {
        instance = new RandomNumber();
    }
    return (float(rand())/float((RAND_MAX)) * pMax ) ;
}

float RandomNumber::GetRandom(float pMin, float pMax)
{
    if (instance == nullptr)
    {
        instance = new RandomNumber();
    }
    float maxx = pMax + std::abs(pMin);
    return (float(rand())/float((RAND_MAX)) * maxx ) - std::abs(pMin) ;
}
