#include <iostream>
#include "stdafx.h"
class Object
{
public:
	Object(float x, float y, float z, float size, int status);
	~Object();
private:
	void SetObjectPosition(float setX, float setY, float setZ, float setSize, int setStatus);
	void CreateObject(float x, float y, float z, float size, int status);

};

Object::~Object() {

}

void Object::SetObjectPosition(float setX, float setY, float setZ, float setSize, int setStatus) {

}
void Object::CreateObject(float x, float y, float z, float size, int status) {

}