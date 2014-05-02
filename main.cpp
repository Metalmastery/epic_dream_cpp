#include "headers.h"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
    InputEventManager imgr;

    IrrlichtDevice *device = createDevice( video::EDT_OPENGL, core::dimension2d<u32>(800, 600), 16, false, false, false, &imgr);

    if (!device)
        return 1;

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

//    guienv->addStaticText(L"Hello World 2", core::recti(10, 10, 100, 30));
    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

    Ship* ship = new Ship();

//    smgr->setAmbientLight(video::SColorf(0.3,0.3,0.3,1));
    ILightSceneNode* light1 = smgr->addLightSceneNode( 0, core::vector3df(25,30,-12), video::SColorf(0.3f,0.3f,0.3f), 150.0f, 1 );

//    ISceneNode* cube = smgr->addCubeSceneNode();
//    cube->setPosition(vector3df(0,5,0));
//
//    cube->setScale(vector3df(1,1,1));
//    cube->setMaterialFlag(EMF_LIGHTING, true);

    ICameraSceneNode * camera = smgr->addCameraSceneNode(0, vector3df(0,0,-200), vector3df(0,5,0));

    core::stringw str;
    u32 frames = 0;

    BasicNode *myNode = new BasicNode(smgr->getRootSceneNode(), smgr, 23);

    while(device->run()) {

        if(++frames == 100)
        {
            str = L"Irrlicht Engine [";
            str += driver->getName();
            str += L"] FPS: ";
            str += (s32)driver->getFPS();

            device->setWindowCaption(str.c_str());
            frames=0;

            if (imgr.IsKeyDown(irr::EKEY_CODE(KEY_KEY_W))){
                ship->accelerate();
            }
            if (imgr.IsKeyDown(irr::EKEY_CODE(KEY_KEY_S))){
                ship->setPosition(vector3df(0,0,0));
            }
            if (imgr.IsKeyDown(irr::EKEY_CODE(KEY_KEY_A))){
                ship->rotateWithDiff(0.001);
            }
            if (imgr.IsKeyDown(irr::EKEY_CODE(KEY_KEY_D))){
                ship->rotateWithDiff(-0.001);
            }
            core::position2d <s32> pos = device->getCursorControl()->getPosition();
            pos -= vector2d <s32>(400, 300);
            ship->setRotationAngle(pos.getAngle() / 180.0 * PI);
            ship->updatePosition();

//    1        myNode->setRotation(vector3df(0,0,ship->getRotationAngleInDegrees()));
            myNode->setRotation(vector3df(0,0,pos.getAngle()));
            myNode->setPosition(ship->getPosition());

            driver->beginScene(true, true, SColor(255, 150, 150, 150));
            smgr->drawAll();
    //        guienv->drawAll();
            driver->endScene();
        }
    }

    device->drop();
    return 0;
}
