// DateView.h : CDateView ��Ľӿ�
//


#pragma once

#include "DateDoc.h"//���Ӵ��лᱨ��Ϊʲô��

class CDateView : public CView
{
protected: // �������л�����
	CDateView();
	DECLARE_DYNCREATE(CDateView)

// ����
public:
	CDateDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnScoreAdd();
public:
	afx_msg void OnImageMirror();
public:
	int m_bMirrorHor;
public:
	int m_bMirrorVer;
public:
	int m_nRow;
public:
	bool m_bDisplay;
public:
	int m_nShu;
public:
	int m_nWidth;
public:
	int m_nHeight;
	int m_nRowLength;
};

#ifndef _DEBUG  // DateView.cpp �еĵ��԰汾
inline CDateDoc* CDateView::GetDocument() const
   { return reinterpret_cast<CDateDoc*>(m_pDocument); }
#endif

