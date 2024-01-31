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
	 const int STAGE_X = 15;
	const int STAGE_Y = 15;
	int STAGE_MAP[STAGE_Y][STAGE_X] = 
	{ {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };
	
	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			Transform floorTrans;
			//Transform wallTrans;
			floorTrans.position_ = { -6.5f+1.0f*(float)x,0,-5+1.0f*(float)y };
			Model::SetTransform(hFloor_, floorTrans);
			Model::SetTransform(hWall_, floorTrans);
			if (STAGE_MAP[y][x] == 0)
			{
				Model::Draw(hFloor_);
			}
			else
			{
				Model::Draw(hWall_);
			}
		}
	}
}

void Stage::Release()
{
}
