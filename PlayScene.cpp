#include "PlayScene.h"
#include "Engine/SceneManager.h"
#include "Ground.h"
#include "TankHead.h"
#include "Tank.h"
#include "Enemy.h"

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
	Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
	enemyNum = ENEMY_NUM;
	for(int i=0;i<enemyNum; i++)
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
