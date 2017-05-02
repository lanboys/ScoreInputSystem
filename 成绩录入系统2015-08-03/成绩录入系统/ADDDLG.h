#pragma once


// CADDDLG dialog

class CADDDLG : public CDialog
{
	DECLARE_DYNAMIC(CADDDLG)

public:
	CADDDLG(CWnd* pParent = NULL);   // standard constructor
	virtual ~CADDDLG();

// Dialog Data
	enum { IDD = IDD_ADD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_class;
public:
	int m_iChinese;
public:
	int m_iMath;
public:
	int m_iEnglish;
public:
	afx_msg void OnBnClickedButtonAdd();
protected:
//	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void PostNcDestroy();
	virtual void UpdateLED();
};
