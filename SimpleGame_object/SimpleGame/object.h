#pragma once

class Object
{

public:
	float x, y, z, size, r, g, b, a, status, speed;

	Object(float x, float y, float z, float size, float r, float g, float b, float a, float status, float speed);
	~Object();
	void SetObjectPosition(float setX, float setY, float setZ, float setSize, float r, float g, float b, float a, float setStatus, float setSpeed);
	void UpdateObject(float setX, float setY, float setZ, float setSize, float setStatus, float setSpeed);
	void CreateObject(float setX, float setY, float setZ, float setSize, float red, float green, float blue, float alpha, float setStatus, float setSpeed);

	float getX();
	float getY();
	float getZ();
	float getSize();
	float getR();
	float getG();
	float getB();
	float getA();
	float getStatus();
	float getSpeed();
};