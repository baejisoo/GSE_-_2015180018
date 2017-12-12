/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"
using namespace std;

#include "SceneMgr.h"
#include "object.h"

SceneMgr *g_SceneMgr = NULL;

DWORD g_prevTime = 0;

float coolTime = 7.0;
void RenderScene(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	
	DWORD currTime = timeGetTime();
	DWORD elapsedTime = currTime - g_prevTime;
	g_prevTime = currTime;
	
	coolTime += elapsedTime / 1000.0;
	g_SceneMgr->UpdateObject(elapsedTime);
	g_SceneMgr->DrawObject();
	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << "Click: " << x << ", " << y << endl;
		if (-400 < 400 - y && 400 - y < 0 && coolTime > 7)
		{
			g_SceneMgr->SetPosObject(x - 250, 400 - y, OBJECT_CHARACTER, TEAM_2);
			coolTime = 0;
		}
	}
	RenderScene();
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
	glutInitWindowSize(500, 800);
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

	glutDisplayFunc(RenderScene);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);

	g_SceneMgr = new SceneMgr(500, 800);
	g_SceneMgr->SetPosObject(-150, 300, OBJECT_BUILDING, TEAM_1);
	g_SceneMgr->SetPosObject(0, 300, OBJECT_BUILDING, TEAM_1);
	g_SceneMgr->SetPosObject(150, 300, OBJECT_BUILDING, TEAM_1);
	
	g_SceneMgr->SetPosObject(-150, -300, OBJECT_BUILDING, TEAM_2);
	g_SceneMgr->SetPosObject(0, -300, OBJECT_BUILDING, TEAM_2);
	g_SceneMgr->SetPosObject(150, -300, OBJECT_BUILDING, TEAM_2);
	//g_SceneMgr->SetPosBuilding();
	g_prevTime = timeGetTime();

	glutMainLoop();

	delete g_SceneMgr;

	return 0;
}

