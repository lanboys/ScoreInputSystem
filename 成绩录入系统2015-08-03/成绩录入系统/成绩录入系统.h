// �ɼ�¼��ϵͳ.h : �ɼ�¼��ϵͳ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDateApp:
// �йش����ʵ�֣������ �ɼ�¼��ϵͳ.cpp
//

class CDateApp : public CWinApp
{
public:
	CDateApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDateApp theApp;