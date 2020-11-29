
// TabDemo.h: основной файл заголовка для приложения TabDemo
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CTabDemoApp:
// Сведения о реализации этого класса: TabDemo.cpp
//

class CTabDemoApp : public CWinAppEx
{
public:
	CTabDemoApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTabDemoApp theApp;
