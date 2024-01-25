#include "PlayScene.h"
#include"Stage.h"
#include"Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Camera::SetPosition(XMFLOAT3(0,10,-10));
	Camera::SetTarget(XMFLOAT3(0, 0, 0));
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
