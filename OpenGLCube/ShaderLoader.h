//
//  ShaderLoader.h
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__ShaderLoader__
#define __OpenGLCube__ShaderLoader__

#include <stdio.h>
#include <GLFW/glfw3.h>

class ShaderLoader{
private:
    
    GLuint _programHandle;
    
    GLuint compileShader(GLenum, const char *source);
    
public:
    
    GLuint getProgramHandle();
    
    ShaderLoader(const char *sourceVS, const char *sourceFS); //VS vertex shader, FS fragment shader
    ~ShaderLoader();
    
};

#endif /* defined(__OpenGLCube__ShaderLoader__) */
