/*
 * Created on Fri Jul 07 2023
 *
 * Copyright (c) 2023 UsuiSama
 */
#pragma once

#ifndef __CEDIT_CUSTOM_HPP__
#define __CEDIT_CUSTOM_HPP__

#ifndef __STDAFX_HPP__
#include "stdafx.hpp"
#endif // !__STDAFX_HPP__

class CEditCustom : public CEdit
{
private:
	int contador;
	bool estado;

protected:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);

public:
	CEditCustom();

	DECLARE_MESSAGE_MAP()
};

#endif // !__CEDIT_CUSTOM_HPP__