#include "stdafx.h"
#include "object.h"
#include "SceneMgr.h"
#include <cmath>
#include <iostream>

using namespace std;

Object::Object(float x, float y, int type)
{
	g_x = x;
	g_y = y;
	g_type = type;
	if (type == OBJECT_BUILDING)
	{
		g_vec_X = 0;
		g_vec_Y = 0;

		g_status = 1;
		g_life = 500.0;
		g_lifeTime = 1000000.0;

		g_size = 50;

		g_red = 1;
		g_green = 1;
		g_blue = 0;
		g_alpha = 1;
	}
	else if (type == OBJECT_CHARACTER)
	{
		g_vec_X = 3.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);
		g_vec_Y = 3.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);

		g_status = 1;
		g_life = 10.0;
		g_lifeTime = 100000.f;

		g_size = 20;

		g_red = 1;
		g_green = 1;
		g_blue = 1;
		g_alpha = 1;
	}
	else if (type == OBJECT_BULLET)
	{

		g_vec_X = 600.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);
		g_vec_Y = 600.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);

		g_status = 1;
		g_life = 20;
		g_lifeTime = 100000.f;

		g_size = 2;

		g_red = 1;
		g_green = 0;
		g_blue = 0;
		g_alpha = 1;
	}
	else if (type == OBJECT_ARROW)
	{

		g_vec_X = 100.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);
		g_vec_Y = 100.f *(((float)std::rand() / (float)RAND_MAX) - 0.5f);

		g_status = 1;
		g_life = 10;
		g_lifeTime = 100000.f;

		g_size = 2;

		g_red = 0;
		g_green = 1;
		g_blue = 0;
		g_alpha = 1;
	}
}


Object::~Object()
{

}

void Object::Update(float elapsedTime)
{
	float elapsedTimeSec = elapsedTime / 10.0;
	g_x = g_x + g_vec_X * elapsedTimeSec;
	g_y = g_y + g_vec_Y * elapsedTimeSec;

	if (g_x > 250)
		g_vec_X *= -1;
	else if (g_x < -250)
		g_vec_X *= -1;
	if (g_y > 250)
		g_vec_Y *= -1;
	else if (g_y < -250)
		g_vec_Y *= -1;

	if (g_life > 0.0)
	{
		g_life -= 0.1;
		cout << g_life << endl;
	}
	if (g_life <= 0.0)
	{
		g_status = 0;
	}
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