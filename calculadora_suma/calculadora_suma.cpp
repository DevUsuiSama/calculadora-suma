/*
 * Created on Fri Jul 07 2023
 *
 * Copyright (c) 2023 UsuiSama
 */
#include "stdafx.hpp"
#include "CMainFrame.hpp"

class CMyCalculadoraSuma : public CWinApp
{
public:
	BOOL InitInstance()
	{
		CMainFrame* pMainFrame = new CMainFrame();

		pMainFrame->ShowWindow(SW_SHOW);
		pMainFrame->UpdateWindow();
		m_pMainWnd = pMainFrame;
		return TRUE;
	}
} myCalculadoraSuma;