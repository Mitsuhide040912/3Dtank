#pragma once
#include "Engine/GameObject.h"
class Infomation :
    public GameObject
{
	int hModel_;
public:
    Infomation(GameObject* parent);
    ~Infomation();
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

