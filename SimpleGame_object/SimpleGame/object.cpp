#include <iostream>
#include "stdafx.h"

class Object
{
public:
	Object(float x, float y, float z, float size, float r, float g, float b, float a, int status);
	~Object();
private:
	void SetObjectPosition(float setX, float setY, float setZ, float setSize, float r, float g, float b, float a, int setStatus);
	void CreateObject(float x, float y, float z, float size, float r, float g, float b, float a, int status);

};

Object::~Object() {

}

void Object::SetObjectPosition(float setX, float setY, float setZ, float setSize, float r, float g, float b, float a, int setStatus) {

}
void Object::CreateObject(float x, float y, float z, float size, float r, float g, float b, float a, int status) {

}