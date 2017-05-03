#pragma once


// CImageMirror dialog

class CImageMirror : public CDialog
{
	DECLARE_DYNAMIC(CImageMirror)

public:
	CImageMirror(CWnd* pParent = NULL);   // standard constructor
	virtual ~CImageMirror();

// Dialog Data
	enum { IDD = IDD_IMAGE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_nMirrorHor;
public:
	int m_nMirrorVer;
public:
	afx_msg void OnBnClickedDisplayBtn();
public:
	int m_nRow;
public:
	virtual BOOL OnInitDialog();
public:
	int m_nWidth;
public:
	int m_nHeight;
public:
	int m_nShu;
public:
	int m_nRowLength;
public:
//	afx_msg void OnStnClickedCopy();
public:
	afx_msg void OnBnClickedCopyBtn();
};
