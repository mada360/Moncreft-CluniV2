//
//  CubeVertices.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#ifndef OpenGLCube_CubeVertices_h
#define OpenGLCube_CubeVertices_h

#include "VertexData.h"

VertexDataPN cubeVertices[] = {
    0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f, //B
    0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f, //C
    0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f, //Bb
    0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f, //Bb
    0.5f, 0.5f, -0.5f,          1.0f, 0.0f, 0.0f,//C
    0.5f, 0.5f, 0.5f,         1.0f, 0.0f, 0.0f,  //Cc
    
    0.5f, 0.5f, -0.5f,         0.0f, 1.0f, 0.0f, //C
    -0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f, //D
    0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f, //Cc
    0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f, //Cc
    -0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f, //D
    -0.5f, 0.5f, 0.5f,         0.0f, 1.0f, 0.0f, //Dd
    
    -0.5f, 0.5f, -0.5f,        -1.0f, 0.0f, 0.0f, //D
    -0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f, //A
    -0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f, //Dd
    -0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f, //Dd
    -0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f, //A
    -0.5f, -0.5f, 0.5f,        -1.0f, 0.0f, 0.0f, //Aa
    
    -0.5f, -0.5f, -0.5f,       0.0f, -1.0f, 0.0f, //A
    0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f, //B
    -0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f, //Aa
    -0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f, //Aa
    0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f, //B
    0.5f, -0.5f, 0.5f,         0.0f, -1.0f, 0.0f, //Bb
    
    0.5f, 0.5f, 0.5f,          0.0f, 0.0f, 1.0f, //Cc
    -0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Dd
    0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Bb
    0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Bb
    -0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f, //Dd
    -0.5f, -0.5f, 0.5f,        0.0f, 0.0f, 1.0f, //Aa
    
    0.5f, -0.5f, -0.5f,        0.0f, 0.0f, -1.0f, //B
    -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f, //A
    0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f, //C
    0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f, //C
    -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f, //A
    -0.5f, 0.5f, -0.5f,        0.0f, 0.0f, -1.0f
};


#endif
