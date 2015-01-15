//
//  VertexData.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#ifndef OpenGLCube_VertexData_h
#define OpenGLCube_VertexData_h

#include "Vector3.h"

typedef struct {
    
    Vector3 positionCoordinates;
    
} VertexDataP;

typedef struct {
    
    Vector3 positionCoordinates;
    Vector3 normalCoordinates;
    
} VertexDataPN;

#endif
