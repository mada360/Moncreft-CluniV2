//
//  ShaderInterface.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#ifndef __SimpleFPS__ShaderInterface__
#define __SimpleFPS__ShaderInterface__

#include <iostream>
#include "ShaderLoader.h"
#include <fstream>

class ShaderInterface{
private:
    
    ShaderLoader *shader;
    
    GLint _aPositionVertex;
    GLint _aPositionNormal;
    GLint _uColor;
    GLint _uLightPosition;
    
    char *_vertexShaderString;
    char *_fragmentShaderString;
    
    char *loadTextFromFile(const char *file);
    
public:
    
    GLuint getProgramHandle();
    GLint get_aPositionVertex();
    GLint get_aPositionNormal();
    GLint get_uColor();
    GLint get_uLightPosition();
    
    ShaderInterface(const char *VS, const char *FS);
    ~ShaderInterface();
    
};

#endif /* defined(__SimpleFPS__ShaderInterface__) */
