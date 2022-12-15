#pragma once

#include "Argus.h"

class ExampleLayer : public Argus::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Argus::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Argus::Event& e) override;

private:
	Argus::ShaderLibrary m_ShaderLibrary;
	Argus::Ref<Argus::Shader> m_Shader;
	Argus::Ref<Argus::VertexArray> m_VertexArray;

	Argus::Ref<Argus::Shader> m_FlatColorShader;
	Argus::Ref<Argus::VertexArray> m_SquareVA;

	Argus::Ref<Argus::Texture2D> m_Texture, m_ChernoLogoTexture;

	Argus::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};