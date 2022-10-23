#pragma once

#include "Argus.h"

class Sandbox2D : public Argus::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Argus::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Argus::Event& e) override;

private:
	Argus::OrthographicCameraController m_CameraController;
	
	// Temporary
	Argus::Ref<Argus::VertexArray> m_SquareVA;
	Argus::Ref<Argus::Shader> m_FlatColorShader;

	Argus::Ref<Argus::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8, 1.0f };

};