//
//  RenderSystem.h
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__RenderSystem__
#define __OpenGLCube__RenderSystem__

#include <stdio.h>
#include <GLFW/glfw3.h>

class RenderSystem{
private:
    
    GLFWwindow *_window;
    
    RenderSystem();
    ~RenderSystem();
    
public:
    
    void render();
    
    static RenderSystem& getRenderSystem();
    static void destroyRenderSystem();
};

#endif /* defined(__OpenGLCube__RenderSystem__) */
