#include "GameManager.h"


//! main
/*!
The entry point into running the game.
 */
int main(int argc, char **argv){
    ///Create a pointer gameManager, to create an instance of the game,
    ///This allows for more than one instance of the game.
    GameManager *gameManager = &GameManager::getGameManager();
    
    ///Run the game.
    gameManager->runGameLoop();
    
    ///Destroy game and free up memory.
    GameManager::destroyGameManager();
}
