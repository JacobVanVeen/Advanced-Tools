#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H


class RandomNumber
{
    public:
    static float GetRandom();
    static float GetRandom(float pMax);
    static float GetRandom(float pMin, float pMax);

    protected:

    private:
        static RandomNumber* instance;
        RandomNumber();
        virtual ~RandomNumber();
};

#endif // RANDOMNUMBER_H
