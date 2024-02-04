#pragma once
#include "Struct.h"
#include "Bullet.h"

class Player
{
private:

	Transform transform_;

	

	int radius_;
	int speed_;
	bool isAlive_;
public:
	Player();
	Bullet* bullet_;

	void Update(char* keys);

	void Draw();

	int Getradius() { return radius_; }
	int Getspeed() { return speed_; }
	int GetposX() { return transform_.x; }
	int GetposY() { return transform_.y; }

	void SetisAlive(bool isAlive) { isAlive_ = isAlive; }
};
