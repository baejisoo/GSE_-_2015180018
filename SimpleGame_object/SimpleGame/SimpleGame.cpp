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
#include <ctime>

#include "Renderer.h"
#include "object.h"
#include "SceneMgr.h"
#define MAX_OBJECTS_COUNT 10
Renderer *g_Renderer = NULL;
SceneMgr *g_SceneMgr;
//Object *m_objects[MAX_OBJECTS_COUNT];

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Renderer Test
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		if (m_objects[i]->getStatus() == 1)
			g_Renderer->DrawSolidRect(m_objects[i]->getX(), m_objects[i]->getY(), m_objects[i]->getZ(), m_objects[i]->getSize(), m_objects[i]->getR(), m_objects[i]->getG(), m_objects[i]->getB(), m_objects[i]->getA());
	}
	glutSwapBuffers();
}


void Idle(void)
{
	RenderScene();
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i) {
		if(m_objects[i]->getStatus() == 1)
			m_objects[i]->UpdateObject(m_objects[i]->getX(), m_objects[i]->getY(), m_objects[i]->getZ(), m_objects[i]->getSize(), m_objects[i]->getStatus(), m_objects[i]->getSpeed());
	}
	// std::cout << m_objects[i]->getX() << ", " << m_objects[i]->getY() << std::endl;

}

void MouseInput(int button, int state, int x, int y)
{
	RenderScene();
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// m_objects[0]->CreateObject(x - 250, 250 - y, 0.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.01f);
		//m_objects[0] = new Object((float)(x - 250), (float)(250 - y), 0.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.01f);
		//++i;
		//g_LButtonDown = true;
	}

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
	srand((unsigned)time(NULL));
	int x, y;
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		x = rand() % 500;
		y = rand() % 500;
		m_objects[i] = new Object((float)(x - 250), (float)(250 - y), 0.0f, 10.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.01f);
	}

	
	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	glutMainLoop();

	delete g_Renderer;

	//
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
//		if(m_objects[i]->getStatus == 1)
//			delete m_objects[i];
	}
	return 0;
}

