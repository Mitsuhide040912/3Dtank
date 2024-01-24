#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
private:
    int hModel_;
    XMFLOAT3 moveDir_;//�����̃x�N�g��

public:

    TankHead(GameObject* parent);
    ~TankHead();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
    /// <summary>
    /// ���f���ԍ���Ԃ��֐�
    /// </summary>
    /// <returns>int hModel:���f���ԍ�</returns>
    int GetModelHandle() { return hModel_; }

    
};

