#include "HUD.h"
#include "Engine/Image.h"
#include "PlayScene.h"
#include "Engine/Model.h"



HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hHUD_(-1)
{
}

void HUD::Initialize()
{
	hHUD_ = Image::Load("Image\\HUD.png");
	assert(hHUD_ >= 0);
	//hNumber_ = Image::Load("image\\number1.png");
	//assert(hNumber_ >= 0);
}

void HUD::Update()
{
	tHud_.scale_ = { 1.0,1.0,0.5 };
	tHud_.position_ = { -0.6,-0.85,0 };
}

string HUD::ConstructEnemyNumberString()
{
	int enemies = ((PlayScene*)GetParent())->GetEnemyNum();
	string enemyNumstr = std::to_string(enemies);
	return enemyNumstr;
}


void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	Transform trans;
	trans.scale_ = { 0.5,0.5,1.0 };
	trans.position_ = { -0.6, 0.855, 0 };

	//trans.position_ = { -0.57,0.855,0 };
	
}

void HUD::Release()
{
}
