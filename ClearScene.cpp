#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

ClearScene::ClearScene(GameObject* parent)
	 :GameObject(parent,"ClearScene"),hModel_(-1)
{
}

ClearScene::~ClearScene()
{
	
}

void ClearScene::Initialize()
{
	hModel_ = Image::Load("Model\\CLEAR.png");
	assert(hModel_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_S))
	{
		SceneManager* pS = (SceneManager*)FindObject("SceneManager");
		pS->ChangeScene(SCENE_ID_TITLE);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hModel_, transform_);
	Image::Draw(hModel_);
}

void ClearScene::Release()
{
}
