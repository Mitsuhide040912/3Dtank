#pragma once
#include "Engine/GameObject.h"
#include <vector>
#include<string>
using std::string;
class HUD :
    public GameObject
{
    string ConstructEnemyNumberString();
    int hUD_;
    int hNumber_;
public:
    HUD(GameObject* parent);
    int hHUD_;
    int hNumbers_;
    //int hkinoko_;
    Transform tHud_;
    std::vector<Transform>tNumbers_;

    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
};

