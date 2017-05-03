#pragma once

class CDateSave :
	public CObject
{
	DECLARE_SERIAL(CDateSave)
public:
	int m_class;
public:
	int m_iChinese;
public:
	int m_iMath;
public:
	int m_iEnglish;
	CString m_str1;
	CString m_str2;
public:
	CDateSave(void);
	CDateSave(int m_class,int m_iChinese,int m_iMath,
		int m_iEnglish,CString m_str1,CString m_str2);
public:
	~CDateSave(void);
public:
	virtual void Serialize(CArchive& ar);
public:
	void Show(CDC* pDC,int nCount=0);
};
