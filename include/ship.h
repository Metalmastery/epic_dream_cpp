#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "irrlicht.h"
using namespace irr;
using namespace core;

class Ship
{
    public:
        Ship();
//        Ship(int posX, posY);
        ~Ship();

        void setRotationAngle(float angle);
        float getRotationAngle();
        float getRotationAngleInDegrees();
        void rotateWithDiff(float diff);
        void accelerate();
        void updatePosition();
        void setPosition(const vector3df& pos);
        vector3df getPosition();

//        void rotateInertial(float time);
//        void useEngine(float time);
    protected:

    private:
        float positionX;
        float positionY;
        float velocityX;
        float velocityY;
        float rotationAngle;
        vector3df position;
        vector3df velocity;

};


#endif // SHIP_H_INCLUDED
