//
//  CubeManager.h
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__CubeManager__
#define __OpenGLCube__CubeManager__

#include <stdio.h>
#include "/Users/mada360/Downloads/glfw-3.0.4/include/GLFW/glfw3.h"
#include "RenderSystem.h"

class CubeManager{
    
    bool _running;
    RenderSystem *_renderSystem;
    GLFWwindow *_window;
    
private:
    CubeManager(bool running);
    ~CubeManager();
    
public:
    void runGameLoop();
    
    static CubeManager& getCubeManager();
    static void destroyCubeManager();
};


#endif /* defined(__OpenGLCube__CubeManager__) */
