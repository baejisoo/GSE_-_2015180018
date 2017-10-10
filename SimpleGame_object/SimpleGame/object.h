#pragma once

class Object
{

public:
	float x, y, z, size, r, g, b, a, status;

	Object(float x, float y, float z, float size, float r, float g, float b, float a, float status);
	~Object();
	void SetObjectPosition(float setX, float setY, float setZ, float setSize, float r, float g, float b, float a, float setStatus);
	//void CreateObject(float x, float y, float z, float size, float r, float g, float b, float a, int status);
	float getX();
	float getY();
	float getZ();
	float getSize();
	float getR();
	float getG();
	float getB();
	float getA();
};