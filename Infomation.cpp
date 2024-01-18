#include "Infomation.h"
#include "Engine/Image.h"
#include "Engine/Model.h"

Infomation::Infomation(GameObject* parent)
	:GameObject(parent,"Infomation"),hModel_(-1)
{
	
}

Infomation::~Infomation()
{
}

void Infomation::Initialize()
{
	/*hModel_ = Image::Load("Model\\info.png");
	assert(hModel_ >= 0);

	transform_.position_ = XMVectorSet(-0.75f, 0.8f,0,0);*/
}

void Infomation::Update()
{
}

void Infomation::Draw()
{
	Image::SetTransform(hModel_, transform_);
	Image::Draw(hModel_);
}

void Infomation::Release()
{
}
