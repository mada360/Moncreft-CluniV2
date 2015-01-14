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
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "VertexBuffer.h"
#include <vector>
#include "ShaderInterface.h"

class RenderSystem{
private:
    
    GLFWwindow *_window;
    
    std::vector<ShaderInterface *> *shaderArray;
    
    RenderSystem();
    ~RenderSystem();
    
public:
    
    void render(VertexBuffer *vertexBuffer);
    
    static RenderSystem& getRenderSystem();
    static void destroyRenderSystem();
};

#endif /* defined(__OpenGLCube__RenderSystem__) */
