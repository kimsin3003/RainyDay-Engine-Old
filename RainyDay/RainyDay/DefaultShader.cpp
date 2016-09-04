#include "rainyday.h"
#include "DefaultShader.h"
#include "UIModel.h"

namespace RainyDay {
	DefaultShader::DefaultShader()
	{
		ID3D10Blob* compilationMsgs = nullptr;
		DWORD shaderFlags = 0;

#if defined (DEBUG) || defined(_DEBUG)
		shaderFlags |= D3D10_SHADER_DEBUG;
		shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
#endif
		std::wstring fileName = L"DefaultShader.fx";
		std::string temp(__FILE__);
		std::wstring currentDir;
		currentDir.assign(temp.begin(), temp.end());
		std::wstring fileDir = currentDir + L"\\..\\" + fileName;
		HRESULT hr = D3DCompileFromFile(
			fileDir.c_str(), 0, 0, //shader 파일 설정
			0, "fx_5_0", shaderFlags,
			0, &m_compiledShader,
			&compilationMsgs
		);

		if (FAILED(hr))
		{
			std::cout << "Shader Compile Error" << std::endl;
			return;
		}

	}


	void DefaultShader::Reset(ID3D11Device* device, ID3D11DeviceContext* immediateContext)
	{

		if (m_effect != nullptr)
		{
			delete m_effect;
			m_effect = nullptr;
		}

		if (m_colorTech != nullptr)
		{
			delete m_colorTech;
			m_colorTech = nullptr;
		}

		if (m_inputLayout != nullptr)
		{
			delete m_inputLayout;
			m_inputLayout = nullptr;
		}

		HRESULT hr = D3DX11CreateEffectFromMemory(
			m_compiledShader->GetBufferPointer(), m_compiledShader->GetBufferSize(), 0, device,
			&m_effect);


		if (FAILED(hr))
		{
			std::cout << "Effect Creation Error" << std::endl;
			return;
		}

		m_colorTech = m_effect->GetTechniqueByName("ColorTech");

		m_wvp = m_effect->GetVariableByName("wvp")->AsMatrix();
		m_world = m_effect->GetVariableByName("world")->AsMatrix();
		m_lightDir = m_effect->GetVariableByName("lightDir")->AsVector();
		m_lightColor = m_effect->GetVariableByName("lightColor")->AsVector();
		m_texDiffuse = m_effect->GetVariableByName("texDiffuse")->AsShaderResource();
		m_samplerVariable = m_effect->GetVariableByName("samLinear")->AsSampler();
		//빛 계산

		XMFLOAT4 lightDirection = { -0.3f, -1.0f, -0.2f, 1.0f };
		XMFLOAT4 lightColor = { 1.0f, 1.0f, 1.0f, 1.0f };
		m_lightDir->SetFloatVector((float*)&lightDirection);
		m_lightColor->SetFloatVector((float*)&m_lightColor);

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
		hr = device->CreateInputLayout(
			layout,
			numElements,
			passDesc.pIAInputSignature,
			passDesc.IAInputSignatureSize,
			&m_inputLayout);

		if (FAILED(hr))
			return;


		//if(model.GetTransparency() > 0)
			m_colorTech->GetPassByIndex(0)->Apply(0, immediateContext);
// 		else
// 		{
// 			if (model.IsUI())
// 				m_colorTech->GetPassByIndex(2)->Apply(0, immediateContext);
// 			else
// 				m_colorTech->GetPassByIndex(0)->Apply(0, immediateContext);
// 		}
	}



	DefaultShader::~DefaultShader()
	{
		delete m_effect;
		delete m_colorTech;
		delete m_compiledShader;
		delete m_inputLayout;
	}
}
