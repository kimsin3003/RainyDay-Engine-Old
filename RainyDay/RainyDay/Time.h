#pragma once

#include <Windows.h>

namespace RainyDay {
	class DLL_API Time
	{
		bool		m_bUseQPF;
		float		m_fElapsedTime;
		LONGLONG	m_llQPFTicksPerSec;
		LONGLONG	m_llLastElapsedTime;
	public:
		Time(void);
		virtual ~Time(void);

		inline float GetElapsedTime() const
		{
			return m_fElapsedTime;
		};

		void Init();
		void ProcessTime();
	};
}