#pragma once
class Object
{
public:
	Object(float x, float y, int type);
	~Object();

	float GetLife();
	float GetLifeTime();
	
	void Update(float elapsedTime);
	void MouseSetObject(float x, float y);

	float g_x;
	float g_y;
	float g_vec_X;
	float g_vec_Y;

	float g_life;
	float g_lifeTime;

	int g_type;
	float g_status;
	float g_size;
	float g_red, g_green, g_blue, g_alpha;
};

