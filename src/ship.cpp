#include "ship.h";

Ship::Ship(){
    this->rotationAngle = 0.0;
    this->position = vector3df(0,0,0);
    this->velocity = vector3df(0,0,0);
};

void Ship::rotateWithDiff(float diff){
    this->rotationAngle += diff;
};

float Ship::getRotationAngle(){
    return this->rotationAngle;
};

void Ship::setRotationAngle(float angle){
    this->rotationAngle = angle;
};

float Ship::getRotationAngleInDegrees(){
    return this->rotationAngle * 180 / PI;
};

void Ship::accelerate(){
    this->velocity.X += cos(this->rotationAngle) * 0.0001;
    this->velocity.Y += sin(this->rotationAngle) * 0.0001;
};

void Ship::updatePosition(){
    this->position += this->velocity;
};

void Ship::setPosition(const vector3df& pos){
    this->position = pos;
};

vector3df Ship::getPosition(){
    return this->position;
}
