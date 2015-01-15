//
//  CameraSystem.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__CameraSystem__
#define __OpenGLCube__CameraSystem__

#include <iostream>
#include "Entity.h"

class CameraSystem {
private:
    
    Entity *_currentCamera;
    
    CameraSystem();
    ~CameraSystem();
    
public:
    
    Entity *getCurrentCamera();
    void setCurrentCamera(Entity *newCamera);
    
    static CameraSystem& getCameraSystem();
    static  void destroyCameraSystem();
};


#endif /* defined(__OpenGLCube__CameraSystem__) */
