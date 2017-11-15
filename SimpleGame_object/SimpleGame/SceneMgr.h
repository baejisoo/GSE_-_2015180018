#pragma once
#include <cstdlib>
#include <iostream>

#include "Renderer.h"
#include "object.h"
#define MAX_OBJECT_COUNT 300
#define OBJECT_BUILDING 0
#define OBJECT_CHARACTER 1
#define OBJECT_BULLET 2
#define OBJECT_ARROW 3

class SceneMgr
{
public:
	SceneMgr(int width, int height);
	~SceneMgr();

	void DrawObject();
	void SetPosObject(float x, float y, int type);
	void SetPosBuilding();
	void DeletePosObject();
	void UpdateObject(float elapsedTime);
	void CheckCollision();
	void CheckObjectStatus();
private:

	Object *g_ObjectList[MAX_OBJECT_COUNT];
	Object *g_BulletList[MAX_OBJECT_COUNT];
	Object *g_Building;
	Renderer *g_Renderer;
	int g_WindowWidth;
	int g_WindowHeight;

};