/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "object.h"

Renderer *g_Renderer = NULL;
Object *g_Object = NULL;
Object *m_Object = NULL;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	g_Renderer->DrawSolidRect(g_Object->getX(), g_Object->getY(), g_Object->getZ(), g_Object->getSize(), g_Object->getR(), g_Object->getG(), g_Object->getB(), g_Object->getA());

	glutSwapBuffers();
}


void Idle(void)
{
	RenderScene();
	g_Object->UpdateObject(g_Object->getX(), g_Object->getY(), g_Object->getZ(), g_Object->getSize(), g_Object->getStatus(), g_Object->getSpeed());

	// std::cout << g_Object->getX() << ", " << g_Object->getY() << std::endl;

}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
	g_Object->CreateObject(x, y, 0.0f, 10.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.01f);
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	// Initialize Renderer
	g_Renderer = new Renderer(500, 500);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}

	g_Object = new Object(10.0f, 10.0f, 0.0f, 10.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.5f);
	//m_Object = new Object(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f);

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

	//
	delete g_Object;
    return 0;
}

