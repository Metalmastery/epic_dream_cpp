#ifndef BASICNODE_H
#define BASICNODE_H

#include "irrlicht.h"
using namespace irr;

class BasicNode : public scene::ISceneNode
{
    public:
        BasicNode(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id);
        ~BasicNode();

        virtual void OnRegisterSceneNode();
        virtual void render();

        virtual const core::aabbox3d<f32>& getBoundingBox() const;
        virtual u32 getMaterialCount() const;
        virtual video::SMaterial& getMaterial(u32 i);


    protected:
    private:
        core::aabbox3d<f32> Box;
        video::S3DVertex Vertices[4];
        video::SMaterial Material;


};

#endif // BASICNODE_H
