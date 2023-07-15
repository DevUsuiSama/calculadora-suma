/*
 * Created on Fri Jul 07 2023
 *
 * Copyright (c) 2023 UsuiSama
 */
#include "CEditCustom.hpp"

void CEditCustom::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString str;

	GetWindowText(str);
	if (isdigit(str[0]) and str[0] != '.')
		estado = !estado;

	if (nChar == VK_BACK or isdigit(nChar) or (nChar == '.' and contador == 0 and estado))
	{
		if (estado)
			estado = !estado;
		if (nChar == '.' and str.Find('.') == -1)
			contador++;
		if (nChar == VK_BACK and contador > 0)
			if (str.GetLength() > 0)
				if (str.Find('.') != -1)
					contador--;
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
}

CEditCustom::CEditCustom()
{
	estado = false;
	contador = 0;
}

BEGIN_MESSAGE_MAP(CEditCustom, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()