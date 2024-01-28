#include "TitleScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),hPict_(-1)
{
}

TitleScene::~TitleScene()
{
	//‰½‚à‚È‚µ
}

void TitleScene::Initialize()
{
	hPict_ = Image::Load("Model\\TITLE.png");
	assert(hPict_ >= 0);
}

void TitleScene::Update()
{
	if (Input::IsKey(DIK_S))
	{
		SceneManager* pS = (SceneManager*)FindObject("SceneManager");
		pS->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void TitleScene::Release()
{
}
