#pragma once


// Диалоговое окно CStyle

class CStyle : public CPropertyPage
{
	DECLARE_DYNAMIC(CStyle)

public:
	CStyle(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CStyle();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_Bold;
	BOOL m_Italic;
	BOOL m_Underline;
};
