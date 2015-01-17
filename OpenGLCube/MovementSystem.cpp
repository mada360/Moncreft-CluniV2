//
//  MovementSystem.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "MovementSystem.h"

MovementSystem::MovementSystem(){
    
}

MovementSystem::~MovementSystem(){
    
}

//!Movement class
/*!
 Uses the transforms returned by the entity to perform player movement.
 */
void MovementSystem::update(std::vector<Entity *> *entityArray){
    for (std::vector<Entity *>::iterator iterator = entityArray->begin(); iterator != entityArray->end(); iterator++) {
        
        Entity *entity = *iterator;
        
        entity->setPosition(addVector3(entity->getPosition(), entity->getVelocity()));
        entity->setScale(addVector3(entity->getScale(), entity->getScaleVelocity()));
        entity->setRotation(addVector3(entity->getRotation(), entity->getRotationVelocity()));
        
    }
}

//!getMovementSystem
/*!
 If there is no movement system, one will be created and returned.
 */
MovementSystem& MovementSystem::getMovementSystem(){
    static MovementSystem* movementSystem = NULL;
    
    if (movementSystem == NULL) {
        movementSystem = new MovementSystem();
    }
    
    return *movementSystem;
}

//!destroyMovementSystem
/*!
 Gets the movement system and then deletes it and frees up memory.
 */
void MovementSystem::destroyMovementSystem(){
    MovementSystem *movementSystem = &getMovementSystem();
    delete movementSystem;
}