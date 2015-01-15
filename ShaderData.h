//
//  ShaderData.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__ShaderData__
#define __OpenGLCube__ShaderData__

#include <stdio.h>
#include <GLFW/glfw3.h>
#include "Vector3.h"
#include "Vector4.h"

class ShaderData{
private:
    
    Vector4 _uColorValue;
    Vector3 _uLightPosition;
    
public:
    
    Vector4 get_uColorValue();
    void set_uColorValue(Vector4 newColor);
    
    Vector3 get_uLightPosition();
    void set_uLightPosition(Vector3 newPosition);
    
    ShaderData(Vector4 newColor, Vector3 newPosition);
    ~ShaderData();   
};

#endif /* defined(__OpenGLCube__ShaderData__) */
