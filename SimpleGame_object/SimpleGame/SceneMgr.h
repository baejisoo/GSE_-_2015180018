#pragma once
#include "Renderer.h"
#include "Object.h"
#define MAX_OBJECT_COUNT 50

class SceneMgr
{
public:
	Object* g_Object[MAX_OBJECT_COUNT];

	SceneMgr();
	~SceneMgr();

	void SceneMgr::Init();
};
