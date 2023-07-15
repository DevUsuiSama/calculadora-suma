#include "CMyWinApp.hpp"

BOOL CMyWinApp::InitInstance()
{
	CMainFrame* pMainFrame = new CMainFrame();

	pMainFrame->ShowWindow(SW_SHOW);
	pMainFrame->UpdateWindow();
	m_pMainWnd = pMainFrame;
	return TRUE;
}