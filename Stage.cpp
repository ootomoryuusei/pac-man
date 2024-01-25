#include "Stage.h"
#include"Engine/Model.h"


Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hFloor_(-1),hWall_(-1)
{
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Model\\Floor.fbx");
	assert(hFloor_ >= 0);
	hWall_ = Model::Load("Model\\Wall.fbx");
	assert(hWall_ >= 0);
}

void Stage::Update()
{
}

void Stage::Draw()
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			Transform floorTrans;
			//Transform wallTrans;
			floorTrans.position_ = { -6.5f+1.0f*(float)x,0,-5+1.0f*(float)y };
			Model::SetTransform(hFloor_, floorTrans);
			Model::SetTransform(hWall_, floorTrans);
			Model::Draw(hFloor_);
			if (x == 0 || x == 14 || y == 0 || y == 14)
			{
				Model::Draw(hWall_);
			}
		}
	}
}

void Stage::Release()
{
}
