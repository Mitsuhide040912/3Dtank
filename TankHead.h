#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:
    int hModel_;

public:

    TankHead(GameObject* parent);
    ~TankHead();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
    /// <summary>
    /// ƒ‚ƒfƒ‹”Ô†‚ğ•Ô‚·ŠÖ”
    /// </summary>
    /// <returns>int hModel:ƒ‚ƒfƒ‹”Ô†</returns>
    int GetModelHandle() { return hModel_; }
};

