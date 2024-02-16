#include "GameOver.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"GameOver"),hPict_(-1)
{
}

void GameOverScene::Initialize()
{
	hPict_ = Image::Load("gameover.png");
	assert(hPict_ >= 0);
}

void GameOverScene::Update()
{
	if (Input::IsMouseButtonUp(0))
	{
		SceneManager* gSM = (SceneManager*)(FindObject("SceneManager"));
		gSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void GameOverScene::Release()
{
}
