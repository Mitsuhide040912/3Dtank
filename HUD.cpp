#include "HUD.h"
#include "Engine/Image.h"

string HUD::ConstructEnemyNumberString()
{
	return string();
}

HUD::HUD(GameObject* parent)
	:GameObject(parent,"HUD"),hUD_(-1),hNumber_(-1)
{
}

void HUD::Initialize()
{
	/*hUD_ = Image::Load("Image::cou.png");
	assert(hUD_ >= 0);
	hNumber_ = Image::Load("image\\number1.png");
	assert(hNumber_ >= 0);*/
}

void HUD::Update()
{
}

void HUD::Draw()
{
	
}

void HUD::Release()
{
}
