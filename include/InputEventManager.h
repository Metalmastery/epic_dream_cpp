#ifndef INPUTEVENTMANAGER_H
#define INPUTEVENTMANAGER_H

#include "irrlicht.h"
#include <iostream>
using namespace irr;
using namespace std;

class InputEventManager : public IEventReceiver
{
    public:
        InputEventManager();
        ~InputEventManager();
        virtual bool OnEvent (const SEvent &event);
        virtual bool IsKeyDown(EKEY_CODE keyCode);
    protected:
    private:
        bool KeyIsDown [KEY_KEY_CODES_COUNT];
};

#endif // INPUTEVENTMANAGER_H
