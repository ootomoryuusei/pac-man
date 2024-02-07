#pragma once
#include "Engine/GameObject.h"
#include"Stage.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Player : public GameObject
{
	int hModel_;
	float speed_;
	float aniframe_;
	Stage* pStage_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};