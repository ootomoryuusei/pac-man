#include "TitleScene.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"

//コンストラクタ
TitleScene::TitleScene(GameObject * parent)
	: GameObject(parent, "TitleScene"),hPict_(-1)
{
}

//初期化
void TitleScene::Initialize()
{
	hPict_ = Image::Load("title.png");
	assert(hPict_ >= 0);
}

//更新
void TitleScene::Update()
{
	if (Input::IsMouseButtonUp(0))
	{
		SceneManager* tSM = (SceneManager*)(FindObject("SceneManager"));
		tSM->ChangeScene(SCENE_ID_PLAY);
	}
}

//描画
void TitleScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//開放
void TitleScene::Release()
{
}
