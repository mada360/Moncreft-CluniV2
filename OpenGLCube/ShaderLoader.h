//
//  ShaderLoader.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#ifndef __OpenGLCube__ShaderLoader__
#define __OpenGLCube__ShaderLoader__

#include <iostream>
#include <GLFW/glfw3.h>

class ShaderLoader{
private:
    
    GLuint _programHandle;
    
    GLuint compileShader(GLenum shader, const  char *source);
    
public:
    
    GLuint getProgramHandle();
    
    ShaderLoader(const char *sourceVS, const char *sourceFS);
    ~ShaderLoader();
    
};

#endif /* defined(__OpenGLCube__ShaderLoader__) */
