#pragma once
#include "Engine/GameObject.h"
class Infomation :
    public GameObject
{
	int hModel_;
public:
    Infomation(GameObject* parent);
    ~Infomation();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

