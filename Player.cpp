#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Stage.h"

namespace
{
	const float PLAYER_MOVE_SPEED{ 0.05 };
}
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), speed_(PLAYER_MOVE_SPEED), pStage_(nullptr), aniframe_(10)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage*)FindObject("Stage");
}

void Player::Update()
{
	XMVECTOR vFront{ 0,0,1,0 };
	XMVECTOR move{ 0,0,0,0 };
	if (Input::IsKey(DIK_W))
	{
		move = XMVECTOR{ 0,0,1,0 };
	}
	if (Input::IsKey(DIK_S))
	{
		move = XMVECTOR{ 0,0,-1,0 };
	}
	if (Input::IsKey(DIK_A))
	{
		move = XMVECTOR{ -1,0,0,0 };
	}
	if (Input::IsKey(DIK_D))
	{
		move = XMVECTOR{ 1,0,0,0 };
	}

	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	/*pos = pos + speed_ * move;*/
	XMVECTOR posTmp = XMVectorZero();
	posTmp = pos + speed_ * move;

	int tx, ty;
	tx = (int)(XMVectorGetX(posTmp) + 1.0f);
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(posTmp) + 1.0f);
	if (!(pStage_->IsWall(tx, ty)))
	{
		pos = posTmp;
	}
	/*XMStoreFloat3(&(transform_.position_), pos);*/
	if (!XMVector3Equal(move, XMVectorZero()))
	{
		XMStoreFloat3(&(transform_.position_), pos);
		XMMATRIX rot = XMMatrixRotationY(XM_PIDIV2);
		XMVECTOR modifiedVec = XMVector3TransformCoord(move, rot);

		Debug::Log(XMVectorGetX(modifiedVec));
		Debug::Log(",");
		Debug::Log(XMVectorGetZ(modifiedVec));

		float angle = atan2(XMVectorGetZ(modifiedVec), XMVectorGetX(modifiedVec));

		Debug::Log(" => ");
		Debug::Log(XMConvertToDegrees(angle), true);

		/*XMVECTOR vdot = XMVector3Dot(vFront, move);
		assert(XMVectorGetX(vdot) <=1 && XMVectorGetX(vdot) >=-1);
		float angle = acos(XMVectorGetX(vdot));

		XMVECTOR vcross = XMVector3Cross(vFront, move);
		if (XMVectorGetY(vcross) < 0)
		{
			angle *= -1;
		}*/
			transform_.rotate_.y = XMConvertToDegrees(-angle);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
