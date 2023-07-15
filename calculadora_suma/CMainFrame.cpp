/*
 * Created on Fri Jul 07 2023
 *
 * Copyright (c) 2023 UsuiSama
 */
#include "CMainFrame.hpp"

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)
{
	// Verifica si el mensaje es una pulsación de tecla y si la tecla es la tecla Tab
	if (pMsg->message == WM_KEYDOWN and pMsg->wParam == VK_TAB)
	{
		// Obtiene el control de edición actualmente enfocado
		CWnd* pFocus = GetFocus();
		// Verifica si el control de edición actualmente enfocado es un control de edición
		if (pFocus != NULL and pFocus->IsKindOf(RUNTIME_CLASS(CEditCustom)))
		{
			// Obtiene el siguiente control de edición en la ventana
			CWnd* pNext = pFocus->GetNextWindow();
			// Verifica si el siguiente control de edición es un control de edición
			if (pNext != NULL and pNext->IsKindOf(RUNTIME_CLASS(CEditCustom)))
			{
				// Establece el foco en el siguiente control de edición
				pNext->SetFocus();
				// Devuelve TRUE para indicar que se ha procesado el mensaje
				return TRUE;
			}
			else {
				// Obtiene el anterior control de edición en la ventana
				pNext = pFocus->GetWindow(GW_HWNDPREV);
				// Verifica si el anterior control de edición es un control de edición
				if (pNext != NULL and pNext->IsKindOf(RUNTIME_CLASS(CEditCustom)))
				{
					pNext->SetFocus();
					return TRUE;
				}
			}
		}
	}

	if (pMsg->message == WM_KEYDOWN and pMsg->wParam == VK_RETURN)
	{
		OnButtonSumar();
		return TRUE;
	}

	// Llama a la función base para procesar los mensajes adicionales
	return CFrameWnd::PreTranslateMessage(pMsg);
}

void CMainFrame::OnPaint()
{
	CPaintDC text(this);
	CRect rect;
	static CFont font[6];

	font[0].CreateFont(100, 50, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Ubuntu Mono"));

	text.SelectObject(font[0]);
	text.SetTextColor(RGB(255, 222, 0));
	text.SetBkColor(RGB(15, 15, 15));

	GetClientRect(&rect);

	CDrawUtil::CenterTextHorizontal((60 * 2), &text, _T("<<DevUsuiSama-2019>>"), rect);

	font[1].CreateFont(20, 10, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Courier New"));

	text.SelectObject(font[1]);
	text.SetTextColor(RGB(0, 255, 255));
	text.SetBkColor(RGB(15, 15, 15));

	GetClientRect(&rect);

	CDrawUtil::CenterTextHorizontalAndBottom(
		20,
		&text,
		_T("Calculadora icon by Icons8"),
		rect);

	font[2].CreateFont(30, 15, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Courier New"));

	text.SelectObject(font[2]);
	text.SetTextColor(RGB(192, 192, 192));
	text.SetBkColor(RGB(15, 15, 15));
	text.TextOut((75 * 2), ((180 * 2) + 4), _T("Ingresé Un Número:")); // Text n1
	text.TextOut((75 * 2), ((210 * 2) + 4), _T("Ingresé Un Número:")); // Text n2

	font[3].CreatePointFont(150, _T("Arial"));
	GetDlgItem(ID_STATIC_RESULTADO)->SetFont(&font[3]);

	font[4].CreatePointFont(100, _T("Courier New"));
	GetDlgItem(ID_EDIT1)->SetFont(&font[4]);
	GetDlgItem(ID_EDIT2)->SetFont(&font[4]);

	font[5].CreatePointFont(120, _T("Courier New"));
	GetDlgItem(ID_BUTTON_SUMAR)->SetFont(&font[5]);
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDC* pDC = GetDC();
	CSize size = pDC->GetTextExtent(_T("Calculadora icon by Icons8"));
	CRect rect;

	GetClientRect(&rect);

	if (point.x > rect.left && point.x < rect.Width() && point.y > rect.top && point.y < 50)
		ShellExecute(NULL, _T("open"), _T("https://icons8.com/icon/11645/calculadora"), NULL, NULL, SW_SHOWNORMAL);

	CFrameWnd::OnLButtonDown(nFlags, point);
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CRect rect;

	GetClientRect(&rect);

	int nWidth = rect.Width();
	int nLeft[4] = { 0 };


	if (CFrameWnd::OnCreate(lpCreateStruct) == EXIT_FAILURE)
		return EXIT_FAILURE;

	// El siguiente calculo es para encontrar el centro del elemento
	nLeft[0] = (nWidth - ((380 * 2) - 10)) / 2;
	nLeft[1] = (nWidth - ((171 * 2) - 10)) / 2;
	nLeft[2] = (nWidth - ((350 * 2) - 10)) / 2;
	nLeft[3] = (nWidth - ((350 * 2) - 10)) / 2;

	if (!resultado.CreateEx(
		WS_EX_CLIENTEDGE,
		_T("STATIC"),
		_T("#Resultado: 0.00"),
		WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | SS_CENTERIMAGE,
		nLeft[0],
		(300 * 2),
		((380 * 2) - 10),
		(85 * 2),
		m_hWnd,
		(HMENU)ID_STATIC_RESULTADO))
	{
		TRACE0("Fallo al Crear Texto Estatico");
		return EXIT_FAILURE;
	}

	if (!btnSumar.CreateEx(
		WS_EX_CLIENTEDGE,
		_T("BUTTON"),
		_T("Sumar"),
		WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		nLeft[1],
		(250 * 2),
		((171 * 2) - 10),
		(25 * 2),
		m_hWnd,
		(HMENU)ID_BUTTON_SUMAR))
	{
		TRACE0("Fallo al Crear Boton");
		return EXIT_FAILURE;
	}

	if (!edit1.CreateEx(
		WS_EX_TRANSPARENT,
		_T("EDIT"),
		NULL,
		WS_VISIBLE | WS_CHILD | WS_BORDER | WS_TABSTOP | ES_CENTER,
		nLeft[2],
		(180 * 2),
		((350 * 2) - 10),
		(20 * 2),
		m_hWnd,
		(HMENU)ID_EDIT1))
	{
		TRACE0("Fallo al Crear Editor de Texto Numero 1");
		return EXIT_FAILURE;
	}

	if (!edit2.CreateEx(
		WS_EX_TRANSPARENT,
		_T("EDIT"),
		NULL,
		WS_VISIBLE | WS_CHILD | WS_BORDER | WS_TABSTOP | ES_CENTER,
		nLeft[3],
		(210 * 2),
		((350 * 2) - 10),
		(20 * 2),
		m_hWnd,
		(HMENU)ID_EDIT2))
	{
		TRACE0("Fallo al Crear Editor de Texto Numero 2");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

HBRUSH CMainFrame::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetTextColor(RGB(0, 255, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
		return CreateSolidBrush(RGB(0, 0, 0));
	case CTLCOLOR_EDIT:
		pDC->SetTextColor(RGB(0, 255, 0));
		pDC->SetBkColor(RGB(0, 0, 0));
		return CreateSolidBrush(RGB(0, 0, 0));
	case CTLCOLOR_BTN:
		pDC->SetBkColor(RGB(0, 255, 0));
		return CreateSolidBrush(RGB(0, 255, 0));
	default:
		return CFrameWnd::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}

void CMainFrame::OnClose()
{
	int dmessage;

	dmessage = AfxMessageBox(_T("Desea Salir de la Aplicación?"), MB_YESNO | MB_ICONINFORMATION);
	if (dmessage == IDYES)
	{
		AfxMessageBox(_T("Gracias!. Por Usar Calculadora - Suma :)"), MB_OK | MB_ICONINFORMATION);
		DestroyWindow();
	}
}

void CMainFrame::OnButtonSumar()
{
	CString text1, text2, text_total;
	float num1, num2, total;

	edit1.GetWindowText(text1);
	edit2.GetWindowText(text2);

	num1 = _tcstof(text1, NULL);
	num2 = _tcstof(text2, NULL);

	total = num1 + num2;

	text_total.Format(TEXT("#Resultado: %.2lf"), total);
	resultado.SetWindowText(text_total);
}

CMainFrame::CMainFrame()
{
	CString wcex = AfxRegisterWndClass(
		CS_VREDRAW | CS_HREDRAW,
		AfxGetApp()->LoadStandardCursor(IDC_ARROW),
		CreateSolidBrush(RGB(15, 15, 15)),
		AfxGetApp()->LoadIcon(MAKEINTRESOURCE(IDI_ICON1)));

	CreateEx(
		WS_EX_CLIENTEDGE,
		wcex,
		_T("Calculadora - Suma"),
		WS_SYSMENU | WM_DPICHANGED,
		(220 * 2),
		(100 * 2),
		((800 * 2) - 10),
		(450 * 2),
		NULL,
		NULL);
}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_BN_CLICKED(ID_BUTTON_SUMAR, &CMainFrame::OnButtonSumar)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	ON_WM_CLOSE()
END_MESSAGE_MAP()