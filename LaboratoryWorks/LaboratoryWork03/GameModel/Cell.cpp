/**
 * Project LaboratoryWork03
 */

#include "stdafx.h"
#include "Cell.h"

/**
 * Cell implementation
 */

Cell::Cell() :
	_isApple(EMPTY), _cellFactor(0)
{
}

Cell::Cell(bool isApple) :
	_isApple(CellType(isApple)), _cellFactor(0)
{
}

void Cell::operator=(bool  cell)
{
	_isApple = (CellType)cell;
}



void Cell::operator=(Cell & cell)
{
	_isApple = cell._isApple;
	_cellFactor = cell._cellFactor;
}

void Cell::operator=(CellType celltype)
{
	_isApple = celltype;
}


Cell::operator int()
{
	return (int)_isApple;
}
