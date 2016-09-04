#pragma once
#include <d3dcompiler.h>
#include <iostream>
#include "Effects\d3dx11effect.h"

namespace RainyDay
{
	class DLL_API Shader
	{
	public:
		virtual ~Shader();
		virtual void Reset(ID3D11Device* device, ID3D11DeviceContext* immediateContext) = 0;
		inline ID3DX11Effect* GetEffect() { return m_effect; };
		inline ID3DX11EffectTechnique* GetEffectTechnique() { return m_colorTech; };
		inline ID3DX11EffectSamplerVariable* GetSamplerVariable() { return m_samplerVariable; };
		inline ID3DX11EffectShaderResourceVariable* GetTexDiffuse() { return m_texDiffuse; };
		inline ID3DX11EffectMatrixVariable* GetWVPMatrix() { return m_wvp; };
		inline ID3DX11EffectMatrixVariable* GetWorldMatrix() { return m_world; };



	protected:
		ID3DX11Effect*									m_effect = nullptr;
		ID3DX11EffectTechnique*							m_colorTech = nullptr;

		ID3DX11EffectSamplerVariable*					m_samplerVariable = nullptr;
		ID3DX11EffectShaderResourceVariable*			m_texDiffuse = nullptr;
		ID3DX11EffectMatrixVariable*					m_wvp;
		ID3DX11EffectMatrixVariable*					m_world; 		
		ID3DX11EffectVectorVariable*					m_lightDir;
		ID3DX11EffectVectorVariable*					m_lightColor;

		D3DX11_PASS_DESC m_passDesc;
		ID3D10Blob* m_compiledShader = nullptr;
		ID3D11InputLayout*								m_inputLayout = nullptr;
	};
}
