//
//  VertexData.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__VertexData__
#define __OpenGLCube__VertexData__

#include <stdio.h>
#include "Vector3.h"

typedef struct{
    
    Vector3 positionCoordinates;
    
} VertexDataP;

typedef struct{
    
    Vector3 positionCoordinates;
    Vector3 normalCoordinates;
    
} VertexDataPN;

#endif /* defined(__OpenGLCube__VertexData__) */
