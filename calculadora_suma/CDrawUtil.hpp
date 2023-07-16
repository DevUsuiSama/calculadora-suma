/*
 * Created on Fri Jul 07 2023
 *
 * Copyright (c) 2023 UsuiSama
 */
#pragma once

#ifndef __STDAFX_HPP__
#include "stdafx.hpp"
#endif // !__STDAFX_HPP__

class CDrawUtil
{
public:
	static void CenterTextHorizontal(int y, CDC* pDC, const CString& strText, CRect rect);
	static void CenterTextHorizontalAndTop(int y, CDC* pDC, const CString& strText, CRect rect);
};

