//
//  ShaderLoader.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#include "ShaderLoader.h"

//!getProgramHandle
/*!
 Returns the program handle
 */
GLuint ShaderLoader::getProgramHandle(){
    return _programHandle;
}

//!compile Shader
/*!
 Takes all aspects of the shader and pulls them together to pass to glCompileShader.
 */
GLuint ShaderLoader::compileShader(GLenum shader, const char *source){
    GLuint shaderHandle = glCreateShader(shader);
    glShaderSource(shaderHandle, 1, &source, NULL);
    glCompileShader(shaderHandle);
    
    ///printShaderInfoLog(shaderHandle);
    
    return shaderHandle;
}

//!Shader loader
/*!
 Loads in the vertex and fragment shader for use in the game engine.
 */
ShaderLoader::ShaderLoader(const char *sourceVS, const char *sourceFS){
    _programHandle = glCreateProgram();
    
    //!Vertex Shader
    /*!
     Compiles the source vertex shader into the openGL vertex shader.
     */
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, sourceVS);
    
    //!Fragment Shader
    /*!
     Compiles the source vertex shader into the openGL fragment shader.
     */
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, sourceFS);
    
    //!glAttachShader
    /*!
    Attaches the shader to the program handle.
     */
    glAttachShader(_programHandle, vertexShader);
    glAttachShader(_programHandle, fragmentShader);
    
    
    //!glLinkProgram
    /*!
     Links the program handle using openGL link program.
     */
    glLinkProgram(_programHandle);
    
    //!Delete the shaders
    /*!
     Now the shaders have been compiled and linked to the program, can now free up the memory used.
     */
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

//!Shader Loader Deconstructor
/*!
 Deletes the program and frees up the memory.
 */
ShaderLoader::~ShaderLoader(){
    glDeleteProgram(_programHandle);
}