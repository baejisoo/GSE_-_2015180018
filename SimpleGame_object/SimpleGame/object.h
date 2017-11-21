#pragma once
class Object
{
public:
	Object(float x, float y, int type, int team);
	~Object();

	float GetLife();
	float GetLifeTime();
	

	void SetDamage(int damage);
	void CreateChar(float elapsedTime);
	void Update(float elapsedTime);
	void MouseSetObject(float x, float y);

	float g_team;
	float g_x;
	float g_y;
	float g_vec_X;
	float g_vec_Y;

	float g_life;
	float g_lifeTime;

	float g_fireTime;
	float g_createTime;

	int g_type;
	float g_status;
	float g_size;
	float g_red, g_green, g_blue, g_alpha;
};

