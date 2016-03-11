// CProperties.h : Implementation of the CProperties class



// CProperties implementation

// code generated on 4 марта 2016 г., 2:31

#include "stdafx.h"
#include "CProperties.h"
IMPLEMENT_DYNAMIC(CProperties, CRecordset)

CProperties::CProperties(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_prevID = -1;
	m_ID = 0;
	m_FIGURE_ID = 0;
	m_FACE_ID = 0;
	m_NAME = "";
	m_VALUE = 0.0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CProperties::GetDefaultConnect()
{
	return _T("DSN=LaboratoryWork01Source;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=OLEGLIPSKIY;DATABASE=laboratorywork01;");
}

CString CProperties::GetDefaultSQL()
{
	return _T("[dbo].[Properties]");
}

void CProperties::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[FIGURE_ID]"), m_FIGURE_ID);
	RFX_Long(pFX, _T("[FACE_ID]"), m_FACE_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);
	RFX_Single(pFX, _T("[VALUE]"), m_VALUE);

}
int CProperties::addRecord(CString name, float value, long figureID, long faceID)
{
	if (!IsBOF() || !IsEOF())
	{
		MoveLast();
		m_prevID = m_ID;
	}
	else
		m_prevID = -1;
	AddNew();
	m_ID = ++m_prevID;
	if(figureID >= 0)
		m_FIGURE_ID = figureID;
	if (faceID >= 0)
		m_FACE_ID = faceID;
	m_NAME = name;
	m_VALUE = value;
	Update();
	return m_prevID;
}
void CProperties::clearRecords()
{
	if (!IsBOF() || !IsEOF())
	{
		while (!IsEOF())
		{
			Delete();
			MoveNext();
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
// CProperties diagnostics

#ifdef _DEBUG
void CProperties::AssertValid() const
{
	CRecordset::AssertValid();
}

void CProperties::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


