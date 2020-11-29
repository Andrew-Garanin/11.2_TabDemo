#pragma once


// Диалоговое окно CPitch

class CPitch : public CPropertyPage
{
	DECLARE_DYNAMIC(CPitch)

public:
	CPitch(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CPitch();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	int m_Pitch;
	int m_Spacing;
	CEdit m_SpacingEdit;
	virtual BOOL OnInitDialog();
};
