#include <iostream>
#include "stdafx.h"
#include "SceneMgr.h"
#include "object.h"
using namespace std;
#define MAX_OBJECTS_COUNT 10

SceneMgr::~SceneMgr() {

}

SceneMgr::SceneMgr() {
	Object *m_objects[MAX_OBJECTS_COUNT];
}