#include <iostream>
#include "stdafx.h"
#include "object.h"
using namespace std;

Object::~Object() {

}

Object::Object(float setX, float setY, float setZ, float setSize, float red, float green, float blue, float alpha, float setStatus, float speed) {
	SetObjectPosition(setX, setY, setZ, setSize, red,  green, blue, alpha, setStatus, speed);
}

void Object::SetObjectPosition(float setX, float setY, float setZ, float setSize, float red, float green, float blue, float alpha, float setStatus, float setSpeed) {
	x = setX;
	y = setY;
	z = setZ;
	size = setSize;
	r = red;
	g = green;
	b = blue;
	a = alpha;
	status = setStatus;
	speed = setSpeed;
}

void Object::UpdateObject(float setX, float setY, float setZ, float setSize, float setStatus, float setSpeed)
{
	if (x < 250)
	{
		x = setX + setSpeed;
	}
	//y = setY + setSpeed;
	//z = setZ + setSpeed;
}

void Object::CreateObject(float setX, float setY, float setZ, float setSize, float red, float green, float blue, float alpha, float setStatus, float setSpeed) 
{
	x = setX;
	y = setY;
	z = setZ;
	size = setSize;
	r = red;
	g = green;
	b = blue;
	a = alpha;
	status = setStatus;
	speed = setSpeed;

}
float Object::getX(){
	return x;
}
float Object::getY() {
	return y;
}
float Object::getZ() {
	return z;
}
float Object::getSize() {
	return size;
}
float Object::getR() {
	return r;
}
float Object::getG() {
	return g;
}
float Object::getB() {
	return b;
}
float Object::getA() {
	return a;
}
float Object::getStatus() {
	return status;
}
float Object::getSpeed() {
	return speed;
}

