//
//  ShaderInterface.h
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__ShaderInterface__
#define __OpenGLCube__ShaderInterface__

#include <stdio.h>
#include "ShaderLoader.h"

class ShaderInterface{
private:
    
    ShaderLoader *shader;
    GLint _aPositionVertex;
    GLint _uColor;
    
public:
    
    GLuint getProgramHandle();
    GLint  get_aPositionVertex();
    GLint  get_uColor();
    
    ShaderInterface(char *VS, char *FS);
    ~ShaderInterface();
    };

#endif /* defined(__OpenGLCube__ShaderInterface__) */
