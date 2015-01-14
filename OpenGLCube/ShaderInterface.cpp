//
//  ShaderInterface.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "ShaderInterface.h"

GLuint ShaderInterface::getProgramHandle(){
    return shader->getProgramHandle();
}
GLint  ShaderInterface::get_aPositionVertex(){
    return _aPositionVertex;
}
GLint  ShaderInterface::get_uColor(){
    return _uColor;
}

ShaderInterface::ShaderInterface(char *VS, char *FS){
    shader = new ShaderLoader(VS,FS);
    
    _aPositionVertex = glGetAttribLocation(shader->getProgramHandle(), "aPositionVertex");
    _uColor = glGetUniformLocation(shader->getProgramHandle(), "uColor");
}

ShaderInterface::~ShaderInterface(){
    delete shader;
}