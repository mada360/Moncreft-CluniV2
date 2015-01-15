//
//  ShaderData.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//
// Followed Tutorial made by Dimitriy Dounaev, youtube channel - https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw


#include "ShaderData.h"

Vector4 ShaderData::get_uColorValue(){
    return _uColorValue;
}

void ShaderData::set_uColorValue(Vector4 newColor){
    _uColorValue = newColor;
}

Vector3 ShaderData::get_uLightPosition(){
    return _uLightPosition;
}

void ShaderData::set_uLightPosition(Vector3 newPosition){
    _uLightPosition = newPosition;
}

ShaderData::ShaderData(Vector4 newColor, Vector3 newPosition):
_uColorValue(newColor),_uLightPosition(newPosition){
    
}

ShaderData::~ShaderData(){
    
}
