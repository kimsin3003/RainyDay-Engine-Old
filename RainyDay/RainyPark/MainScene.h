#pragma once
#include "Scene.h"

class MainScene : public Scene
{
public:
	MainScene();
	~MainScene();

	virtual void Start(Camera& camera) override;


	virtual bool Update(float dt, InputClass& input, Camera& camera) override;


	virtual void UpdateUIString(Camera& camera) override;


	virtual void ShutDown() override;

};

