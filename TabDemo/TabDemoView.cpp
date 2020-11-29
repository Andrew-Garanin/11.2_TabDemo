
// TabDemoView.cpp: реализация класса CTabDemoView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "TabDemo.h"
#endif

#include "TabDemoDoc.h"
#include "TabDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTabDemoView

IMPLEMENT_DYNCREATE(CTabDemoView, CView)

BEGIN_MESSAGE_MAP(CTabDemoView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CTabDemoView

CTabDemoView::CTabDemoView() noexcept
{
	// TODO: добавьте код создания

}

CTabDemoView::~CTabDemoView()
{
}

BOOL CTabDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CTabDemoView

void CTabDemoView::OnDraw(CDC* pDC)
{
	CTabDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	RECT ClientRect;
	CFont Font;
	LOGFONT LF;
	int LineHeight;
	CFont* PtrOldFont;
	int X, Y;
	// заполнение структуры LF свойствами
	// стандартного системного шрифта:
	CFont TempFont;
	if (pDoc->m_Pitch == PITCH_VARIABLE)
		TempFont.CreateStockObject(SYSTEM_FONT);
	else
		TempFont.CreateStockObject(SYSTEM_FIXED_FONT);
	TempFont.GetObject(sizeof(LOGFONT), &LF);
	// инициализируем поля lfWeight, lfItalic и lfUnderline: 
	if (pDoc->m_Bold)
		LF.lfWeight = FW_BOLD;
	if (pDoc->m_Italic)
		LF.lfItalic = 1;
	if (pDoc->m_Underline)
		LF.lfUnderline = 1;

	// создание и выбор шрифта:
	Font.CreateFontIndirect(&LF);
	PtrOldFont = pDC->SelectObject(&Font);
	// задаем выравнивание:
	GetClientRect(&ClientRect);
	switch (pDoc->m_Justify)
	{
	case JUSTIFY_LEFT:
		pDC->SetTextAlign(TA_LEFT);
		X = ClientRect.left + 5;
		break;
	case JUSTIFY_CENTER:
		pDC->SetTextAlign(TA_CENTER);
		X = (ClientRect.left + ClientRect.right) / 2;
		break;
	case JUSTIFY_RIGHT:
		pDC->SetTextAlign(TA_RIGHT);
		X = ClientRect.right - 5;
		break;
	}
	// установка цвета текста и режима фона:
	pDC->SetTextColor(::GetSysColor(COLOR_WINDOWTEXT));
	pDC->SetBkMode(TRANSPARENT);

	// вывод строк текста:
	LineHeight = LF.lfHeight * pDoc->m_Spacing;
	Y = 5;
	pDC->TextOut(X, Y,
		_T("This is the first line of sample text."));
	Y += LineHeight;
	pDC->TextOut(X, Y,
		_T("This is the second line of sample text."));
	Y += LineHeight;
	pDC->TextOut(X, Y,
		_T("This is the third line of sample text."));

	// отмена выбора шрифта:
	pDC->SelectObject(PtrOldFont);

}

void CTabDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTabDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CTabDemoView

#ifdef _DEBUG
void CTabDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTabDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTabDemoDoc* CTabDemoView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTabDemoDoc)));
	return (CTabDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CTabDemoView
