// ImageMirror.cpp : implementation file
//

#include "stdafx.h"
#include "成绩录入系统.h"
#include "ImageMirror.h"

#include "MainFrm.h"
#include "DateView.h"
#include "DateDoc.h"

// CImageMirror dialog

IMPLEMENT_DYNAMIC(CImageMirror, CDialog)

CImageMirror::CImageMirror(CWnd* pParent /*=NULL*/)
	: CDialog(CImageMirror::IDD, pParent)
	, m_nMirrorHor(0)
	, m_nMirrorVer(0)
	, m_nRow(0)
	, m_nWidth(0)
	, m_nHeight(0)
	, m_nShu(0)
	, m_nRowLength(0)
{

}

CImageMirror::~CImageMirror()
{
}

void CImageMirror::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX,IDC_ROWLENGHT_EDIT,m_nRowLength);
	DDX_Text(pDX,IDC_ROWNUM_EDIT,m_nRow);
	DDX_Text(pDX,IDC_SHUNUM_EDIT,m_nShu);
	DDX_Text(pDX,IDC_WIDTH_EDIT,m_nWidth);
	DDX_Text(pDX,IDC_HEIGHT_EDIT,m_nHeight);
	DDX_Check(pDX,IDC_HOR_CHECK,m_nMirrorHor);
	DDX_Check(pDX,IDC_VER_CHECK,m_nMirrorVer);


}


BEGIN_MESSAGE_MAP(CImageMirror, CDialog)
	ON_BN_CLICKED(IDC_DISPLAY_BTN, &CImageMirror::OnBnClickedDisplayBtn)
//	ON_STN_CLICKED(IDC_COPY, &CImageMirror::OnStnClickedCopy)
	ON_BN_CLICKED(IDC_COPY_BTN, &CImageMirror::OnBnClickedCopyBtn)
END_MESSAGE_MAP()


// CImageMirror message handlers

void CImageMirror::OnBnClickedDisplayBtn()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CDateView *pView = (CDateView*)pMainFrame->GetActiveView();

	pView->m_bMirrorHor=m_nMirrorHor;
	pView->m_bMirrorVer=m_nMirrorVer;
	pView->m_nRow=m_nRow;
	pView->m_nShu=m_nShu;
	pView->m_nWidth=m_nWidth;
	pView->m_nHeight=m_nHeight;
	pView->m_nRowLength=m_nRowLength=((m_nWidth + 3) / 4) * 4;
	
	UpdateData(FALSE);
	pView->Invalidate(TRUE);

}

BOOL CImageMirror::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	//CString str;
	//str=_T("7");

	//CEdit *pEdit = (CEdit *)GetDlgItem(IDC_ROWNUM_EDIT);
	//pEdit->SetWindowText(str);

	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CDateView *pView = (CDateView*)pMainFrame->GetActiveView();

	m_nMirrorHor=pView->m_bMirrorHor;
	m_nMirrorVer=pView->m_bMirrorVer;
	m_nRow=pView->m_nRow;
	m_nShu=pView->m_nShu;
	m_nWidth=pView->m_nWidth;
	m_nHeight=pView->m_nHeight;
	m_nRowLength=pView->m_nRowLength;

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//void CImageMirror::OnStnClickedCopy()
//{
//	// TODO: Add your control notification handler code here
//	UpdateData(TRUE);
//
//	m_nShu=m_nWidth;
//	m_nRow=m_nHeight;
//
//	UpdateData(FALSE);
//
//}

void CImageMirror::OnBnClickedCopyBtn()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_nShu=m_nWidth;
	m_nRow=m_nHeight;

	UpdateData(FALSE);
}
