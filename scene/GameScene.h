#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
// #include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

#include "AxisIndicator.h"
#include "DebugCamera.h"
#include "Camera.h"
#include "Ground.h"
#include "Player.h"
#include "Skydome.h"
#include <memory>

/// <summary>
/// ゲームシーン
/// </summary>

class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>

	// ビュープロジェクション
	ViewProjection viewProjection_;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	// モデルデータ
	std::unique_ptr<Model> modelFighter_;
	// 3Dモデル
	std::unique_ptr<Model> modelSkydome_;
	// 3Dモデル
	std::unique_ptr<Model> modelGround_;

	// クラス
	// std::unique_ptr<Model> model_;
	std::unique_ptr<Player> player_;
	std::unique_ptr<Ground> ground_;
	std::unique_ptr<Skydome> skydome_;

	// デバッグカメラ
	std::unique_ptr<DebugCamera> debugCamera_;
	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	// 追従カメラ
	std::unique_ptr<FollowCamera> followCamera_;
};