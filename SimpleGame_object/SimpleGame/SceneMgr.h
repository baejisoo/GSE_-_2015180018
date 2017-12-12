#pragma once
#include <cstdlib>
#include <iostream>

#include "Renderer.h"
#include "object.h"
#define MAX_OBJECT_COUNT 3000
#define OBJECT_BUILDING 0
#define OBJECT_CHARACTER 1
#define OBJECT_BULLET 2
#define OBJECT_ARROW 3
#define TEAM_1 1
#define TEAM_2 2
#define LEVEL_GOD 0
#define LEVEL_SKY 0.1
#define LEVEL_GROUND 0.2
#define LEVEL_UNDERGROUND 0.3

class SceneMgr
{
public:
	SceneMgr(int width, int height);
	~SceneMgr();
	
	float CreateCharTime = 0;

	void DrawObject();
	void SetPosObject(float x, float y, int type, int team);
	void SetPosBuilding();
	void DeletePosObject(int num);
	void UpdateObject(float elapsedTime);
	void CheckCollision();
	void CheckObjectStatus();
private:

	Object *g_ObjectList[MAX_OBJECT_COUNT];
	Object *g_Building;
	Renderer *g_Renderer;
	int g_WindowWidth;
	int g_WindowHeight;

};