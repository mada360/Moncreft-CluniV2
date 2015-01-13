#include "/Users/mada360/Downloads/glfw-3.0.4/include/GLFW/glfw3.h"
#include "CubeManager.h"
int main(int argc, char **argv)
{
    CubeManager *cubeManager = &CubeManager::getCubeManager();
    cubeManager->runGameLoop();
    CubeManager::destroyCubeManager();
}