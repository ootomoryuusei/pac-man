#include "Stage.h"
#include"Engine/Model.h"
#include"Engine/CsvReader.h"
#include"Engine/Camera.h"
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
	csv.Load("map2.csv");
	stageWidth_ = csv.GetWidth();
	stageHeight_ = csv.GetHeight();

	for (int y = 0; y < stageHeight_; y++)
	{
		vector<int> sdata(stageWidth_, 0);
		stageData_.push_back(sdata);
	}
	for (int y = 0; y < stageHeight_; y++)
	{
		for (int x = 0; x < stageWidth_; x++)
		{
			stageData_[y][x] = csv.GetValue(x, y);
		}
	}

	for (int y = 0; y < stageHeight_; y++)
	{
		for (int x = 0; x < stageWidth_; x++)
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
	Camera::SetPosition({ 6.5, 10, -5 });
	Camera::SetTarget({ 6.5, 0, 5.5 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };
	for (int z = 0; z < stageHeight_; z++)
	{
		for (int x = 0; x < stageWidth_; x++)
		{
			floorTrans.position_ = { (float)x,0,(float)(14 - z) };
			if(stageData_[z][x] == 1)
			{
			  /* floorTrans.position_ = { -6.5f+1.0f*(float)x,0,-5+1.0f*(float)y };*/
			   Model::SetTransform(hWall_, floorTrans);
			   Model::Draw(hWall_);
			}
			else
			{
				/*floorTrans.position_ = { -6.5f + 1.0f * (float)x,0,-5 + 1.0f * (float)y };*/
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}
}

void Stage::Release()
{
	for (int i = 0; i < stageHeight_; i++)
	{
		stageData_[i].clear();
	}
	stageData_.clear();
}

bool Stage::IsWall(int _x, int _y)
{
	if (stageData_[_y][_x] == STAGE_OBJ::WALL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
