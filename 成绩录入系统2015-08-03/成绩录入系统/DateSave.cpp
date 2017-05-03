#include "StdAfx.h"
#include "DateSave.h"

#include "DateView.h"
#include "DateDoc.h"
#include "MainFrm.h"

IMPLEMENT_SERIAL(CDateSave,CObject,1)

CDateSave::CDateSave(void)
{
}

CDateSave::~CDateSave(void)
{
}
CDateSave::CDateSave(int m_class,int m_iChinese,int m_iMath,
					 int m_iEnglish,CString m_str1,CString m_str2)
{
	this->m_class=m_class;
	this->m_iChinese=m_iChinese;
	this->m_iMath=m_iMath;
	this->m_iEnglish=m_iEnglish;
	this->m_str1=m_str1;
	this->m_str2=m_str2;
}

void CDateSave::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar<<m_class<<m_iChinese<<m_iMath<<m_iEnglish<<m_str1<<m_str2;		
	}
	else
	{	// loading code
		ar>>m_class>>m_iChinese>>m_iMath>>m_iEnglish>>m_str1>>m_str2;
	}
}

void CDateSave::Show(CDC* pDC,int nCount)
{
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CDateView *pView = (CDateView*)pMainFrame->GetActiveView();
	CDateDoc *pDoc=(CDateDoc*)pView->GetDocument();
	ASSERT(pDoc);

	CFont font;
	font.CreatePointFont(150,_T("华文行楷"));

	CFont *pOldFont;
	pOldFont=pDC->SelectObject(&font);


	CString strTemp,str,str1;
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	str1=_T("      ");
	strTemp=m_str1+str1+m_str2+str1;

	switch(m_class)
	{
	case 0:
		strTemp+=_T("高三（1）班")+str1;
		break;
	case 1:
		strTemp+=_T("高三（2）班")+str1;
		break;
	case 2:
		strTemp+=_T("高三（3）班")+str1;
		break;
	}
	
	str.Format(_T("%d"),m_iChinese);
	strTemp+=str+str1+str1;
	str.Format(_T("%d"),m_iMath);
	strTemp+=str+str1+str1;
	str.Format(_T("%d"),m_iEnglish);
	strTemp+=str+str1;

	pDC->TextOut(0,(tm.tmHeight+10)*nCount+20,strTemp);
	
	pDC->SelectObject(&pOldFont);

}
