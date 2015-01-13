//
//  CubeManager.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "CubeManager.h"
#include <iostream>


CubeManager::CubeManager(bool running): _running(running), _window(glfwGetCurrentContext()), _renderSystem(&RenderSystem::getRenderSystem()){
    
}

CubeManager::~CubeManager(){
    RenderSystem::destroyRenderSystem();
}

void CubeManager::runGameLoop(){
    while(_running){
        
        //When game not running, set running to false.
        _running = !glfwWindowShouldClose(_window);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        _renderSystem->render();
        
  
    }
}

CubeManager& CubeManager::getCubeManager(){
    static CubeManager *cubeManager = NULL;
    
    if(cubeManager == NULL){
        
        glfwInit();
        
        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_RED_BITS,    8);
        glfwWindowHint(GLFW_BLUE_BITS,   8);
        glfwWindowHint(GLFW_GREEN_BITS,  8);
        glfwWindowHint(GLFW_ALPHA_BITS,  8);
        
        GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Cube", NULL, NULL);
        glfwMakeContextCurrent(window);
        
        cubeManager = new CubeManager(true);
        std::cout << "Cube manager made" << std::endl;
    }
    return *cubeManager;
}

void CubeManager::destroyCubeManager(){
    CubeManager *cubeManager = &getCubeManager();
    delete cubeManager;
    
        std::cout << "Cube manager destroyed" << std::endl;
    
    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    
    glfwTerminate();
    
}


