#include "rainyday.h"
#include "Shader.h"
#include <d3dcompiler.h>
#include <iostream>
#include "Effects\d3dx11effect.h"



Shader::Shader()
{
	ID3D10Blob* compiledShader = nullptr;
	ID3D10Blob* compilationMsgs = nullptr;
	DWORD shaderFlags = 0;

#if defined (DEBUG) || defined(_DEBUG)
	shaderFlags |= D3D10_SHADER_DEBUG;
	shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
#endif
	HRESULT hr = D3DCompileFromFile(
		L"MyShader.fx", 0, 0, //shader 파일 설정
		0, "fx_5_0", shaderFlags,
		0, &compiledShader,
		&compilationMsgs
	);

	if (FAILED(hr))
	{
		std::cout << "Shader Compile Error" << std::endl;
		return;
	}

	hr = D3DX11CreateEffectFromMemory(
		compiledShader->GetBufferPointer(), compiledShader->GetBufferSize(), 0, m_device,
		&m_effect);


	if (FAILED(hr))
	{
		std::cout << "Effect Creation Error" << std::endl;
		return;
	}

	m_colorTech = m_effect->GetTechniqueByName("ColorTech");

	if (FAILED(hr))
		return;


	D3D11_INPUT_ELEMENT_DESC	layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	D3DX11_PASS_DESC passDesc;
	UINT numElements = ARRAYSIZE(layout);

	m_colorTech->GetPassByIndex(0)->GetDesc(&passDesc);

	hr = m_device->CreateInputLayout(
		layout,
		numElements,
		passDesc.pIAInputSignature,
		passDesc.IAInputSignatureSize,
		&m_inputLayout);

	if (FAILED(hr))
		return;
}


Shader::~Shader()
{
	delete m_effect;
	delete m_colorTech;
	delete m_samplerVariable;
	delete m_texDiffuse;
	delete m_wvp;
	delete m_world;
	delete m_lightDir;
	delete m_lightColor;
}
