//
//  PlayerInputSystem.h
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#ifndef __OpenGLCube__PlayerInputSystem__
#define __OpenGLCube__PlayerInputSystem__

#include <iostream>
#include  <GLFW/glfw3.h>
#include "Entity.h"
#include "Vector2.h"

class PlayerInputSystem{
private:
    
    Vector2 _lastMousePosition;
    
    Vector3 _eyeVector;
    
    GLFWwindow *_window;
    
    Entity *_currentPlayer;
    
    PlayerInputSystem();
    ~PlayerInputSystem();
    
    void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    
public:
    
    void setCurrentPlayer(Entity *newPlayer);
    
    void update();
    
    static PlayerInputSystem& getPlayerInputSystem();
    static void destroyPlayerInputSystem();
    
    static void keyCallbackFun(GLFWwindow *window, int key, int scancode, int action, int mods);
};

#endif /* defined(__OpenGLCube__PlayerInputSystem__) */
