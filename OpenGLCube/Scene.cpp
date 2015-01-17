//
//  Scene.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "Scene.h"
#include "CameraSystem.h"
#include "ResourceManager.h"
#include "PlayerInputSystem.h"

std::vector<Entity *>* Scene::getChildren(){
    return _children;
}
//!Scene Creator
/*!
 Creates and populates the scene.
 */
Scene::Scene(){
    _children = new std::vector<Entity *>();
    
    //!Create instance of resource manager
    /*!
     Creates a resource manager to deal with generation of the cubes
     */
    ResourceManager *resourceManager = &ResourceManager::getResourceManager();
    
    //!Create a cube Entity
    /*!
     Takes the paramaters :-
     \param X-Pos a float value for the x-position in the scene.
     \param Y-Pos a float value for the Y-position in the scene.
     \param Z-Pos a float value for the Z-position in the scene.
     */
    Entity *entity =new Entity(resourceManager->getVertexBufferArray()->at(1),
                               makeVector3(0.0f, 0.0f, 5.0f));
    
    _children->push_back(entity);
    
    Entity *cube2 =new Entity(resourceManager->getVertexBufferArray()->at(1),
                              makeVector3(1.5f, 0.0f, 5.0f));
    
    _children->push_back(cube2);
    
    Entity *cube3 =new Entity(resourceManager->getVertexBufferArray()->at(1),
                              makeVector3(3.0f, 0.0f, 5.0f));
    
    _children->push_back(cube3);
    
    Entity *cube4 =new Entity(resourceManager->getVertexBufferArray()->at(1),
                              makeVector3(4.5f, 0.0f, 5.0f));
    
    _children->push_back(cube4);
    
    //!Create a camera for the scene
    /*!
     Generates a camera for the scene at world space origin.
    */
    Entity *camera = new Entity(NULL, makeVector3(0.0f, 0.0f, 0.0f));
    camera->setEyeVector(normalizeVector3(makeVector3(0.0f, 0.0f, 1.0f)));
    
    //!Setup Player input
    /*!
     Applys player input system controls, onto the camera.
     */
    PlayerInputSystem *playerInputSystem = &PlayerInputSystem::getPlayerInputSystem();
    playerInputSystem->setCurrentPlayer(camera);
    
    _children->push_back(camera);
    
    CameraSystem *cameraSystem = &CameraSystem::getCameraSystem();
    cameraSystem->setCurrentCamera(camera);
}

//!Scene Destructor
/*!
 Destructs the scene by deleting each item/child created, freeing them from memory.
 */
Scene::~Scene(){
    for (std::vector<Entity *>::iterator iterator = _children->begin(); iterator != _children->end(); iterator++) {
        delete *iterator;
    }
    
    delete _children;
}