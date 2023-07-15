/*
 * Created on Fri Jul 07 2023
 *
 * Copyright (c) 2023 UsuiSama
 */
#include "CDrawUtil.hpp"

void CDrawUtil::CenterTextHorizontal(int y, CDC* pDC, const CString& strText, CRect rect)
{
	CSize size = pDC->GetTextExtent(strText);
	int x = rect.left + (rect.Width() - size.cx) / 2;
	pDC->TextOut(x, y, strText);
}

void CDrawUtil::CenterTextHorizontalAndBottom(int _y, CDC* pDC, const CString& strText, CRect rect)
{
	CSize size = pDC->GetTextExtent(strText);
	int x = rect.left + (rect.Width() - size.cx) / 2;
	int y = rect.bottom - (rect.Height() - size.cy);
	pDC->TextOut(x, y + _y, strText);
}