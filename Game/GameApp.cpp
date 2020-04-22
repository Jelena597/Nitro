#include "precomp.h"
#include "GameApp.h"

#include <Core/EntryPoint.h>

#include "CameraController.h"
#include "DebugController.h"
#include "PlayerController.h"
#include "TextureController.h"


void Nitro::GameApp::GameSpecificWindowData()
{
	Engine::WindowData windowData;
	windowData.m_Height = 720;
	windowData.m_Width = 1280;
	windowData.m_Title = "Nitro";
	SetWindowData(windowData);
}

bool Nitro::GameApp::GameSpecificInit()
{
#if _DEBUG
	m_DebugController = DebugController::Create();
	if (!m_DebugController->Init(m_EntityManager.get(), m_TextureManager.get(), 
	                             &m_WindowData, m_RenderSystem->GetRenderer()))
	{
		LOG_ERROR("Failed to initialize DebugController");
		return false;
	}
#endif

	m_TextureController = TextureController::Create();
	if (!m_TextureController->Init(m_RenderSystem->GetRenderer(), m_TextureManager.get(), "Resource"))
	{
		LOG_ERROR("Failed to initialize TextureController");
		return false;
	}
	
	m_CameraController = CameraController::Create();
	if (!m_CameraController->Init(m_EntityManager.get(), &m_WindowData))
	{
		LOG_ERROR("Failed to initialize CameraController");
		return false;
	}

	m_PlayerController = PlayerController::Create();
	if (!m_PlayerController->Init(m_EntityManager.get(), m_TextureManager.get()))
	{
		LOG_ERROR("Failed to initialize PlayerController");
		return false;
	}
	return true;
}

bool Nitro::GameApp::GameSpecificShutdown()
{
	return true;
}

void Nitro::GameApp::GameSpecificUpdate(float dt)
{
	m_DebugController->Update(dt, m_EntityManager.get());
	m_PlayerController->Update(dt, m_EntityManager.get());
	m_CameraController->Update(dt, m_EntityManager.get());
}