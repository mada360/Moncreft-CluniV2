//
//  ResourceManager.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "ResourceManager.h"
#include "TriangleVertices.h"
#include "CubeVertices.h"


//!Get Shader Array
/*!
 Returns the variable _shader array.
 */
std::vector<ShaderInterface *>* ResourceManager::getShaderArray(){
    return _shaderArray;
}

//!Get Vertex Array
/*!
 Returns the variable _vertexBufferArray
 */
std::vector<VertexBuffer *>* ResourceManager::getVertexBufferArray(){
    return _vertexBufferArray;
}

//!Resource Manager Constructor
/*!
Uses shader matrices to generate resources.
 */
ResourceManager::ResourceManager(){
    _shaderArray = new std::vector<ShaderInterface *>();
    //!Color shader (aka colour shader)
    /*!
     Takes the colour shader files and applies them to the shader interface.
     */
    ShaderInterface *shader = new ShaderInterface("ColorShader.vsh", "ColorShader.fsh");
    _shaderArray->push_back(shader);
    //!Light shader
    /*!
     Takes the light shader files and applies them to the shader interface.
     */
    ShaderInterface *lightShader = new ShaderInterface("SimpleLightShader.vsh", "SimpleLightShader.fsh");
    _shaderArray->push_back(lightShader);
    
    shaderData = new ShaderData(makeVector4(1.0f, 0.0f, 1.0f, 1.0f), makeVector3(1.0f, 1.0f, 1.0f));
    
    
    //!Pyramid
    /*!
     Vertex buffer for a pyrmaid shape.
     */
    _vertexBufferArray = new std::vector<VertexBuffer *>();
    VertexBuffer *vertexBuffer = new VertexBuffer(vertices,
                                                  sizeof(vertices),
                                                  GL_TRIANGLES,
                                                  3,
                                                  sizeof(GLfloat)*3,
                                                  _shaderArray->at(0),
                                                  shaderData,
                                                  NULL,
                                                  NULL);
    
    //!Cube
    /*!
     Vertex buffer for a cube.
     */
    _vertexBufferArray->push_back(vertexBuffer);
    VertexBuffer *cubeVertexBuffer = new VertexBuffer(cubeVertices,
                                                      sizeof(cubeVertices),
                                                      GL_TRIANGLES,
                                                      36,
                                                      sizeof(VertexDataPN),
                                                      _shaderArray->at(1),
                                                      shaderData,
                                                      (GLvoid *)(offsetof(VertexDataPN, positionCoordinates)),
                                                      (GLvoid *)(offsetof(VertexDataPN, normalCoordinates)));
    _vertexBufferArray->push_back(cubeVertexBuffer);
}

//!Resource Manager Destructor
/*!
 Deletes all the shaders and then deletes the shader array, before deleting the shaderData array.
 */
ResourceManager::~ResourceManager(){
    
    for (std::vector<ShaderInterface *>::iterator iterator = _shaderArray->begin();
         iterator != _shaderArray->end();
         iterator++) {
        delete *iterator;
    }
    
    delete _shaderArray;
    
    for (std::vector<VertexBuffer *>::iterator iterator = _vertexBufferArray->begin();
         iterator != _vertexBufferArray->end();
         iterator++) {
        delete *iterator;
    }
    
    delete shaderData;
    delete _vertexBufferArray;
}


//!Get resource manager method
/*!
 Returns the resource manager.
 */
ResourceManager& ResourceManager::getResourceManager(){
    static ResourceManager *resourceManager = NULL;
    
    if (resourceManager == NULL) {
        resourceManager = new ResourceManager();
    }
    
    return *resourceManager;
}

//!destroy Resource Manager
/*!
Deletes the resource manager and frees up the memory.
 */
void ResourceManager::destroyResourceManager(){
    ResourceManager *resourceManager = &getResourceManager();
    delete resourceManager;
}