//
//  CubeManager.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "CubeManager.h"
#include <iostream>

CubeManager::CubeManager(bool running):
_running(running), _window(glfwGetCurrentContext()),
_renderSystem(&RenderSystem::getRenderSystem()),
_resourceManager(&ResourceManager::getResourceManager()),
_movementSystem(&MovementSystem::getMovementSystem()),
_cameraSystem(&CameraSystem::getCameraSystem()), scene(new Scene), _playerInputSystem(&PlayerInputSystem::getPlayerInputSystem())
{
}

CubeManager::~CubeManager(){
    ResourceManager::destroyResourceManager();
    CameraSystem::destroyCameraSystem();
    RenderSystem::destroyRenderSystem();
    PlayerInputSystem::destroyPlayerInputSystem();
}

#define Updates_Per_Second 60.0f

void CubeManager::runCubeLoop(){
    double lastTime = glfwGetTime();
    double deltaTime = 0.0f;
    
    while (_running){
        
        double currentTime = glfwGetTime();
        deltaTime += (currentTime - lastTime) * Updates_Per_Second;
        lastTime = currentTime;
        
        while (deltaTime >= 1.0f) {
            
            _running = !glfwWindowShouldClose(_window);
            
            _movementSystem->update(scene->getChildren());
            _playerInputSystem->update();
            
            --deltaTime;
        }
        
        _renderSystem->render(scene->getChildren());
    }
}

CubeManager& CubeManager::getCubeManager(){
    static CubeManager *cubeManager = NULL;
    
    if (cubeManager == NULL) {
        
        glfwInit();
        
        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        glfwWindowHint(GLFW_SAMPLES, 16);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        GLFWwindow *window = glfwCreateWindow(1280, 720, "Cube World", NULL, NULL);
        glfwMakeContextCurrent(window);
        
        cubeManager = new CubeManager(true);
        
        std::cout << "cubeManager created" << std::endl;
    }
    
    return *cubeManager;
}

void CubeManager::destroyCubeManager(){
    CubeManager *cubeManager = &getCubeManager();
    delete cubeManager;
    
    std::cout << "CubeManager destroyed" << std::endl;
    
    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    
    glfwTerminate();
    
}