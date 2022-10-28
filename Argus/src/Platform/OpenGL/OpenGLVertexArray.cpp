#include "aspch.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"
#include <glad/glad.h>

namespace Argus
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Argus::ShaderDataType::Float:		return GL_FLOAT;
		case Argus::ShaderDataType::Float2:		return GL_FLOAT;
		case Argus::ShaderDataType::Float3:		return GL_FLOAT;
		case Argus::ShaderDataType::Float4:		return GL_FLOAT;
		case Argus::ShaderDataType::Mat3:		return GL_FLOAT;
		case Argus::ShaderDataType::Mat4:		return GL_FLOAT;
		case Argus::ShaderDataType::Int:		return GL_INT;
		case Argus::ShaderDataType::Int2:		return GL_INT;
		case Argus::ShaderDataType::Int3:		return GL_INT;
		case Argus::ShaderDataType::Int4:		return GL_INT;
		case Argus::ShaderDataType::Bool:		return GL_BOOL;
		}
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		AS_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		AS_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		AS_PROFILE_FUNCTION();
		
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		AS_PROFILE_FUNCTION();
		
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		AS_PROFILE_FUNCTION();
		
		AS_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		AS_PROFILE_FUNCTION();
		
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}
}