//
//  VertexBuffer.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#include "VertexBuffer.h"

GLuint VertexBuffer::getVertexBufferID(){
    return _vertexBufferID;
}

ShaderInterface *VertexBuffer::getShader(){
    return _shader;
}

ShaderData *VertexBuffer::getShaderData(){
    return _shaderData;
}

VertexBuffer::VertexBuffer(const GLvoid *data,
                           GLsizeiptr size,
                           GLenum mode,
                           GLsizei count,
                           GLsizei stride,
                           ShaderInterface *shader,
                           ShaderData *shaderData,
                           GLvoid *positionOffset,
                           GLvoid *normalOffset):
_mode(mode), _count(count), _stride(stride), _shader(shader), _positionOffset(positionOffset), _normalOffset(normalOffset),
_shaderData(shaderData){
    glGenBuffers(1, &_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

//!Vertex Buffer destructor
/*!
 Deletes all vertex buffers and sets the vertexBuffer variable to 0.
 */
VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &_vertexBufferID);
    _vertexBufferID = 0;
}

//!configure Vertex Attributes
/*!
 When _shader is empty (-1 position) grab a new position vertex and apply this to the vertex attributes.
 */
void VertexBuffer::configureVertexAttributes(){
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferID);
    if (_shader->get_aPositionVertex() != -1) {
        glEnableVertexAttribArray(_shader->get_aPositionVertex());
        glVertexAttribPointer(_shader->get_aPositionVertex(), 3, GL_FLOAT, GL_FALSE, _stride, _positionOffset);
    }
    
    if (_shader->get_aPositionNormal() != -1) {
        glEnableVertexAttribArray(_shader->get_aPositionNormal());
        glVertexAttribPointer(_shader->get_aPositionNormal(), 3, GL_FLOAT, GL_FALSE, _stride, _normalOffset);
    }
}

//!render Vertex Buffer
/*!
 Calls for the open gl to draw arrays
 \param Primitve render type
 \param Start position (0 start)
 \param Size of array vertices. 
 */
void VertexBuffer::renderVertexBuffer(){
    glDrawArrays(_mode, 0, _count);
}
