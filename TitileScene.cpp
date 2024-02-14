#include "TitleScene.h"
#include"Engine/Image.h"

//�R���X�g���N�^
TitleScene::TitleScene(GameObject * parent)
	: GameObject(parent, "TitleScene"),hPict_(-1)
{
}

//������
void TitleScene::Initialize()
{
	hPict_ = Image::Load("title.png");
	assert(hPict_ >= 0);
}

//�X�V
void TitleScene::Update()
{
}

//�`��
void TitleScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void TitleScene::Release()
{
}
