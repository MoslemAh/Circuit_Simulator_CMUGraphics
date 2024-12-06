#pragma once
class Cell
{
	int vCell; // the vertical cell number: starts from 0 to NumVerticalCells - 1
	int hCell; // the horizontal cell number: starts from 0 to NumHorizontalCells - 1

public:
	Cell(); // Initializes the cell to (-1,-1) indicating not initialized with valid values
	Cell(int v, int h); // Sets vCell and hCell if valid


	bool SetVCell(int v);
	bool SetHCell(int h);

	int GetVCell() const; // The getter of vCell
	int GetHCell() const; // The getter of hCell

	bool IsValidCell() const; // Checks if the current cell position (vCell and hCell) both are valid then return true
	// Otherwise, return false
};

