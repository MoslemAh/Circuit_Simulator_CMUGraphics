#include "Cell.h"

Cell::Cell()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

Cell::Cell(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

bool Cell::SetVCell(int v)
{

	if (v >= 0 && v <= 29)
	{
		vCell = v;
		return true;
	}

	return false;
}

bool Cell::SetHCell(int h)
{

	if (h >= 0 && h <= 59)
	{
		hCell = h;
		return true;
	}

	return false;
}

int Cell::GetVCell() const
{
	return vCell;
}

int Cell::GetHCell() const
{
	return hCell;
}

bool Cell::IsValidCell() const
{

	if ((GetVCell() >= 0 && GetVCell() <= 29) && (GetHCell() >= 0 && GetHCell() <= 59))
	{
		return true;
	}

	return false;
}