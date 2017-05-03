// DateView.cpp : CDateView ���ʵ��
//

#include "stdafx.h"
#include "�ɼ�¼��ϵͳ.h"

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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SCORE_ADD, &CDateView::OnScoreAdd)
	ON_COMMAND(ID_IMAGE_Mirror, &CDateView::OnImageMirror)
END_MESSAGE_MAP()

// CDateView ����/����

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
	// TODO: �ڴ˴���ӹ������

}

CDateView::~CDateView()
{
}

BOOL CDateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDateView ����

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
			font.CreatePointFont(150,_T("�����п�"));

			CFont *pOldFont;
			pOldFont=pDC->SelectObject(&font);

			CString strTemp;
			strTemp=_T("��  ��      ѧ   ��      ��   ��      �� ��      �� ѧ      Ӣ ��");
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
	



	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDateView ��ӡ

BOOL CDateView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDateView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDateView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDateView ���

#ifdef _DEBUG
void CDateView::AssertValid() const
{
	CView::AssertValid();
}

void CDateView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDateDoc* CDateView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDateDoc)));
	return (CDateDoc*)m_pDocument;
}
#endif //_DEBUG


// CDateView ��Ϣ�������

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
