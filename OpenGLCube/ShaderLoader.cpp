//
//  ShaderLoader.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#include "ShaderLoader.h"

GLuint ShaderLoader::getProgramHandle(){
    return _programHandle;
}

GLuint ShaderLoader::compileShader(GLenum shader, const char *source){
    GLuint shaderHandle = glCreateShader(shader);
    glShaderSource(shaderHandle, 1, &source, NULL);
    glCompileShader(shaderHandle);
    
    //printShaderInfoLog(shaderHandle);
    
    return shaderHandle;
}

ShaderLoader::ShaderLoader(const char *sourceVS, const char *sourceFS){
    _programHandle = glCreateProgram();
    
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, sourceVS);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, sourceFS);
    
    glAttachShader(_programHandle, vertexShader);
    glAttachShader(_programHandle, fragmentShader);
    
    glLinkProgram(_programHandle);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

ShaderLoader::~ShaderLoader(){
    glDeleteProgram(_programHandle);
}