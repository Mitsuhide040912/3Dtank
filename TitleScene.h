#pragma once
#include "Engine/GameObject.h"
class TitleScene :
    public GameObject
{
public:
    TitleScene(GameObject* parent);
    int hPict_;
    ~TitleScene();

    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
};

