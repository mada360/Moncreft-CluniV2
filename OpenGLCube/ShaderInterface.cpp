//
//  ShaderInterface.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#include "ShaderInterface.h"
#include <stdio.h>
#include <stdlib.h>

GLuint ShaderInterface::getProgramHandle(){
    return shader->getProgramHandle();
}

GLint ShaderInterface::get_aPositionVertex(){
    return _aPositionVertex;
}

GLint ShaderInterface::get_aPositionNormal(){
    return _aPositionNormal;
}

GLint ShaderInterface::get_uColor(){
    return _uColor;
}

GLint ShaderInterface::get_uLightPosition(){
    return _uLightPosition;
}

//!Shader Interface
/*!
 Takes the shader files applies them to the Shader loader.
 */
ShaderInterface::ShaderInterface(const char *VS, const char *FS){
    
    _vertexShaderString = loadTextFromFile(VS);
    _fragmentShaderString = loadTextFromFile(FS);
    
    //!new ShaderLoader
    /*!
     loads the vertex and fragment shader text files into the shader loader.
     */
    shader = new ShaderLoader(_vertexShaderString, _fragmentShaderString);
    
    //!Free shader
    /*!
     Release the shader text files from memory.
     */
    free(_vertexShaderString);
    free(_fragmentShaderString);
    
    _aPositionVertex = glGetAttribLocation(shader->getProgramHandle(), "aPositionVertex");
    _aPositionNormal = glGetAttribLocation(shader->getProgramHandle(), "aPositionNormal");
    
    _uColor = glGetUniformLocation(shader->getProgramHandle(), "uColor");
    _uLightPosition = glGetUniformLocation(shader->getProgramHandle(), "uLightPosition");
    
}

//!Shader Interface Deconstructor
/*!
 Delets the shader.
 */
ShaderInterface::~ShaderInterface(){
    delete shader;
}


//!Load Text From File
/*!
 Loads in the text from the external shader files. 
 Currently has infrequent errors and needs to be fixed!
 Returns the data from within the text file.
 */
char *ShaderInterface::loadTextFromFile(const char *file){
    std::ifstream input_file;
    int length;
    input_file.open(file, std::ios::in);
    
    input_file.seekg(0, std::ios::end);  // go to the end of the file
    length = (int)input_file.tellg();    // get length of the file
    input_file.seekg(0, std::ios::beg);  // go to beginning of the file
    
    char * data = new char[length+1];
    input_file.read(data, length);
    data[length+1]='\0';  // Ensure null terminated
    
    input_file.close();
    
    return data;
}