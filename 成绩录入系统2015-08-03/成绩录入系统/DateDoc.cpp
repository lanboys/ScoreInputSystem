// DateDoc.cpp : CDateDoc 类的实现
//

#include "stdafx.h"
#include "成绩录入系统.h"

#include "DateDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDateDoc

IMPLEMENT_DYNCREATE(CDateDoc, CDocument)

BEGIN_MESSAGE_MAP(CDateDoc, CDocument)
END_MESSAGE_MAP()


// CDateDoc 构造/析构

CDateDoc::CDateDoc()
{
	// TODO: 在此添加一次性构造代码

}

CDateDoc::~CDateDoc()
{
}

BOOL CDateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CDateDoc 序列化

void CDateDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}

	m_obArray.Serialize(ar);
}


// CDateDoc 诊断

#ifdef _DEBUG
void CDateDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDateDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDateDoc 命令

void CDateDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
	int nCount;
	nCount=(int)m_obArray.GetSize();

	for (int i=0;i<nCount;i++)
	{
		delete m_obArray.GetAt(i);
	}
	m_obArray.RemoveAll();

	CDocument::DeleteContents();
}
