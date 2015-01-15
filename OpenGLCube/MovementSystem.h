//
//  MovementSystem.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__MovementSystem__
#define __OpenGLCube__MovementSystem__

#include <iostream>
#include "Vector3.h"
#include <GLFW/glfw3.h>
#include "Entity.h"

class MovementSystem
{
private:
    
    MovementSystem();
    ~MovementSystem();
    
public:
    
    void update(std::vector<Entity *> *entityArray);
    
    static MovementSystem& getMovementSystem();
    static void destroyMovementSystem();
};


#endif /* defined(__OpenGLCube__MovementSystem__) */
