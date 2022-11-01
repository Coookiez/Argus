#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <chrono>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}


void Sandbox2D::OnAttach()
{
	AS_PROFILE_FUNCTION();
	
	m_CheckerboardTexture = Argus::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	AS_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Argus::Timestep ts)
{
	AS_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		AS_PROFILE_SCOPE("Renderer Prep");
		Argus::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Argus::RenderCommand::Clear();
	}

	{
		AS_PROFILE_SCOPE("Renderer Draw");
		Argus::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Argus::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, glm::radians(-45.0f), { 0.8f, 0.2f, 0.3f, 1.0f });
		Argus::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Argus::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, glm::radians(80.0f), m_CheckerboardTexture, 10.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));
		Argus::Renderer2D::EndScene();
	}
}
void Sandbox2D::OnImGuiRender()
{
	AS_PROFILE_FUNCTION();
	
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Argus::Event& e)
{
	m_CameraController.OnEvent(e);
}