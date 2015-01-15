//
//  GameManager.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__GameManager__
#define __OpenGLCube__GameManager__

#include <iostream>
#include <GLFW/glfw3.h>
#include "RenderSystem.h"
#include "ResourceManager.h"
#include "MovementSystem.h"
#include "CameraSystem.h"
#include "PlayerInputSystem.h"
#include "Entity.h"
#include "Scene.h"

class GameManager{
private:
    
    bool _running;
    RenderSystem *_renderSystem;
    ResourceManager *_resourceManager;
    MovementSystem *_movementSystem;
    CameraSystem *_cameraSystem;
    PlayerInputSystem *_playerInputSystem;
    GLFWwindow *_window;
    
    Scene *scene;
    
    GameManager(bool running);
    ~GameManager();
    
public:
    
    void runGameLoop();
    
    static GameManager& getGameManager();
    static void destroyGameManager();
    
};

#endif /* defined(__OpenGLCube__GameManager__) */
