# Moncreft-CluniV2

##Introduction
This is a simple project using C++ and openGL, to develop a voxel based game.
The controls are the basic WASD for movement and mouse controlls for camera; found in 99.9% of FPS Games.

##Prerequisites
You will need to a have a system with the following installed
- OpenGL
- GLFW
- GLEW
- C++11 compiler (g++ used)

On a system using the yum repository system (fedora) use:
```
$Sudo yum install glew-utils libglew-dev
```

On aptitude repository based systems (Ubuntu) please use please use:
```
$Sudo apt-get install glew-utils libglew-dev
```

On a max system using xcode, the project file should already be good to go, providing you have the libraries installed; please look to the origin sources on installation instructions.

##How to install
#####Makefile still a work in progress.


##Documentation
You can find the documentation for the code within the [Documentation](https://github.com/mada360/Moncreft-CluniV2/tree/master/Documentation) folder.


##References and Thanks
Followed Tutorial made by Dimitriy Dounaev, [youtube channel](https://www.youtube.com/channel/UCaFy_GmZA02jbHGfc3zUuPw).
In following these tutorials, I learned a lot about how the classes were implemented.


##Check list

####Urgent -
- [x] Cube not loading.
- [ ] Cube fails to load sometimes (Previous error).
- [ ] Rendering issue on cubes pushed.

####Needs Fixing -
- [ ] Only renders to half the screen, until esc -> move the window -> select window again.

####More features -
- [x] MOAR CUBES!!
- [ ] Different Cubes.
- [ ] Jump feature, for all you're jumping needs.
- [ ] Installer!!
