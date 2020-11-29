
// TabDemoView.h: интерфейс класса CTabDemoView
//

#pragma once


class CTabDemoView : public CView
{
protected: // создать только из сериализации
	CTabDemoView() noexcept;
	DECLARE_DYNCREATE(CTabDemoView)

// Атрибуты
public:
	CTabDemoDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~CTabDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в TabDemoView.cpp
inline CTabDemoDoc* CTabDemoView::GetDocument() const
   { return reinterpret_cast<CTabDemoDoc*>(m_pDocument); }
#endif

