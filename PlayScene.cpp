#include "PlayScene.h"
#include "Engine/SceneManager.h"
#include "Ground.h"
#include "TankHead.h"
#include "Tank.h"
#include "Enemy.h"
#include "HUD.h"
#include "Infomation.h"
#include "Engine/Text.h"
#include "Engine/Camera.h"

namespace
{
	const int ENEMY_NUM{ 30 };
}



PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PLAY_SCENE"),hModel_(-1)
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
	enemyNum = ENEMY_NUM;

	for (int i = 0; i < enemyNum; i++)
	     Instantiate<Enemy>(this);
	//pText = new Text;
	//pText->Initialize();
	//Instantiate<Infomation>(this);

	/*for(int i=0;i<enemyNum; i++)
	Instantiate<Enemy>(this);*/
	Instantiate<HUD>(this);
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
	//pText->Draw(30, 30, "Mitsuhide");
}

void PlayScene::Release()
{
}
