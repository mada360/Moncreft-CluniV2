//
//  ResourceManager.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__ResourceManager__
#define __OpenGLCube__ResourceManager__

#include <iostream>
#include <vector>
#include "ShaderInterface.h"
#include "VertexBuffer.h"
#include "ShaderData.h"

class ResourceManager{
private:
    
    std::vector<ShaderInterface *> *_shaderArray;
    std::vector<VertexBuffer *> *_vertexBufferArray;
    
    ShaderData *shaderData;
    
    ResourceManager();
    ~ResourceManager();
    
public:
    
    std::vector<ShaderInterface *>* getShaderArray();
    std::vector<VertexBuffer *>* getVertexBufferArray();
    
    static ResourceManager& getResourceManager();
    static void destroyResourceManager();
    
};

#endif /* defined(__OpenGLCube__ResourceManager__) */
