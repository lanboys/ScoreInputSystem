// DateDoc.h : CDateDoc ��Ľӿ�
//


#pragma once
#include "afxcoll.h"


class CDateDoc : public CDocument
{
protected: // �������л�����
	CDateDoc();
	DECLARE_DYNCREATE(CDateDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CDateDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CObArray m_obArray;
public:
	virtual void DeleteContents();
};


