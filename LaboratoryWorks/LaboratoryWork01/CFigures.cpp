// CFigures.h : Implementation of the CFigures class



// CFigures implementation

// code generated on 4 марта 2016 г., 2:26

#include "stdafx.h"
#include "CFigures.h"
IMPLEMENT_DYNAMIC(CFigures, CRecordset)

CFigures::CFigures(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_SESSION_ID = 0;
	m_NAME = "";
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CFigures::GetDefaultConnect()
{
	return _T("DSN=LaboratoryWork01Source;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=OLEGLIPSKIY;DATABASE=laboratorywork01;");
}

CString CFigures::GetDefaultSQL()
{
	return _T("[dbo].[Figures]");
}

void CFigures::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[SESSION_ID]"), m_SESSION_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);

}
void CFigures::addRecord(int sessionID)
{
	AddNew();
	m_ID = GetRecordCount();;
	m_SESSION_ID = sessionID;
	m_NAME.Format(_T("%dFigure%d"), sessionID, m_ID);
	//Update();
}
/////////////////////////////////////////////////////////////////////////////
// CFigures diagnostics

#ifdef _DEBUG
void CFigures::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFigures::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


