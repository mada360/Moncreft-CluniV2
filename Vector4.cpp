//
//  Vector4.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "Vector4.h"

Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w){
    Vector4 newVector;
    newVector.x = x;
    newVector.y = y;
    newVector.z = z;
    newVector.w = w;
    
    return newVector;
}
