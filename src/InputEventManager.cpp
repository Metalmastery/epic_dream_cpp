#include "InputEventManager.h"
namespace keys {
    enum {
        up = 87,
        down = 83,
        left = 65,
        right = 68
    };
}

InputEventManager::InputEventManager()
{
    //ctor
    for (u32 i = 0; i < KEY_KEY_CODES_COUNT; i++){
        KeyIsDown[i] = false;
    }
}

InputEventManager::~InputEventManager()
{
    //dtor
}

bool InputEventManager::OnEvent(const SEvent &event){
    if (event.EventType == irr::EET_KEY_INPUT_EVENT){
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }
//    cout << keys::up << ' ' << event.KeyInput.Key << endl;
    return false;
}

bool InputEventManager::IsKeyDown(EKEY_CODE keyCode){
    return KeyIsDown[keyCode];
}
