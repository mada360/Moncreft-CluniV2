//
//  CubeManager.h
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__CubeManager__
#define __OpenGLCube__CubeManager__

#include <iostream>
#include <GLFW/glfw3.h>
#include "RenderSystem.h"
#include "ResourceManager.h"
#include "MovementSystem.h"
#include "CameraSystem.h"
#include "PlayerInputSystem.h"
#include "Entity.h"
#include "Scene.h"

class CubeManager{
private:
    
    bool _running;
    RenderSystem *_renderSystem;
    ResourceManager *_resourceManager;
    MovementSystem *_movementSystem;
    CameraSystem *_cameraSystem;
    PlayerInputSystem *_playerInputSystem;
    GLFWwindow *_window;
    
    Scene *scene;
    
    CubeManager(bool running);
    ~CubeManager();
    
public:
    
    void runCubeLoop();
    
    static CubeManager& getCubeManager();
    static void destroyCubeManager();
    
};


#endif /* defined(__OpenGLCube__CubeManager__) */
