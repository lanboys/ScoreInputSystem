// DateView.h : CDateView 类的接口
//


#pragma once

#include "DateDoc.h"//不加此行会报错，为什么？

class CDateView : public CView
{
protected: // 仅从序列化创建
	CDateView();
	DECLARE_DYNCREATE(CDateView)

// 属性
public:
	CDateDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // DateView.cpp 中的调试版本
inline CDateDoc* CDateView::GetDocument() const
   { return reinterpret_cast<CDateDoc*>(m_pDocument); }
#endif

