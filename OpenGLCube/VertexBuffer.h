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
#include <GLFW/glfw3.h>

class VertexBuffer{
    
private:
    GLuint _vertexBufferID;
    
    GLenum _mode;
    GLsizei _count;
    GLsizei _stride;
    
public:
    
    GLuint getVertexBufferID();
    
    VertexBuffer(const GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride);
    ~VertexBuffer();
    
    void configureVertexAttributes(GLint vertexPosition);
    void renderVertexBuffer();
    
};

#endif /* defined(__OpenGLCube__VertexBuffer__) */
