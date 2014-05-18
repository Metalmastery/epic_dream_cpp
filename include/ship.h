#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "headers.h"
#include "Pilot.h"

using namespace irr;
using namespace core;

class Ship
{
    public:
        Ship();
        Ship(Pilot* pilot, vector3df pos, float angle);
        ~Ship();

        float getRotationAngle();
        float getRotationAngleInDegrees();
        void rotateWithDiff(float diff);

        void accelerate();
        void update(float time = 1.0);

        void rotateLeft();
        void rotateRight();
        void rotateToPoint(vector3df pos);
        void rotateToAngle(float angle);

        void setPosition(const vector3df& pos);
        vector3df getPosition();

//        void rotateInertial(float time);
//        void useEngine(float time);
    protected:

    private:
        float rotationAngle;
        float rotationSpeed;
        float rotationAcceleration;
        vector3df position;
        vector3df velocity;
        float acceleration;
        void init (Pilot* pilot, const vector3df& pos = vector3df(), float angle = 0.0);

        Pilot * pilot;
};


#endif // SHIP_H_INCLUDED
