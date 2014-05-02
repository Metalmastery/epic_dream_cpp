#include "BasicNode.h"

BasicNode::BasicNode(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id)
        : scene::ISceneNode(parent, mgr, id)
{
    Material.Wireframe = false;
    Material.Lighting = false;

    video::SColor color = video::SColor(255,255,255,255);

    Vertices[0] = video::S3DVertex(-10,-5,0, 1,1,0,
                color, 0, 1);
    Vertices[1] = video::S3DVertex(10,0,0, 1,0,0,
            color, 1, 1);
    Vertices[2] = video::S3DVertex(-10,5,0, 0,1,1,
            color, 1, 0);
    Vertices[3] = video::S3DVertex(-5,0,-3, 0,0,1,
            color, 0, 0);

    Box.reset(Vertices[0].Pos);

    for (s32 i=1; i<4; ++i)
        Box.addInternalPoint(Vertices[i].Pos);
};

void BasicNode::OnRegisterSceneNode()
{
    if (IsVisible)
        SceneManager->registerNodeForRendering(this);
    ISceneNode::OnRegisterSceneNode();
}

void BasicNode::render()
{
    u16 indices[] = { 1,0,3, 3,2,1 };
    video::IVideoDriver* driver = SceneManager->getVideoDriver();
    driver->setMaterial(Material);
    driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
    driver->drawVertexPrimitiveList(&Vertices[0], 4, &indices[0], 2, video::EVT_STANDARD, scene::EPT_TRIANGLES, video::EIT_16BIT);
}

const core::aabbox3d<f32>& BasicNode::getBoundingBox() const
{
    return Box;
}
u32 BasicNode::getMaterialCount() const
{
    return 1;
}

video::SMaterial& BasicNode::getMaterial(u32 i)
{
    return Material;
}

BasicNode::~BasicNode(){};
