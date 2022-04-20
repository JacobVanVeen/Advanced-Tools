#ifndef BSPCELL_H
#define BSPCELL_H
#include "Gameobject.h"
#include <string>
#include "TraditionalCollisionDetection.h"
#include <algorithm>

class BspCell : public Gameobject
{
    public:
        BspCell(std::string pName);
        BspCell();
        virtual ~BspCell();
        void OnCollision(Gameobject* Other) override;
        void OnCollisionExit(Gameobject* Other) override;
        void CheckCollisions();
        bool IsColliding(Gameobject* pObject);
        TraditionalCollisionDetection* GetTradColDet();
    protected:

    private:
        std::vector<Colider*> inhabitans;
        TraditionalCollisionDetection* TradColDect;
};

#endif // BSPCELL_H
