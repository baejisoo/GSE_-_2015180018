#include <iostream>
#include "stdafx.h"
#include "SceneMgr.h"
#include <ctime>
using namespace std;
#define MAX_OBJECTS_COUNT 10

SceneMgr::SceneMgr() {
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
		g_Object[i] = NULL;
}

SceneMgr::~SceneMgr() {

	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
		if (g_Object[i] != NULL)
			delete g_Object[i];
}

void SceneMgr::Init()
{
	srand((unsigned)time(NULL));
	int x, y;
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		x = rand() % 250;
		y = rand() % 250;

		g_Object[i] = new Object(x, y);
	}
}
