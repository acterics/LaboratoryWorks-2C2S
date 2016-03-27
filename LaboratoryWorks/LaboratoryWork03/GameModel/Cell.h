/**
 * Project LaboratoryWork03
 */

#ifndef _CELL_H
#define _CELL_H

enum CellType {
	EMPTY,
	APPLE,
	APPLEWAY,
	PASSED,
	EATEN

};

class Cell {
public:
	Cell();
	Cell(bool isApple);

	void operator=(bool cell);
	void operator=(Cell& cell);
	void operator=(CellType celltype);
	operator int();

	int _cellFactor;


protected: 
	CellType  _isApple;

};

#endif //_CELL_H