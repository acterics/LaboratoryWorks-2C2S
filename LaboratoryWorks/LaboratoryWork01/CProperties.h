// CProperties.h : Declaration of the CProperties

#pragma once

// code generated on 4 марта 2016 г., 2:31

class CProperties : public CRecordset
{
public:
	CProperties(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CProperties)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	long	m_ID;
	long	m_FIGURE_ID;
	long	m_FACE_ID;
	CString	m_NAME;
	float	m_VALUE;

// Overrides
	// Wizard generated virtual function overrides
	public:
	virtual CString GetDefaultConnect();	// Default connection string

	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support

	void addRecord(CString name, float value, long figureID, long faceID = -1);

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


