#pragma once
#include "Model.h"
#include "Camera.h"

namespace RainyDay {
	class DLL_API UIModel : public Model
	{
	public:
		UIModel();
		virtual ~UIModel() override;

		void SetUIXY(float x, float y);
		float GetUIX();
		float GetUIY();

		void SetUIPosition(Camera& cam);
		void SetToNumber(int n);

		static const float LETTERWIDTH;
		static const float LETTERHEIGHT;

	protected:
		float m_uiPosx;
		float m_uiPosy;
		float m_height;
		float m_width;
	};

}