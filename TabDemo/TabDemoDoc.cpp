
// TabDemoDoc.cpp: реализация класса CTabDemoDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "TabDemo.h"
#endif

#include "TabDemoDoc.h"
#include "Cstyle.h"
#include "Cjustify.h"
#include "Cpitch.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTabDemoDoc

IMPLEMENT_DYNCREATE(CTabDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTabDemoDoc, CDocument)
	ON_COMMAND(ID_TEXT_FORMAT, &CTabDemoDoc::OnTextFormat)
END_MESSAGE_MAP()


// Создание или уничтожение CTabDemoDoc

CTabDemoDoc::CTabDemoDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора
	m_Bold = FALSE;
	m_Italic = FALSE;
	m_Underline = FALSE;
	m_Justify = JUSTIFY_LEFT;
	m_Pitch = PITCH_VARIABLE;
	m_Spacing = 1;

}

CTabDemoDoc::~CTabDemoDoc()
{
}

BOOL CTabDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CTabDemoDoc

void CTabDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CTabDemoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CTabDemoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CTabDemoDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CTabDemoDoc

#ifdef _DEBUG
void CTabDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTabDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CTabDemoDoc


void CTabDemoDoc::OnTextFormat()
{
	// TODO: добавьте свой код обработчика команд
	// создание объекта диалогового окна с вкладками:
	CPropertySheet PropertySheet(_T("Format"));

	// создание объекта для каждой страницы:
	CStyle StylePage;
	CJustify JustifyPage;
	CPitch PitchPage;

	// добавление страниц к объекту диалогового окна:
	PropertySheet.AddPage(&StylePage);
	PropertySheet.AddPage(&JustifyPage);
	PropertySheet.AddPage(&PitchPage);
	// инициализация объектов страниц:
	StylePage.m_Bold = m_Bold;
	StylePage.m_Italic = m_Italic;
	StylePage.m_Underline = m_Underline;
	JustifyPage.m_Justify = m_Justify;
	PitchPage.m_Pitch = m_Pitch;
	PitchPage.m_Spacing = m_Spacing;

	// отображение диалогового окна с вкладками:   
	if (PropertySheet.DoModal() == IDOK)
	{
		// сохранение значений элементов управления страниц:
		m_Bold = StylePage.m_Bold;
		m_Italic = StylePage.m_Italic;
		m_Underline = StylePage.m_Underline;
		m_Justify = JustifyPage.m_Justify;
		m_Pitch = PitchPage.m_Pitch;
		m_Spacing = PitchPage.m_Spacing;

		// перерисовка текста:
		UpdateAllViews(NULL);
	}

}
