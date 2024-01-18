#pragma once
#include "Engine/GameObject.h"
class PlayScene :
    public GameObject
{
    int hModel_;
    int enemyNum;
public:
    PlayScene(GameObject* parent);
    ~PlayScene();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
};

