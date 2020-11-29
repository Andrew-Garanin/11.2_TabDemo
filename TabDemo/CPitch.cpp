// CPitch.cpp: файл реализации
//

#include "pch.h"
#include "TabDemo.h"
#include "CPitch.h"
#include "afxdialogex.h"


// Диалоговое окно CPitch

IMPLEMENT_DYNAMIC(CPitch, CPropertyPage)

CPitch::CPitch(CWnd* pParent /*=nullptr*/)
	: CPropertyPage(IDD_DIALOG3, 0)
	, m_Pitch(0)
	, m_Spacing(0)
{

}

CPitch::~CPitch()
{
}

void CPitch::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_VARIABLE, m_Pitch);
	DDX_Text(pDX, IDC_SPACING, m_Spacing);
	DDV_MinMaxInt(pDX, m_Spacing, 1, 3);
	DDX_Control(pDX, IDC_SPACING, m_SpacingEdit);
}


BEGIN_MESSAGE_MAP(CPitch, CPropertyPage)
END_MESSAGE_MAP()


// Обработчики сообщений CPitch


BOOL CPitch::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  Добавить дополнительную инициализацию
	m_SpacingEdit.LimitText(1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}
