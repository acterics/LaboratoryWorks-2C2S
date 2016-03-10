// CSessions.h : Implementation of the CSessions class



// CSessions implementation

// code generated on 4 марта 2016 г., 2:09

#include "stdafx.h"
#include "CSessions.h"
IMPLEMENT_DYNAMIC(CSessions, CRecordset)

CSessions::CSessions(CDatabase* pdb)
	: CRecordset(pdb)
{
	
	m_ID = 0;
	m_NAME = "";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CSessions::GetDefaultConnect()
{
	return _T("DSN=LaboratoryWork01Source;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=OLEGLIPSKIY;DATABASE=laboratorywork01;");
}

CString CSessions::GetDefaultSQL()
{
	return _T("[dbo].[Sessions]");
}

void CSessions::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);

}
int CSessions::addRecord()
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
	m_NAME.Format(_T("Session%d"), m_ID);
	Update();
	return m_prevID;
}
/////////////////////////////////////////////////////////////////////////////
// CSessions diagnostics

#ifdef _DEBUG
void CSessions::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSessions::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


