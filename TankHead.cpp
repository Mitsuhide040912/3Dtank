#include "TankHead.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
#include "Engine/Camera.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("Model\\tankHead2.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.y -= 2.0;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.y += 2.0;
	}

	if (Input::IsKeyDown(DIK_F))
	{
		XMFLOAT3 cannonTopPos = Model::GetBonePosition(hModel_, "CannonPos");
		XMFLOAT3 cannonRootPos = Model::GetBonePosition(hModel_, "CannonRoot");
		/*XMFLOAT3 joint1 = Model::GetBonePosition(hModel_, "joint1");
		XMFLOAT3 joint2 = Model::GetBonePosition(hModel_, "joint2");*/

		XMVECTOR vtop = XMLoadFloat3(&cannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&cannonRootPos);
		/*XMVECTOR vtop = XMLoadFloat3(&joint1);
		XMVECTOR vroot = XMLoadFloat3(&joint2);*/
        XMVECTOR moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);
		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);


		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(cannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpeed(0.3);
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
