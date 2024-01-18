#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:
    int hModel_;
    XMFLOAT3 moveDir_;//向きのベクトル

public:

    TankHead(GameObject* parent);
    ~TankHead();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
    /// <summary>
    /// モデル番号を返す関数
    /// </summary>
    /// <returns>int hModel:モデル番号</returns>
    int GetModelHandle() { return hModel_; }

    
};

