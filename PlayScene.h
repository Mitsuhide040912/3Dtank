#pragma once
#include "Engine/GameObject.h"

class Tank;
class Text;

class PlayScene :
    public GameObject
{
    Text* pText;
    Tank* player;
    int hModel_;
    int enemyNum;
public:
    PlayScene(GameObject* parent);
    ~PlayScene();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;


    //ƒCƒ“ƒ‰ƒCƒ“’è‹`
    void DescEnemy() { enemyNum--; }
    bool IsEnmeyLeft() { return enemyNum > 0; }
    int GetEnemyNum() { return enemyNum; }
};

