#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet()
{
	transform_.x = 100;
	transform_.y = 100;
	speed_ = 10;
	radius_ = 10;
	isShot_ = 0;
}

void Bullet::Update()
{
	if (isShot_ == 1)
	{
		transform_.y -= speed_;
		if (transform_.y <= -10)
		{
			isShot_ = 0;
		}
	}
}

void Bullet::Draw()
{
	if (isShot_ == 1)
	{
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}