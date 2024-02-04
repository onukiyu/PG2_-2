#include <Novice.h>
#include "Player.h"


Player::Player()
{
	transform_.x = 100;
	transform_.y = 100;
	speed_ = 5;
	radius_ = 30;
	isAlive_ = true;
	bullet_ = new Bullet;
}

//Player::Player()
//{

//}
void Player::Update(char* keys)
{
	if (keys[DIK_A])
	{
		transform_.x -= speed_;
	}

	if (keys[DIK_W])
	{
		transform_.y -= speed_;
	}

	if (keys[DIK_S])
	{
		transform_.y += speed_;
	}

	if (keys[DIK_D])
	{
		transform_.x += speed_;
	}

	if (keys[DIK_SPACE] && bullet_->isShot_ == 0)
	{
		bullet_->transform_.x = transform_.x;
		bullet_->transform_.y = transform_.y;
		bullet_->isShot_ = 1;
	}
	bullet_->Update();
}

void Player::Draw()
{
	if (isAlive_ == true) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
	
	Novice::DrawEllipse(bullet_->transform_.x, bullet_->transform_.y, bullet_->radius_, bullet_->radius_, 0.0f, WHITE, kFillModeSolid);
}