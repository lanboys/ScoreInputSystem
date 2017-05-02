// DateView.cpp : CDateView 类的实现
//

#include "stdafx.h"
#include "成绩录入系统.h"

#include "DateDoc.h"
#include "DateView.h"
#include "ADDDLG.h"
#include "ImageMirror.h"

#include "DateSave.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDateView

IMPLEMENT_DYNCREATE(CDateView, CView)

BEGIN_MESSAGE_MAP(CDateView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SCORE_ADD, &CDateView::OnScoreAdd)
	ON_COMMAND(ID_IMAGE_Mirror, &CDateView::OnImageMirror)
END_MESSAGE_MAP()

// CDateView 构造/析构

CDateView::CDateView()
: m_bMirrorHor(false)
, m_bMirrorVer(false)
, m_nRow(7)
, m_bDisplay(false)
, m_nShu(5)
, m_nWidth(5)
, m_nHeight(7)
, m_nRowLength(0)
{
	// TODO: 在此处添加构造代码

}

CDateView::~CDateView()
{
}

BOOL CDateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDateView 绘制

void CDateView::OnDraw(CDC* pDC)
{
	CDateDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(!m_bDisplay)
	{
		int nCount;
		nCount=(int)pDoc->m_obArray.GetSize();

		if (nCount)
		{
			CFont font;
			font.CreatePointFont(150,_T("华文行楷"));

			CFont *pOldFont;
			pOldFont=pDC->SelectObject(&font);

			CString strTemp;
			strTemp=_T("姓  名      学   号      班   级      语 文      数 学      英 语");
			pDC->TextOut(0,0,strTemp);

			pDC->SelectObject(&pOldFont);
		}

		for (int i=0;i<nCount;i++)
		{
			((CDateSave *)pDoc->m_obArray.GetAt(i))->Show(pDC,i+1);
		}
	}
	
/////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////
	
	else
	{
			
		int nWidth=m_nWidth;
		int nHeight=m_nHeight;
		int ImageBuffer=100;
		
		int m_pBits=200;
		int a=0;
		int b=0;
		BOOL m_bRotate=1;
	
		CString strTemp1,strTemp2,strTemp3,str,str1;
		TEXTMETRIC tm;
		pDC->GetTextMetrics(&tm);
		str1=_T("   ");
	
		if(m_bRotate)
		{
			m_nRowLength = (int)((nWidth + 3) / 4) * 4;

			if(!m_bMirrorHor && !m_bMirrorVer)
			{
				for(int i = 0; i < nHeight; ++i)
				{
	
					strTemp1="     ";
					strTemp2="     ";
					
					for(int j = 0; j < nWidth; ++j)
					{
	
						a=m_pBits + i * m_nRowLength + j;
						b=ImageBuffer + i + (nWidth - 1 - j)* nHeight;
	
						str.Format(_T("%d"),a);
						strTemp1+=str+str1;
	
						str.Format(_T("%d"),b);
						strTemp2+=str+str1;
					}
					pDC->TextOut(300,(tm.tmHeight+10)*i+40,strTemp1);
					pDC->TextOut(300,(tm.tmHeight+10)*i+250,strTemp2);
				}
	
				for(int i = 0; i < m_nShu; ++i)
				{
					strTemp3="     ";
	
					for(int j = 0; j < m_nRow; ++j)
					{
					
						a=j+i*m_nRow;
						
						str.Format(_T("%d"),a+100);
						strTemp3+=str+str1;
					}
					
					pDC->TextOut(0,(tm.tmHeight+10)*i+250,strTemp3);
				}
	
			}
			else if(!m_bMirrorHor && m_bMirrorVer)
			{
				for(int i = 0; i < nHeight; ++i)
				{
	
					strTemp1="     ";
					strTemp2="     ";
	
					for(int j = 0; j < nWidth; ++j)
					{
						a=m_pBits + i * m_nRowLength + j;
						b=ImageBuffer + (nHeight - 1 - i) + (nWidth - 1 - j) * nHeight;
						
						str.Format(_T("%d"),a);
						strTemp1+=str+str1;
	
						str.Format(_T("%d"),b);
						strTemp2+=str+str1;
					}
					pDC->TextOut(300,(tm.tmHeight+10)*i+40,strTemp1);
					pDC->TextOut(300,(tm.tmHeight+10)*i+250,strTemp2);
				}
	
				for(int i = 0; i < m_nShu; ++i)
				{
					strTemp3="     ";

					for(int j = 0; j < m_nRow; ++j)
						{
		
							a=j+i*m_nRow;
		
		
							str.Format(_T("%d"),a+100);
							strTemp3+=str+str1;
						}
		
						pDC->TextOut(0,(tm.tmHeight+10)*i+250,strTemp3);
					}
				}
		
		
		
		
				else if(m_bMirrorHor && !m_bMirrorVer)
				{
					for(int i = 0; i < nHeight; ++i)
					{
						strTemp1="     ";
						strTemp2="     ";
		
						for(int j = 0; j < nWidth; ++j)
						{
							a=m_pBits + i * m_nRowLength + j;
							b=ImageBuffer + i + j * nHeight;
		
		
		
		
		
							str.Format(_T("%d"),a);
							strTemp1+=str+str1;
		
							str.Format(_T("%d"),b);
							strTemp2+=str+str1;
							}
							pDC->TextOut(300,(tm.tmHeight+10)*i+40,strTemp1);
							pDC->TextOut(300,(tm.tmHeight+10)*i+250,strTemp2);
							}
		
					for(int i = 0; i < m_nShu; ++i)
					{
						strTemp3="     ";

						for(int j = 0; j < m_nRow; ++j)
							{
		
							a=j+i*m_nRow;
		
		
							str.Format(_T("%d"),a+100);
							strTemp3+=str+str1;
							}
		
							pDC->TextOut(0,(tm.tmHeight+10)*i+250,strTemp3);
							}
					}
				
				else if(m_bMirrorHor && m_bMirrorVer)
				{
					for(int i = 0; i < nHeight; ++i)
					{
						strTemp1="     ";
						strTemp2="     ";
			
						for(int j = 0; j < nWidth; ++j)
						{
							a=m_pBits + i * m_nRowLength + j;
							b=ImageBuffer + (nHeight - 1 - i) + j * nHeight;
							
							str.Format(_T("%d"),a);
							strTemp1+=str+str1;
		
							str.Format(_T("%d"),b);
							strTemp2+=str+str1;
						}
							pDC->TextOut(300,(tm.tmHeight+10)*i+40,strTemp1);
							pDC->TextOut(300,(tm.tmHeight+10)*i+250,strTemp2);
					}
		
					for(int i = 0; i < m_nShu; ++i)
					{
						strTemp3="     ";

						for(int j = 0; j < m_nRow; ++j)
							{
		
							a=j+i*m_nRow;
		
		
							str.Format(_T("%d"),a+100);
							strTemp3+=str+str1;
							}
		
							pDC->TextOut(0,(tm.tmHeight+10)*i+250,strTemp3);
						}
					}
			}
			
			
			
			/*else
			{
		
				if(!m_bMirrorHor && !m_bMirrorVer)
				{
					memcpy(m_pBits, ImageBuffer, nWidth*nHeight);
				}
				else if(!m_bMirrorHor && m_bMirrorVer)
				{
					for(int i = 0; i < nHeight; ++i)
						memcpy(m_pBits + i * nWidth, (BYTE*)ImageBuffer + (nHeight - 1 - i) * nWidth, nWidth);
				}
				else if(m_bMirrorHor && !m_bMirrorVer)
				{
					for(int i = 0; i < nHeight; ++i)
					{
						for(int j = 0; j < nWidth; ++j)
						{
							*(m_pBits + i * nWidth + j) = *((BYTE*)ImageBuffer + i * nWidth + nWidth - 1 - j);
						}
					}
				}
				else if(m_bMirrorHor && m_bMirrorVer)
				{
					for(int i = 0; i < nHeight; ++i)
					{
						for(int j = 0; j < nWidth; ++j)
						{
							*(m_pBits + i * nWidth + j) = *((BYTE*)ImageBuffer + (nHeight - 1 - i) * nWidth + nWidth - 1 - j);
						}
					}
				}*/
		}
	



	
	// TODO: 在此处为本机数据添加绘制代码
}


// CDateView 打印

BOOL CDateView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDateView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDateView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CDateView 诊断

#ifdef _DEBUG
void CDateView::AssertValid() const
{
	CView::AssertValid();
}

void CDateView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDateDoc* CDateView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDateDoc)));
	return (CDateDoc*)m_pDocument;
}
#endif //_DEBUG


// CDateView 消息处理程序

void CDateView::OnScoreAdd()
{
	// TODO: Add your command handler code here
	m_bDisplay=FALSE;
	CADDDLG dlg;
	dlg.DoModal();
	/*if (IDOK==dlg.DoModal())
	{
		Invalidate(TRUE);
	}*/


	/*CADDDLG *pDlg=new CADDDLG;
	pDlg->Create(ID_SCORE_ADD,this);
	pDlg->ShowWindow(SW_SHOW);*/
	
}

void CDateView::OnImageMirror()
{
	m_bDisplay=TRUE;
	CImageMirror dlg;
	dlg.DoModal();

	// TODO: Add your command handler code here
}
