//
//  Vector4.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__Vector4__
#define __OpenGLCube__Vector4__

#include <stdio.h>
#include <GLFW/glfw3.h>

typedef struct{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
    
} Vector4;

Vector4 makeVector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);


#endif /* defined(__OpenGLCube__Vector4__) */
