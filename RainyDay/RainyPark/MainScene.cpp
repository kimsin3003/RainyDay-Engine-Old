#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

void MainScene::Start(Camera& camera)
{
	SystemClass::GetInstance()->SetLightDirection(XMFLOAT4(-1, -1, 1, 1));
	camera.SetCameraPos(10, 10, 10);
	camera.SetCameraTarget(0, 0, 0);
	Model* cube = new Model();
	cube->SetColor(1, 0, 0, 1);
	cube->SetToCube(XMFLOAT3(10, 10, 10));
	cube->SetPosition(XMFLOAT3(0, 0, 0));
	
	AddModel(cube);
}

bool MainScene::Update(float dt, InputClass& input, Camera& camera)
{
	return true;
}

void MainScene::UpdateUIString(Camera& camera)
{

}

void MainScene::ShutDown()
{

}
