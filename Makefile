  #ifdef __APPLE__
	  #  include <OpenGL/gl.h>
	  #  include <OpenGL/glu.h>
	  #  include <GLUT/glut.h>
	  #else
	  #  include <GL/gl.h>
	  #  include <GL/glu.h>
	  #  include <GL/glut.h>
	  #endif


OBJS = Main.o CameraSystem.o Entity.o GameManager.o Matrix3.o MovementSystem.o PlayerInputSystem.o ResourceManager.o Scene.o ShaderData.o Vector2.o Vector3.o Vector4.o VertexBuffer.o ShaderLoader.o ShaderInterface.o RenderSystem.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: OpenGLCube clean

OpenGLCube: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o OpenGLCube -lGLEW -lGL -lGLU -lglut -lGLEW -lm -lGLFW3

Main.o: ./OpenGLCube/Main.cpp ./OpenGLCube/GameManager.h
	$(CC) $(CFLAGS) ./OpenGLCube/Main.cpp

CameraSystem.o:  ./OpenGLCube/CameraSystem.h ./OpenGLCube/CameraSystem.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/CameraSystem.cpp

Entity.o: ./OpenGLCube/Entity.h ./OpenGLCube/Entity.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/Entity.cpp

GameManager.o: ./OpenGLCube/GameManager.h ./OpenGLCube/GameManager.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/GameManager.cpp

Matrix3.o: ./OpenGLCube/Matrix3.h ./OpenGLCube/Matrix3.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/Matrix3.cpp

MovementSystem.o: ./OpenGLCube/MovementSystem.h ./OpenGLCube/MovementSystem.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/MovementSystem.cpp


PlayerInputSystem.o: ./OpenGLCube/PlayerInputSystem.h ./OpenGLCube/PlayerInputSystem.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/PlayerInputSystem.cpp


RenderSystem.o: ./OpenGLCube/RenderSystem.h ./OpenGLCube/ShaderInterface.h ./OpenGLCube/RenderSystem.cpp 
	$(CC) $(CFLAGS) ./OpenGLCube/RenderSystem.cpp

ResourceManager.o: ./OpenGLCube/ResourceManager.h ./OpenGLCube/ResourceManager.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/ResourceManager.cpp


Scene.o: ./OpenGLCube/Scene.h ./OpenGLCube/Scene.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/Scene.cpp

ShaderData.o: ./OpenGLCube/ShaderData.h ./OpenGLCube/ShaderData.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/ShaderData.cpp

ShaderInterface.o: ./OpenGLCube/ShaderInterface.h ./OpenGLCube/ShaderInterface.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/ShaderInterface.cpp

ShaderLoader.o: ./OpenGLCube/ShaderLoader.h ./OpenGLCube/ShaderLoader.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/ShaderLoader.cpp

Vector2.o: ./OpenGLCube/Vector2.h ./OpenGLCube/Vector2.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/Vector2.cpp

Vector3.o: ./OpenGLCube/Vector3.h ./OpenGLCube/Vector3.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/Vector3.cpp

Vector4.o: ./OpenGLCube/Vector4.h ./OpenGLCube/Vector4.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/Vector4.cpp

VertexBuffer.o: ./OpenGLCube/VertexBuffer.h ./OpenGLCube/VertexBuffer.cpp
	$(CC) $(CFLAGS) ./OpenGLCube/VertexBuffer.cpp


clean:
	@echo "**Cleaning up object and tmp files**"
	rm -rf *.o *~
