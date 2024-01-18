#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Ground.h"
#include "TankHead.h"
#include "Engine/Camera.h"
#include "Engine/Debug.h"

//カメラの指定
enum CAM_TYPE
{
	FIXED_TYPE, //固定の視点
	TPS_NORT_TYPE,//三人称回転なし
	TPS_TYPE,//三人称回転あり
	FPS_TYPE,//一人称
	MAX_TYPE//ここ、空出来たら終わり
};

Tank::Tank(GameObject* parent)
	:GameObject(parent,"Tank"),hModel_(-1),
	speed_(0.05),front_({0,0,1,0}),camState_(CAM_TYPE::FIXED_TYPE)
{
}

Tank::~Tank()
{
}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\TankBody.fbx");
	assert(hModel_ >= 0);
	speed_ = 0.05;
	float_ = XMVECTOR({ 0,0,1,0 });

	Instantiate<TankHead>(this);//親子関係
}


void Tank::Update()
{
	XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	XMVECTOR move{ 0,0,0,0 };
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	//前進
	if (Input::IsKey(DIK_W))
	{
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		XMVECTOR rotVec = XMVector3TransformCoord(float_, rotY);

		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_),pos);
	}
	//後退
	if (Input::IsKey(DIK_S))
	{
		XMMATRIX rotY = XMMatrixIdentity();
		XMVECTOR rotVec = XMVector3TransformCoord(float_, rotY);

		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - move;
		XMStoreFloat3(&(transform_.position_), pos);
	}

#if 1
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 2.0f;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 2.0f;
	}
#endif

	//回転行列
	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	//ベクトルの回転結果
	rotVec = XMVector3TransformCoord(front_, rotY);
	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + dir * move;
	XMStoreFloat3(&(transform_.position_), pos);

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;
	}

	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		if (camState_ == CAM_TYPE::MAX_TYPE)camState_ = CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE://固定
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}

	case CAM_TYPE::TPS_NORT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 15.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}

	case CAM_TYPE::TPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{ 0,5,-10,0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}

	case CAM_TYPE::FPS_TYPE:
	{
		Camera::SetPosition(transform_.position_);
		XMFLOAT3 camTarget;

		XMStoreFloat3(&camTarget, pos + move);
		Camera::SetTarget(camTarget);
		break;
	}

	}

}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}
