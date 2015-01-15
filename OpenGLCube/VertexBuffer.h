//
//  VertexBuffer.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#ifndef __OpenGLCube__VertexBuffer__
#define __OpenGLCube__VertexBuffer__

#include <iostream>
#include <GLFW/glfw3.h>
#include "ShaderInterface.h"
#include "ShaderData.h"

class VertexBuffer
{
private:
    
    GLuint _vertexBufferID;
    ShaderInterface *_shader;
    ShaderData *_shaderData;
    
    GLenum _mode;
    GLsizei _count;
    GLsizei _stride;
    GLvoid *_positionOffset;
    GLvoid *_normalOffset;
    
public:
    
    GLuint getVertexBufferID();
    ShaderInterface *getShader();
    ShaderData *getShaderData();
    
    VertexBuffer(const GLvoid *data,
                 GLsizeiptr size,
                 GLenum mode,
                 GLsizei count,
                 GLsizei stride,
                 ShaderInterface *shader,
                 ShaderData *shaderData,
                 GLvoid *positionOffset,
                 GLvoid *normalOffset);
    ~VertexBuffer();
    
    void configureVertexAttributes();
    void renderVertexBuffer();
};

#endif /* defined(__OpenGLCube__VertexBuffer__) */
