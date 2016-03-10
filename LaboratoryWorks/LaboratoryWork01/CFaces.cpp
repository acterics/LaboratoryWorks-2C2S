// CFaces.h : Implementation of the CFaces class



// CFaces implementation

// code generated on 4 марта 2016 г., 3:26

#include "stdafx.h"
#include "CFaces.h"

IMPLEMENT_DYNAMIC(CFaces, CRecordset)

CFaces::CFaces(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_FIGURE_ID = 0;
	m_NAME = "";
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CFaces::GetDefaultConnect()
{
	//return _T("ODBC;");
	return _T("DSN=LaboratoryWork01Source;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=OLEGLIPSKIY;DATABASE=laboratorywork01;");
}

CString CFaces::GetDefaultSQL()
{
	return _T("[dbo].[Faces]");
}

void CFaces::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[FIGURE_ID]"), m_FIGURE_ID);
	RFX_Text(pFX, _T("[NAME]"), m_NAME);

}
void CFaces::addRecord(int figureID)
{
	AddNew();
	m_ID = this->GetRecordCount();
	m_FIGURE_ID = figureID;
	m_NAME.Format(_T("%dFace%d"), figureID, m_ID);

	//Update();
}
/////////////////////////////////////////////////////////////////////////////
// CFaces diagnostics

#ifdef _DEBUG
void CFaces::AssertValid() const
{
	CRecordset::AssertValid();
}

void CFaces::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


