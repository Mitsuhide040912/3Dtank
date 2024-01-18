#pragma once
#include "Engine/GameObject.h"
#include "PlayScene.h"
class Enemy :
    public GameObject
{
    int hModel_;
    PlayScene* playScene_;
public:
    Enemy(GameObject* parent);
    
    ~Enemy();

    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void OnCollision(GameObject* pTarget);
};

