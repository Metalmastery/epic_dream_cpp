#include "headers.h"
#include "utils.h"
#include "ship.h"
#include "PlayerPilot.h"
#include "BasicNode.h"


#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

void addBasicSurface(ISceneManager * smgr, IVideoDriver* driver) {

   // Create a terrain scene node
   IAnimatedMesh *terrain_model = smgr->addHillPlaneMesh("starPlane", // Name of the scenenode
                           core::dimension2d<f32>(256.0f, 256.0f), // Tile size
                           core::dimension2d<u32>(8, 8), // Tile count
                           0, // Material
                           0.0f, // Hill height
                           core::dimension2d<f32>(0.0f, 0.0f), // countHills
                           core::dimension2d<f32>(8.0f, 8.0f)); // textureRepeatCount
    ISceneNode * terrain_node;
   terrain_node = smgr->addAnimatedMeshSceneNode(terrain_model);
   terrain_node->setMaterialTexture(0, driver->getTexture("starfield.png"));
   terrain_node->setMaterialFlag(EMF_LIGHTING, false);

   // Insert it into the scene
   terrain_node->setPosition(vector3df(0,0,10));
   terrain_node->setRotation(vector3df(-90,0,0));

}

int main()
{
    InputEventManager * imgr = getEventManager();


    IrrlichtDevice *device = getDevice();

    if (!device)
        return 1;

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();
    IGUIEnvironment* guienv = device->getGUIEnvironment();

//    guienv->addStaticText(L"Hello World 2", core::recti(10, 10, 100, 30));
    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");

    Ship* ship = new Ship(new PlayerPilot(), vector3df(50,50,0),0.0);

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

    addBasicSurface(smgr, driver);

    while(device->run()) {
        // camera follows player
        vector3df pos = ship->getPosition();
        camera->setTarget(pos);
        pos.Z = -500;
        camera->setPosition(pos);
        //

        if(++frames == 100)
        {
            str = L"Irrlicht Engine [";
            str += driver->getName();
            str += L"] FPS: ";
            str += (s32)driver->getFPS();

            device->setWindowCaption(str.c_str());
            frames=0;

            ship->update(0.01);

//    1        myNode->setRotation(vector3df(0,0,ship->getRotationAngleInDegrees()));
            myNode->setRotation(vector3df(0,0,ship->getRotationAngleInDegrees()));
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
