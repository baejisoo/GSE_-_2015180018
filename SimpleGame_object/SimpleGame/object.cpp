#include <iostream>
#include "stdafx.h"
#include "object.h"

Object::~Object() {

}

Object::Object(float setX, float setY, float setZ, float setSize, float red, float green, float blue, float alpha, float setStatus) {
	SetObjectPosition(setX, setY, setZ, setSize, red,  green, blue, alpha, setStatus);
}

void Object::SetObjectPosition(float setX, float setY, float setZ, float setSize, float red, float green, float blue, float alpha, float setStatus) {
	x = setX;
	y = setY;
	z = setZ;
	size = setSize;
	r = red;
	g = green;
	b = blue;
	a = alpha;
	status = setStatus;

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
//void Object::CreateObject(float x, float y, float z, float size, float r, float g, float b, float a, int status) {

//}