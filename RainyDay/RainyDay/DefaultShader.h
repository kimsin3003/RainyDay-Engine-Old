#pragma once
#include "Shader.h"

namespace RainyDay {
	class DefaultShader :
		public Shader
	{
	public:
		DefaultShader();
		~DefaultShader();
		virtual void Reset(ID3D11Device* device, ID3D11DeviceContext* immediateContext);
	};
}