//
//  Scene.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__Scene__
#define __OpenGLCube__Scene__

#include <iostream>
#include "Entity.h"
#include <vector>

class Scene{
private:
    
    std::vector<Entity *> *_children;
    
public:
    
    std::vector<Entity *>* getChildren();
    
    Scene();
    ~Scene();
    
};

#endif /* defined(__OpenGLCube__Scene__) */
