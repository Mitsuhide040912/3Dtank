#pragma once
#include "Engine/GameObject.h"
class Tank :
    public GameObject
{
    int hModel_;
    XMVECTOR float_;
    float speed_;
    XMFLOAT3 f;
    XMVECTOR v = XMLoadFloat3(&f);
public:

    Tank(GameObject* parent);
    ~Tank();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
};

