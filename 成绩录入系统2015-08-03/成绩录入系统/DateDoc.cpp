// DateDoc.cpp : CDateDoc ���ʵ��
//

#include "stdafx.h"
#include "�ɼ�¼��ϵͳ.h"

#include "DateDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDateDoc

IMPLEMENT_DYNCREATE(CDateDoc, CDocument)

BEGIN_MESSAGE_MAP(CDateDoc, CDocument)
END_MESSAGE_MAP()


// CDateDoc ����/����

CDateDoc::CDateDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDateDoc::~CDateDoc()
{
}

BOOL CDateDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CDateDoc ���л�

void CDateDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}

	m_obArray.Serialize(ar);
}


// CDateDoc ���

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


// CDateDoc ����

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
