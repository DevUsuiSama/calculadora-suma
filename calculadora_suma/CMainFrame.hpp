/*
 * Created on Fri Jul 07 2023
 *
 * Copyright (c) 2023 UsuiSama
 */
#pragma once

#include "CDrawUtil.hpp"
#include "CEditCustom.hpp"

class CMainFrame : public CFrameWnd
{
private:
	CStatic resultado;
	CButton btnSumar;
	CEditCustom edit1;
	CEditCustom edit2;

protected:
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClose();
	void OnButtonSumar();

public:
	CMainFrame();

	DECLARE_MESSAGE_MAP()
};