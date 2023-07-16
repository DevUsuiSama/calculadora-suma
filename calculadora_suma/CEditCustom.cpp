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
	if (isdigit(str[0]) && str.Find('.') == -1)
		estado = !estado;

	if (nChar == VK_BACK || isdigit(nChar) || (nChar == '.' && contador == 0 && estado))
	{
		if (estado)
			estado = !estado;
		if (nChar == '.' && str.Find('.') == -1)
			contador++;
		if (nChar == VK_BACK && contador > 0)
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