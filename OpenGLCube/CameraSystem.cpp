//
//  CameraSystem.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "CameraSystem.h"
#include "RenderSystem.h"

Entity* CameraSystem::getCurrentCamera(){
    return _currentCamera;
}

//!Create Camera entity
/*!
 Creates the camera entity to be added to the scene
 */
void CameraSystem::setCurrentCamera(Entity *newCamera){
    _currentCamera = newCamera;
    
    RenderSystem *renderSystem = &RenderSystem::getRenderSystem();
    renderSystem->setCurrentCamera(_currentCamera);
}

CameraSystem::CameraSystem(){
    
}

CameraSystem::~CameraSystem(){
    
}

CameraSystem& CameraSystem::getCameraSystem(){
    static CameraSystem *cameraSystem = NULL;
    
    if (cameraSystem == NULL) {
        
        cameraSystem = new CameraSystem();
    }
    
    return *cameraSystem;
}


//!Destruct Camera entity
/*!
 Gets the camera and deletes it.
 */
void CameraSystem::destroyCameraSystem(){
    CameraSystem *cameraSystem = &getCameraSystem();
    delete cameraSystem;
}