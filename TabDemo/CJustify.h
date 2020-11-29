#pragma once


// Диалоговое окно CJustify

class CJustify : public CPropertyPage
{
	DECLARE_DYNAMIC(CJustify)

public:
	CJustify(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CJustify();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int m_Justify;
};
