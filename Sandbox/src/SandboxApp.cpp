#include <Argus.h>
#include <Argus/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Sandbox2D.h"

class ExampleLayer : public Argus::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f, true)
	{
		///  TRIANGLE

		m_VertexArray = Argus::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Argus::Ref<Argus::VertexBuffer> vertexBuffer = Argus::VertexBuffer::Create(vertices, sizeof(vertices));
		Argus::BufferLayout layout = {
			{ Argus::ShaderDataType::Float3, "a_Position" },
			{ Argus::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Argus::Ref<Argus::IndexBuffer> indexBuffer = Argus::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA = Argus::VertexArray::Create();

		///  SQUARE

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			+0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			+0.5f, +0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f, +0.5f, 0.0f, 0.0f, 1.0f
		};

		Argus::Ref<Argus::VertexBuffer> squareVB = Argus::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		squareVB->SetLayout({
			{ Argus::ShaderDataType::Float3, "a_Position" },
			{ Argus::ShaderDataType::Float2, "a_TexCoord" }
		});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Argus::Ref<Argus::IndexBuffer> squareIB = Argus::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;
			
			void main()
			{
				color = vec4(v_Position + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader = Argus::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			
			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			
			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader = Argus::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Argus::Texture2D::Create("assets/textures/Checkerboard.png");

		std::dynamic_pointer_cast<Argus::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Argus::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}


	void OnUpdate(Argus::Timestep ts) override
	{
		//AS_TRACE("Delta time: {0}s ({1}ms)", ts.GetSeconds(), ts.GetMilliseconds());
		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		Argus::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Argus::RenderCommand::Clear();

		Argus::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Argus::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Argus::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Argus::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");
		m_Texture->Bind();
		Argus::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		//Argus::Renderer::Submit(m_Shader, m_VertexArray);

		Argus::Renderer::EndScene();
	}
	
	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Argus::Event& e) override
	{
		m_CameraController.OnEvent(e);
	} 

private:
	Argus::ShaderLibrary m_ShaderLibrary;
	Argus::Ref<Argus::Shader> m_Shader, m_FlatColorShader;

	Argus::Ref<Argus::VertexArray> m_VertexArray;
	Argus::Ref<Argus::IndexBuffer> m_IndexBuffer;

	Argus::Ref<Argus::VertexArray> m_SquareVA;
	Argus::Ref<Argus::Texture2D> m_Texture;

	Argus::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox : public Argus::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

Argus::Application* Argus::CreateApplication()
{
	return new Sandbox();
}