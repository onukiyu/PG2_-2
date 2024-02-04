#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1C_08_オオヌキユウ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	//弾と敵の当たり判定
	float bulletD = 0.0f;
	float bulletR = 0.0f;

	//自機と敵の当たり判定
	float playerD = 0.0f;
	float playerR = 0.0f;

	Player* player = new Player();

	Enemy* enemy = new Enemy();

	enemy->Initalize();

	int scene = 0;
	enum Scene
	{
		TITLE,
		GAME
	};

	//Scene scene = TITLE;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		switch (scene)
		{
		case TITLE:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				scene = GAME;
				break;
			}

		case GAME:

			player->Update(keys);

			enemy->Update();

			bulletD = float((enemy->GetposX() - player->bullet_->transform_.x) * (enemy->GetposX() - player->bullet_->transform_.x) + (enemy->GetposY() - player->bullet_->transform_.y) * (enemy->GetposY() - player->bullet_->transform_.y));

			bulletR = float((enemy->Getradius() + player->bullet_->radius_) * (enemy->Getradius() + player->bullet_->radius_));

			playerD = float((enemy->GetposX() - player->GetposX()) * (enemy->GetposX() - player->GetposX()) + (enemy->GetposY() - player->GetposY()) * (enemy->GetposY() - player->GetposY()));

			playerR = float((enemy->Getradius() + player->Getradius() * (enemy->Getradius() + player->Getradius())));

			if (bulletD <= bulletR) {
				enemy->SetisAlive(false);
			}

			if (playerD <= playerR) {
				player->SetisAlive(false);
			}

			if (keys[DIK_R] && preKeys[DIK_R] == 0)
			{
				scene = TITLE;
				break;
			}
			
		}

		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		

		switch (scene)
		{
		case TITLE:
			Novice::ScreenPrintf(600, 360, "SPACE GAME START");
			break;

		case GAME:
			Novice::ScreenPrintf(10, 10, "R:title");
			player->Draw();

			enemy->Draw();

			break;
		}
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	delete player;
	return 0;
}