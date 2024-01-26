#pragma once
#include "Engine/GameObject.h"

class PlayScene;


class Bullet :
    public GameObject
{
    int hModel_;
    XMFLOAT3 moveDir_;//Œü‚«‚ÌƒxƒNƒgƒ‹
    float bulletSpeed_;
    //int speed_;
    PlayScene* playScene_;
public:
    Bullet(GameObject* parent);
    ~Bullet();

    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
    void SetSpeed(float _speed) { bulletSpeed_ = _speed; }
    void OnCollision(GameObject* pTarget)override;
};

