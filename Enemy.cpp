#include <Novice.h>
#include "Enemy.h"

void Enemy ::Initalize() {
	//初期化処理
	transform_.x = 300;
	transform_.y = 300;
	speed_ = 5;
	radius_ = 30;
	timer_ = 60;
	isAlive_ = true;
}


void Enemy::Update() {
	//更新処理
	if (isAlive_ == true) {
		transform_.x += speed_;
		if (transform_.x >= 1280) {
			speed_ *= -1;
		}
		if (transform_.x <= 0) {
			speed_ *= -1;
		}
	}
	if (isAlive_ == false) {
		timer_ -= 1;
	}
	if (timer_ <= 0) {
		isAlive_ = true;
		timer_ = 60;
	}
}


void Enemy::Draw() {
	//描画処理
	if (isAlive_ == true) {
		Novice::DrawEllipse(transform_.x, transform_.y, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
	}
	
}