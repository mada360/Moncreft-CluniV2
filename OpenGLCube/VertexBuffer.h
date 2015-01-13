//
//  VertexBuffer.h
//  OpenGLCube
//
//  Created by Adam Worley on 13/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__VertexBuffer__
#define __OpenGLCube__VertexBuffer__

#include <stdio.h>
#include "/Users/mada360/Downloads/glfw-3.0.4/include/GLFW/glfw3.h"

class VertexBuffer{
    
private:
    GLuint _vertexBufferID;
    
public:
    
    GLuint getVertexBufferID();
    
    VertexBuffer(const GLvoid *data, GLsizeiptr size);
    ~VertexBuffer();
    
};

#endif /* defined(__OpenGLCube__VertexBuffer__) */
