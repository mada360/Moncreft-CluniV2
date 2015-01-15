//
//  RenderSystem.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__RenderSystem__
#define __OpenGLCube__RenderSystem__

#include <iostream>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "VertexBuffer.h"
#include <vector>
#include "ShaderInterface.h"
#include "Entity.h"
#include "CameraSystem.h"

class RenderSystem{
private:
    
    GLFWwindow *_window;
    
    CameraSystem *_cameraSystem;
    Entity *_currentCamera;
    
    RenderSystem();
    ~RenderSystem();
    
public:
    
    Entity *getCurrentCamera();
    void setCurrentCamera(Entity *newCamera);
    
    void render(std::vector<Entity *> *entityArray);
    
    static RenderSystem& getRenderSystem();
    static void destroyRenderSystem();
    
};

#endif /* defined(__OpenGLCube__RenderSystem__) */
