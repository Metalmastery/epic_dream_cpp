#include "ship.h";
#include "PlayerPilot.h";

Ship::Ship(){
    this->init(new PlayerPilot());
};

Ship::Ship(Pilot* pilot, vector3df pos, float angle){
    this->init(pilot, pos, angle);
};

void Ship::init(Pilot* pilot, const vector3df& pos, float angle){
    this->rotationAngle = angle;
    this->rotationSpeed = 0.0;
    this->rotationAcceleration = 0.001;
    this->position = pos;
    this->acceleration = 0.01;
    this->velocity = vector3df(0,0,0);
    this->pilot = pilot;
};

void Ship::rotateWithDiff(float diff){
    this->rotationAngle += diff;
};

float Ship::getRotationAngle(){
    return this->rotationAngle;
};

void Ship::rotateLeft(){
    this->rotationSpeed += this->rotationAcceleration;
};

void Ship::rotateRight(){
    this->rotationSpeed -= this->rotationAcceleration;
};

void Ship::rotateToAngle(float angle){
    float c0 = 0.1 / 3.14;
    float c1 = 1.1 * sqrt(c0);
    float force = angle * c0 - this->rotationSpeed * c1;

    if (fabs(force) > 0.00001) {
        if (force > 0) {
            this->rotateLeft();
        } else {
            this->rotateRight();
        }
    }
}

float Ship::getRotationAngleInDegrees(){
    return this->rotationAngle * 180 / PI;
};

void Ship::accelerate(){
    this->velocity.X += cos(this->rotationAngle) * this->acceleration;
    this->velocity.Y += sin(this->rotationAngle) * this->acceleration;
};

void Ship::update(float time){
    this->pilot->update(*this);
    this->rotationAngle += this->rotationSpeed * time;
    this->position += this->velocity * time;
};

void Ship::setPosition(const vector3df& pos){
    this->position = pos;
};

vector3df Ship::getPosition(){
    return this->position;
}
