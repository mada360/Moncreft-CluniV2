//
//  Matrix3.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__Matrix3__
#define __OpenGLCube__Matrix3__

#include <iostream>
#include <GLFW/glfw3.h>

typedef struct
{
    GLfloat m00;
    GLfloat m01;
    GLfloat m02;
    GLfloat m10;
    GLfloat m11;
    GLfloat m12;
    GLfloat m20;
    GLfloat m21;
    GLfloat m22;
    
} Matrix3;

Matrix3 scalerMultiplyMatrix3(Matrix3 matrix, GLfloat scalerValue);
Matrix3 addMatrix3(Matrix3 matrixA, Matrix3 matrixB);
Matrix3 makeRotationMatrix3(GLfloat angle, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis);

const Matrix3 identityMatrix3 = {  1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 1.0f};

#endif /* defined(__OpenGLCube__Matrix3__) */
