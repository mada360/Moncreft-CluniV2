//
//  Vector3.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__Vector3__
#define __OpenGLCube__Vector3__

#include <iostream>
#include <GLFW/glfw3.h>
#include "Matrix3.h"

typedef struct {
    
    GLfloat x;
    GLfloat y;
    GLfloat z;
    
} Vector3;

Vector3 makeVector3(GLfloat x, GLfloat y, GLfloat z);
Vector3 addVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 subtractVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 normalizeVector3(Vector3 vector);
Vector3 scalerMultiplyVector3(Vector3 vectorToMultiply, GLfloat scalerValue);
Vector3 crossProductVector3(Vector3 vectorA, Vector3 vectorB);
GLfloat dotProductVector3(Vector3 vectorA, Vector3 vectorB);
Vector3 transformVector3(Vector3 vector, Matrix3 transformationMatrix);

#endif /* defined(__OpenGLCube__Vector3__) */
