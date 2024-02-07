#pragma once
#include "Engine/GameObject.h"
#include<vector>

using std::vector;

enum STAGE_OBJ
{
	FLOOR,
	WALL,
};
//�e�X�g�V�[�����Ǘ�����N���X
class Stage : public GameObject
{
	int hFloor_;
	int hWall_;
	int stageWidth_;
	int	stageHeight_;
	vector<vector<int>> stageData_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	bool IsWall(int _x, int _y);

	int GetStageWidth() { return stageWidth_; }
	int GetStageHight() { return stageHeight_; }
};