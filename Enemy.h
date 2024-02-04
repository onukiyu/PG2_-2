#pragma once
#include "Struct.h"
class Enemy
{
private://メンバ変数
	Transform transform_;
	int radius_;
	int speed_;
	int timer_;
	bool isAlive_;
public://メンバ関数
	///<summary>
	///初期化状態
	/// </summary>
	void Initalize();//初期化
	

	void Update();

	void Draw();

	int Getradius() { return radius_; }
	int GetposX() { return transform_.x; }
	int GetposY() { return transform_.y; }
	int Gettimer() { return timer_; }


	void SetisAlive(bool isAlive) { isAlive_ = isAlive; }
};

