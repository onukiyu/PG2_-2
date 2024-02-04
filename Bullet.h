#pragma once
#include "Struct.h"
class Bullet
{
public:

	Transform transform_;

	Bullet();

	int radius_;
	int speed_;
	int isShot_;

public:
	void Update();
	void Draw();
};
