//
//  RenderSystem.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "RenderSystem.h"

RenderSystem::RenderSystem(): _window(glfwGetCurrentContext()){
    
}

RenderSystem::~RenderSystem(){
    
}

void RenderSystem::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

RenderSystem& RenderSystem::getRenderSystem(){
    
    static RenderSystem *renderSystem = NULL;
    
    if (renderSystem == NULL){
        renderSystem = new RenderSystem();
        
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }
    
    return *renderSystem;
}

void RenderSystem::destroyRenderSystem(){
    RenderSystem *renderSystem = &getRenderSystem();
    delete renderSystem;
}