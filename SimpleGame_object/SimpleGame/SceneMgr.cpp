#include "stdafx.h"
#include "SceneMgr.h"
#include <iostream>
using namespace std;

int objectNum = 0;
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
	}
	//g_Building = NULL;
}

SceneMgr::~SceneMgr()
{
}
void SceneMgr::SetPosBuilding()
{
	if (g_Building == NULL)
	{
		g_Building = new Object(0,0, OBJECT_BUILDING, TEAM_1);
	}
}
void SceneMgr::SetPosObject(float x, float y, int type, int team)
{
	if (g_ObjectList[objectNum] == NULL)
	{
		if (type == OBJECT_BUILDING) {
			g_ObjectList[objectNum] = new Object(x, y, OBJECT_BUILDING, team);
			++objectNum;
		}
		if (type == OBJECT_BULLET) {
			g_ObjectList[objectNum] = new Object(x, y, OBJECT_BULLET, team);
			++objectNum;
		}
		if (type == OBJECT_CHARACTER) {
			g_ObjectList[objectNum] = new Object(x, y, OBJECT_CHARACTER, team);
			++objectNum;
		}
		if (type == OBJECT_ARROW) {
			g_ObjectList[objectNum] = new Object(x, y, OBJECT_ARROW, team);
			++objectNum;
		}
	}
	/*
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (g_ObjectList[i] == NULL)
		{
			g_ObjectList[i] = new Object(x, y, type);
			cout << "Set" << endl;
			break;
		}
	}
	*/
}

void SceneMgr::UpdateObject(float elapsedTime)
{
	CheckCollision();
	CreateCharTime += elapsedTime / 1000.0;
	if (CreateCharTime >= 5.0)
	{
		int createX = std::rand() % 200 - 200;
		int createY = std::rand() % 300;
		cout << createX << ", " << createY << endl;
		SetPosObject(createX, createY, OBJECT_CHARACTER, TEAM_1);
		CreateCharTime = 0;
	}
	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (g_ObjectList[i] != NULL)
		{
			
			if (g_ObjectList[i]->g_life <= 0)
			{
				delete g_ObjectList[i];
				g_ObjectList[i] = NULL;
			}
			else if (g_ObjectList[i]->g_life > 0)
			{
				g_ObjectList[i]->Update(elapsedTime);

				if (g_ObjectList[i]->g_type == OBJECT_BUILDING)
				{
					
					if (g_ObjectList[i]->g_fireTime >= 5)
					{
						//cout << "Bullet" << g_ObjectList[i]->g_team<< endl;
						SetPosObject(g_ObjectList[i]->g_x, g_ObjectList[i]->g_y, OBJECT_BULLET, g_ObjectList[i]->g_team);
						g_ObjectList[i]->g_fireTime = 0;
					}
				}

				if (g_ObjectList[i]->g_type == OBJECT_CHARACTER)
				{

					if (g_ObjectList[i]->g_fireTime >= 3)
					{
						SetPosObject(g_ObjectList[i]->g_x, g_ObjectList[i]->g_y, OBJECT_ARROW, g_ObjectList[i]->g_team);
						g_ObjectList[i]->g_fireTime = 0;
					}
				}
			}
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
	int collisionNum = 0;

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		if (g_ObjectList[i] != NULL)
		{
			for (int j = i+1; j < MAX_OBJECT_COUNT; ++j)
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

					if (minX1 > maxX2 || maxX1 < minX2 || minY1 > maxY2 || maxY1 < minY2)
						IsCollid = false;
					else
					{
						IsCollid = true;
						//g_ObjectList[i]->g_status = 1;
						//g_ObjectList[j]->g_status = 1;
						//++collisionNum;
						if (g_ObjectList[i]->g_team != g_ObjectList[j]->g_team)
						{
							if (g_ObjectList[i]->g_type == OBJECT_BUILDING && g_ObjectList[j]->g_type == OBJECT_CHARACTER)
							{
								g_ObjectList[i]->SetDamage(g_ObjectList[j]->g_life);
								g_ObjectList[j]->SetDamage(g_ObjectList[j]->g_life);	// ¼Ò¸ê
								cout << "Buliding Life: " << g_ObjectList[i]->g_life;
								cout << "Character Life: " << g_ObjectList[j]->g_life;
							}
							if (g_ObjectList[i]->g_type == OBJECT_BULLET && g_ObjectList[j]->g_type == OBJECT_CHARACTER)
							{
								g_ObjectList[i]->SetDamage(g_ObjectList[i]->g_life); // ¼Ò¸ê
								g_ObjectList[j]->SetDamage(g_ObjectList[i]->g_life);
								cout << "Bullet Life: " << g_ObjectList[i]->g_life;
								cout << "Character Life: " << g_ObjectList[j]->g_life;
							}
							if (g_ObjectList[i]->g_type == OBJECT_BUILDING && g_ObjectList[j]->g_type == OBJECT_ARROW)
							{
								g_ObjectList[i]->SetDamage(g_ObjectList[j]->g_life); // ¼Ò¸ê
								g_ObjectList[j]->SetDamage(g_ObjectList[j]->g_life);
								cout << "Buliding Life: " << g_ObjectList[i]->g_life;
								cout << "Arrow Life: " << g_ObjectList[j]->g_life;
							}
						}
					}
					/*
					if (collisionNum > 0 && g_ObjectList[i]->g_status == 1)
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
						*/
				}
			}
		}

	}
}

void SceneMgr::DeletePosObject(int num)
{
	if (g_ObjectList[num] != NULL)
	{
		delete g_ObjectList[num];
		g_ObjectList[num] = NULL;
	}
}

void SceneMgr::DrawObject()
{
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
	
	if (g_Building != NULL) {
		g_Renderer->DrawTexturedRect(0, 0, 0, 50, 1, 1, 0, 0.5,g_Renderer->CreatePngTexture("Textures/test.png"));
		
	}

	for (int i = 0; i < MAX_OBJECT_COUNT; ++i)
	{
		
		if (g_ObjectList[i] != NULL) {
			if (g_ObjectList[i]->g_type == OBJECT_BUILDING)
			{
				if (g_ObjectList[i]->g_team == TEAM_1)
				{
					g_Renderer->DrawTexturedRect(
						g_ObjectList[i]->g_x,
						g_ObjectList[i]->g_y,
						0,
						g_ObjectList[i]->g_size,
						g_ObjectList[i]->g_red,
						g_ObjectList[i]->g_green,
						g_ObjectList[i]->g_blue,
						g_ObjectList[i]->g_alpha,
						g_Renderer->CreatePngTexture("Textures/TEAM_1.png")
					);
				}
				else
				{
					g_Renderer->DrawTexturedRect(
						g_ObjectList[i]->g_x,
						g_ObjectList[i]->g_y,
						0,
						g_ObjectList[i]->g_size,
						g_ObjectList[i]->g_red,
						g_ObjectList[i]->g_green,
						g_ObjectList[i]->g_blue,
						g_ObjectList[i]->g_alpha,
						g_Renderer->CreatePngTexture("Textures/TEAM_2.png")
					);
				}
				
			}
			else 
			{
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
	
}

