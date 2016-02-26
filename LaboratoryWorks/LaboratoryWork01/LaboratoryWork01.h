
// LaboratoryWork01.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLaboratoryWork01App:
// See LaboratoryWork01.cpp for the implementation of this class
//

class CLaboratoryWork01App : public CWinApp
{
public:
	CLaboratoryWork01App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLaboratoryWork01App theApp;