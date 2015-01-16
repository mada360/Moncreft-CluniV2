//
//  GameManager.cpp
//  OpenGLCube
//
//  Created by Adam Worley on 14/01/2015.
//  Copyright (c) 2015 Adam Worley. All rights reserved.
//

#include "GameManager.h"


GameManager::GameManager(bool running):
_running(running), _window(glfwGetCurrentContext()),
_renderSystem(&RenderSystem::getRenderSystem()),
_resourceManager(&ResourceManager::getResourceManager()),
_movementSystem(&MovementSystem::getMovementSystem()),
_cameraSystem(&CameraSystem::getCameraSystem()), scene(new Scene), _playerInputSystem(&PlayerInputSystem::getPlayerInputSystem())
{
}

//! GameManager destructor.
/*!
 Deletes each part of the game and frees up memory.
 */
GameManager::~GameManager(){
    ResourceManager::destroyResourceManager();
    CameraSystem::destroyCameraSystem();
    RenderSystem::destroyRenderSystem();
    PlayerInputSystem::destroyPlayerInputSystem();
}

#define Updates_Per_Second 60.0f

void GameManager::runGameLoop(){
    double lastTime = glfwGetTime();
    double deltaTime = 0.0f;
    
    while (_running) {
        
        double currentTime = glfwGetTime();
        deltaTime += (currentTime - lastTime) * Updates_Per_Second;
        lastTime = currentTime;
        
        while (deltaTime >= 1.0f) {
            
            _running = !glfwWindowShouldClose(_window);
            
            _movementSystem->update(scene->getChildren());
            _playerInputSystem->update();
            
            --deltaTime;
        }
        
        _renderSystem->render(scene->getChildren());
    }
}

//! GameManager create.
/*!
 Creates all basic window context and colour settings.
 */
GameManager& GameManager::getGameManager(){
    ///Create instance of game.
    static GameManager *gameManager = NULL;
    
    ///Ensures that the following code will not run if gameManager has been instantiated.
    if (gameManager == NULL) {
        ///Initialise window.
        glfwInit();
        
        glfwWindowHint(GLFW_DEPTH_BITS, 24);       ///
        glfwWindowHint(GLFW_RED_BITS, 8);          /*! Set red bit depth to a value of 8. */
        glfwWindowHint(GLFW_GREEN_BITS, 8);        /*! Set green bit depth to a value of 8. */
        glfwWindowHint(GLFW_BLUE_BITS, 8);         /*! Set blue bit depth to a value of 8. */
        glfwWindowHint(GLFW_ALPHA_BITS, 8);        /*! Set alpha bit depth to a value of 8. */
        glfwWindowHint(GLFW_SAMPLES, 16);          ///
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);  /// Window is set to a fixed size.
        
        //! A pure virtual member.
        /*!
         \sa glfwCreateWindow
         \param 1280 Screen Width.
         \param 720 The screen height.
         \param NULL, NULL - Not used, as options for multiple displays.
         */
        GLFWwindow *window = glfwCreateWindow(1280, 720, "OpenGL Cube", NULL, NULL);  /// Screen settings glfwCreateWindow(width, height, title...
        ///The other two parameters are used for multiple display setups and will not be used.
        
        glfwMakeContextCurrent(window); ///Creates the context window, the game window is now visible.
    
        gameManager = new GameManager(true);
        ///Console output - Not needed, may remove.
        std::cout << "GameManager created" << std::endl;
    }
    ///Return the window/context to be set to run in main.
    return *gameManager;
}

void GameManager::destroyGameManager(){
    ///Gets the current game and deletes it.
    GameManager *gameManager = &getGameManager();
    delete gameManager;
    ///Console output during development, not needed - May remove.
    std::cout << "GameManager destroyed" << std::endl;
    
    ///Gets the context window and destroys
    GLFWwindow *window = glfwGetCurrentContext();
    glfwDestroyWindow(window);
    
    ///End glfw and free memory.
    glfwTerminate();
    
}