#include "stdafx.h"
#include "object.h"
#include "SceneMgr.h"
#include <cmath>
#include <iostream>

using namespace std;

Object::Object(float x, float y, int type, int team, float level)
{
	g_x = x;
	g_y = y;
	g_type = type;
	g_team = team;
	g_level = level;
	if (type == OBJECT_BUILDING)
	{
		g_vec_X = 0;
		g_vec_Y = 0;

		g_status = 1;
		g_life = 500.0;
		g_lifeTime = 1000000.0;

		g_fireTime = 0;
		g_createTime = 0;

		g_size = 50;


		if (team == TEAM_1)
		{
			g_red = 1;
			g_green = 0;
			g_blue = 0;
			g_alpha = 1;
		}
		else
		{
			g_red = 0;
			g_green = 0;
			g_blue = 1;
			g_alpha = 1;
		}
	}
	if (type == OBJECT_CHARACTER)
	{
		g_vec_X = 300.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);
		g_vec_Y = 300.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);

		g_status = 1;
		g_life = 100.0;
		g_lifeTime = 100000.f;
		g_fireTime = 0;

		g_size = 10;

		g_sprite = 0;
		g_spriteTime = 0;
		if (team == TEAM_1)
		{
			g_red = 1;
			g_green = 0;
			g_blue = 0;
			g_alpha = 1;
		}
		else
		{
			g_red = 0;
			g_green = 0;
			g_blue = 1;
			g_alpha = 1;
		}
	}
	else if (type == OBJECT_BULLET)
	{

		g_vec_X = 300.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);
		g_vec_Y = 300.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);

		g_status = 1;
		g_life = 20;
		g_lifeTime = 100000.f;

		g_size = 5;
		g_particleTime = 0;

		if (team == TEAM_1)
		{
			if (g_vec_Y >= 0)
				g_vec_Y *= -1;
			g_red = 1;
			g_green = 0;
			g_blue = 0;
			g_alpha = 1;
		}
		else
		{
			if (g_vec_Y < 0)
				g_vec_Y *= -1;
			g_red = 0;
			g_green = 0;
			g_blue = 1;
			g_alpha = 1;
		}
	}
	else if (type == OBJECT_ARROW)
	{

		g_vec_X = 100.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);
		g_vec_Y = 100.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);

		g_status = 1;
		g_life = 10;
		g_lifeTime = 100000.f;

		g_size = 5;

		if (team == TEAM_1)
		{
			g_red = 0.5;
			g_green = 0.2;
			g_blue = 0.7;
			g_alpha = 1;
		}
		else
		{
			g_red = 1;
			g_green = 1;
			g_blue = 0;
			g_alpha = 1;
		}
	}
}

Object::~Object()
{

}
void Object::CreateChar(float elapsedTime) {
	float elapsedTimeSec = elapsedTime / 1000.0;
	g_createTime += elapsedTimeSec;
}

void Object::Update(float elapsedTime)
{
	float elapsedTimeSec = elapsedTime / 1000.0;
	g_x = g_x + g_vec_X * elapsedTimeSec;
	g_y = g_y + g_vec_Y * elapsedTimeSec;
	g_fireTime += elapsedTimeSec;
	g_createTime += elapsedTimeSec;

	//cout << "sp time " << g_spriteTime << endl;
	//cout << "sprite " << g_sprite << endl;
	if (g_spriteTime < 1)
	{
		g_spriteTime += 0.2;
	}
	else
	{
		g_sprite += 1;
		g_spriteTime = 0;
	}
	if (g_particleTime < 1)
		g_particleTime += elapsedTimeSec *0.1;
	else
		g_particleTime = 0;
	if (g_type == OBJECT_BULLET || g_type == OBJECT_ARROW)
	{
		if (g_x > 250)
			g_life = 0;
		else if (g_x < -250)
			g_life = 0;
		if (g_y > 400)
			g_life = 0;
		else if (g_y < -400)
			g_life = 0;
	}
	else
	{
		if (g_x > 250)
			g_vec_X *= -1;
		else if (g_x < -250)
			g_vec_X *= -1;
		if (g_y > 400)
			g_vec_Y *= -1;
		else if (g_y < -400)
			g_vec_Y *= -1;
	}
	if (g_life > 0.0)
	{
		//g_life -= 0.1;
		//cout << g_life << endl;
	}
	if (g_life <= 0.0)
	{
		g_status = 0;
	}
	if (g_type == OBJECT_CHARACTER)
	{
		if (g_sprite > 5)
			g_sprite = 0;
	}
}

void Object::SetDamage(int damage)
{
	g_life -= damage;
}
float Object::GetLife()
{
	return g_life;
}

float Object::GetLifeTime()
{
	return g_lifeTime;
}
void Object::MouseSetObject(float x, float y)
{
	g_x = x;
	g_y = y;
	g_vec_X = 1;
	g_vec_Y = 1;

	g_status = 1;
	g_size = 10;
	g_red = 0;
	g_green = 1;
	g_blue = 1;
	g_alpha = 1;
}
