#pragma once
class Shader
{
public:
	Shader();
	~Shader();

	

private:
	ID3DX11Effect*									m_effect = nullptr;
	ID3DX11EffectTechnique*							m_colorTech = nullptr;
	
	D3DX11_PASS_DESC m_passDesc;
};

