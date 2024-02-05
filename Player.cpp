#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"

namespace
{
	const float PLAYER_MOVE_SPEED{ 0.05 };
}
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1),speed_(PLAYER_MOVE_SPEED)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	XMVECTOR vFront{ 0,0,1,0 };
	XMVECTOR move{ 0,0,1,0 };
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
	pos = pos + speed_ * move;
	XMStoreFloat3(&(transform_.position_), pos);

	XMVECTOR vdot = XMVector3Dot(vFront, move);
	float angle = acos(XMVectorGetX(vdot));

	XMVECTOR vcross = XMVector3Cross(vFront, move);
	if (XMVectorGetY(vcross) < 0)
	{
		angle *= -1;
	}
	transform_.rotate_.y = XMConvertToDegrees(angle);
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
