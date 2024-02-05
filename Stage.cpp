#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/CsvReader.h"

//const int STAGE_X{ 15 };
//const int STAGE_Y{ 15 };
//const int STAGE_MAP[STAGE_X][STAGE_Y] = {
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//};

Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage"),hFloor_(-1),hWall_(-1)
{
	CsvReader csv;
	csv.Load("map.csv");
	int STAGE_X = csv.GetWidth();
	int STAGE_Y = csv.GetHeight();

	for (int y = 0; y < STAGE_Y; y++)
	{
		vector<int> sdata(STAGE_X, 0);
		stageData_.push_back(sdata);
	}
	for (int y = 0; y < STAGE_X; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			stageData_[y][x] = csv.GetValue(x, y);
		}
	}
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
			if(stageData_[y][x] == 0)
			{
			   floorTrans.position_ = { -6.5f+1.0f*(float)x,0,-5+1.0f*(float)y };
			   Model::SetTransform(hFloor_, floorTrans);
			   Model::Draw(hFloor_);
			}
			else
			{
				floorTrans.position_ = { -6.5f + 1.0f * (float)x,0,-5 + 1.0f * (float)y };
				Model::SetTransform(hWall_, floorTrans);
				Model::Draw(hWall_);
			}
		}
	}
}

void Stage::Release()
{
}
