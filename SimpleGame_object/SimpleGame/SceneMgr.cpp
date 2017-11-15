#include "stdafx.h"
#include "SceneMgr.h"
#include <iostream>
using namespace std;

int CharNum = 0;
int BulletNum = 0;
int ArrowNum = 0;

SceneMgr::SceneMgr(int width, int height)
{
	// Initialize Renderer
	
	g_Renderer = new Renderer(width, height);
	if (!g_Renderer->IsInitialized())
	{
		std::cout << "Renderer could not be initialized.. \n";
	}
	g_WindowWidth = width;
	g_WindowHeight = height;

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		g_ObjectList[i] = NULL;
		g_BulletList[i] = NULL;
	}
	g_Building = NULL;
}

SceneMgr::~SceneMgr()
{
}
void SceneMgr::SetPosBuilding()
{
	if (g_Building == NULL)
	{
		g_Building = new Object(0, 0, OBJECT_BUILDING);
	}
}
void SceneMgr::SetPosObject(float x, float y, int type)
{
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (g_ObjectList[i] == NULL)
		{
			g_ObjectList[i] = new Object(x, y, type);
			cout << "Set" << endl;
			break;
		}
	}
}

void SceneMgr::UpdateObject(float elapsedTime)
{
	//CheckCollision();

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (g_ObjectList[i] != NULL)
		{
			if (g_ObjectList[i]->g_status == 0)
			{
				delete g_ObjectList[i];
				g_ObjectList[i] = NULL;
			}
			else if (g_ObjectList[i]->g_status == 1)
			{
				g_ObjectList[i]->Update(elapsedTime);
			}
		}

		if(g_BulletList[i] != NULL)
		{
			g_BulletList[i]->Update(elapsedTime);
		}
	}

}

void SceneMgr::CheckObjectStatus()
{
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (g_ObjectList[i]->g_status == 0)
			g_ObjectList[i] = NULL;
	}
}
void SceneMgr::CheckCollision()
{
	bool IsCollid = false;
	int collisionNum;

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (g_ObjectList[i] != NULL)
		{
			for (int j = 0; j < MAX_OBJECT_COUNT; ++j)
			{
				if(i==j || g_ObjectList[i]==NULL || g_ObjectList[j] == NULL)
					continue;
				if (g_ObjectList[j] != NULL)
				{
					double minX1, minY1, maxX1, maxY1;
					double minX2, minY2, maxX2, maxY2;

					minX1 = g_ObjectList[i]->g_x - g_ObjectList[i]->g_size / 2.0;
					minY1 = g_ObjectList[i]->g_y - g_ObjectList[i]->g_size / 2.0;
					maxX1 = g_ObjectList[i]->g_x + g_ObjectList[i]->g_size / 2.0;
					maxY1 = g_ObjectList[i]->g_y + g_ObjectList[i]->g_size / 2.0;

					minX2 = g_ObjectList[j]->g_x - g_ObjectList[j]->g_size / 2.0;
					minY2 = g_ObjectList[j]->g_y - g_ObjectList[j]->g_size / 2.0;
					maxX2 = g_ObjectList[j]->g_x + g_ObjectList[j]->g_size / 2.0;
					maxY2 = g_ObjectList[j]->g_y + g_ObjectList[j]->g_size / 2.0;

					if (minX1 > maxX2)
						IsCollid = false;
					if (maxX1 < minX2)
						IsCollid = false;
					if (minY1 > maxY2)
						IsCollid = false;
					if (maxY1 < minY2)
						IsCollid = false;
					else
						IsCollid = true;

					if (IsCollid == true)
						{
							g_ObjectList[i]->g_red = 1;
							g_ObjectList[i]->g_green = 0;
							g_ObjectList[i]->g_blue = 0;
							g_ObjectList[i]->g_alpha = 1;

							g_ObjectList[j]->g_red = 1;
							g_ObjectList[j]->g_green = 0;
							g_ObjectList[j]->g_blue = 0;
							g_ObjectList[j]->g_alpha = 1;
						}
					else
						{
							g_ObjectList[i]->g_red = 1;
							g_ObjectList[i]->g_green = 1;
							g_ObjectList[i]->g_blue = 1;
							g_ObjectList[i]->g_alpha = 1;

							g_ObjectList[j]->g_red = 1;
							g_ObjectList[j]->g_green = 1;
							g_ObjectList[j]->g_blue = 1;
							g_ObjectList[j]->g_alpha = 1;
						}
				}
			}
		}

	}
}
/*
void SceneMgr::DeletePosObject(int num)
{
	if (g_ObjectList[num] != NULL)
	{
		delete g_ObjectList[num];
		g_ObjectList[num] = NULL;
	}
}
*/
void SceneMgr::DrawObject()
{
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	
	if (g_Building != NULL) {
		g_Renderer->DrawTexturedRect(0, 0, 0, 50, 1, 1, 0, 1,
			g_Renderer->CreatePngTexture("Textures/test.png"));
	}

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		
		if (g_ObjectList[i] != NULL) {
			g_Renderer->DrawSolidRect(
				g_ObjectList[i]->g_x,
				g_ObjectList[i]->g_y,
				0,
				g_ObjectList[i]->g_size,
				g_ObjectList[i]->g_red,
				g_ObjectList[i]->g_green,
				g_ObjectList[i]->g_blue,
				g_ObjectList[i]->g_alpha
			);
		}
	}
	
}

