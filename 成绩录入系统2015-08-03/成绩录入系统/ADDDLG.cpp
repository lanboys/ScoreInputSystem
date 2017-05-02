// ADDDLG.cpp : implementation file
//

#include "stdafx.h"
#include "�ɼ�¼��ϵͳ.h"
#include "ADDDLG.h"

#include "DateSave.h"
#include "MainFrm.h"
#include "DateView.h"
#include "DateDoc.h"

// CADDDLG dialog

IMPLEMENT_DYNAMIC(CADDDLG, CDialog)

CADDDLG::CADDDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CADDDLG::IDD, pParent)
	, m_class(-1)
	, m_iChinese(0)
	, m_iMath(0)
	, m_iEnglish(0)
{

}

CADDDLG::~CADDDLG()
{
}

void CADDDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX,IDC_CLASS_ONE,m_class);                
	DDX_Text(pDX,IDC_EDIT_CHANESE,m_iChinese);
	DDX_Text(pDX,IDC_EDIT_MATH,m_iMath);
	DDX_Text(pDX,IDC_EDIT_ENGLISH,m_iEnglish);
	DDV_MinMaxInt(pDX, m_iChinese, 0, 150);
	DDV_MinMaxInt(pDX, m_iMath, 0, 150);
	DDV_MinMaxInt(pDX, m_iEnglish, 0, 150);
}


BEGIN_MESSAGE_MAP(CADDDLG, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CADDDLG::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CADDDLG message handlers

void CADDDLG::OnBnClickedButtonAdd()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);


	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CDateView *pView = (CDateView*)pMainFrame->GetActiveView();
	CDateDoc *pDoc=(CDateDoc*)pView->GetDocument();
	ASSERT(pDoc);

	CString str1,str2;
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT_NAME);
	pEdit->GetWindowText(str1);

	pEdit = (CEdit *)GetDlgItem(IDC_EDIT_NUM);
	pEdit->GetWindowText(str2);

	CButton *pButton= (CButton *)GetDlgItem(IDC_TIP);
	

	if (_T("����")==str1)
	{	
		MessageBox(_T("����������������"));
		return;
	}

	int nCount;
	nCount=(int)pDoc->m_obArray.GetSize();
	
	for (int i=0;i<nCount;i++)
	{
		if (str2==((CDateSave *)pDoc->m_obArray.GetAt(i))->m_str2)
		{
			MessageBox(((CDateSave *)pDoc->m_obArray.GetAt(i))->m_str2+_T(" �Ѿ�¼��ϵͳ������"));
			return;
		}
		
	}

	if (_T("20100941430")==str2)
	{
		MessageBox(_T("��������ȷ��ѧ�ţ�����"));
		return;
	}
	else if (_T("")==str2)
	{
		MessageBox(_T("������ѧ�ţ�����"));
		return;
	}

	if (-1==m_class)
	{	
		MessageBox(_T("��ѡ��༶������"));
		return;
	}

	if (0==m_iChinese || 0==m_iMath || 0==m_iEnglish)
	{
		MessageBox(_T("��������Ʒ������������ĳһ��Ŀ��֣��벹������Ʒ����������ٻ���������"));
		return;
	}
	else if (pButton->GetCheck())
		{
			if (90>=m_iChinese || 90>=m_iMath || 90>=m_iEnglish)
			{
				MessageBox(_T("�����п�Ŀ��������ע�ⲹ��ʱ�䣡����"));
			}
			else if (135<=m_iChinese && 135<=m_iMath && 135<=m_iEnglish)
				{
					MessageBox(_T("�����ο��ò��������Ŭ��������"));
				}

		}

	CDateSave  *pdateSave=new CDateSave(m_class,m_iChinese,m_iMath,m_iEnglish,str1,str2);

	pDoc->m_obArray.Add(pdateSave);

	UpdateLED();

	pView->Invalidate(TRUE);
}

//void CADDDLG::OnOK()
//{
//	// TODO: Add your specialized code here and/or call the base class
//	Invalidate(TRUE);
//	CDialog::OnOK();
//}

BOOL CADDDLG::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CMainFrame *pMainFrame = (CMainFrame*)AfxGetMainWnd();
	CDateView *pView = (CDateView*)pMainFrame->GetActiveView();
	CDateDoc *pDoc=(CDateDoc*)pView->GetDocument();
	ASSERT(pDoc);

	CString str1,str2;
	
	int nCount;
	nCount=(int)pDoc->m_obArray.GetSize();

	if (!nCount)
	{
		str1=_T("����");
		str2=_T("20100941430");
	}
	else
	{
		str1=((CDateSave *)pDoc->m_obArray.GetAt(nCount-1))->m_str1;
		str2=((CDateSave *)pDoc->m_obArray.GetAt(nCount-1))->m_str2;
		m_class=((CDateSave *)pDoc->m_obArray.GetAt(nCount-1))->m_class;
		m_iChinese=((CDateSave *)pDoc->m_obArray.GetAt(nCount-1))->m_iChinese;
		m_iMath=((CDateSave *)pDoc->m_obArray.GetAt(nCount-1))->m_iMath;
		m_iEnglish=((CDateSave *)pDoc->m_obArray.GetAt(nCount-1))->m_iEnglish;
	}

	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT_NAME);
	pEdit->SetWindowText(str1);

	pEdit = (CEdit *)GetDlgItem(IDC_EDIT_NUM);
	pEdit->SetWindowText(str2);

	CButton *pButton= (CButton *)GetDlgItem(IDC_TIP);
	pButton->SetCheck(NULL);

	UpdateLED();

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CADDDLG::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	//delete this;
	CDialog::PostNcDestroy();
}

void CADDDLG::UpdateLED()
{
	CStatic* pStatic=NULL;

	HBITMAP hGrayBitmap=LoadBitmap(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDB_1));
	HBITMAP hRedBitmap=LoadBitmap(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDB_2));

	pStatic=(CStatic*)GetDlgItem(IDC_1);
	if(m_iChinese<=90)
	{
		pStatic->SetBitmap(hRedBitmap);
	}
	else
	{
		pStatic->SetBitmap(hGrayBitmap);
	}


	pStatic=(CStatic*)GetDlgItem(IDC_2);
	if(m_iMath<=90)
	{
		pStatic->SetBitmap(hRedBitmap);
	}
	else
	{
		pStatic->SetBitmap(hGrayBitmap);
	}


	pStatic=(CStatic*)GetDlgItem(IDC_3);
	if(m_iEnglish<=90)
	{
		pStatic->SetBitmap(hRedBitmap);
	}
	else
	{
		pStatic->SetBitmap(hGrayBitmap);
	}
}

