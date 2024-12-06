#ifndef OUPTUT_H
#define OUPTUT_H

#include "DEFS.h"
#include "UI_Info.h" 
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Cell.h"
#include "Node.h"
#include "Input.h"
#include <iostream>

// forward declarations (their includes are in the cpp)
class Input;

class Output
{
private:	

	window* pWind;	// Pointer to the Graphics Window
	
	// ========== Some Utility Functions (Private Functions) ==========

	int GetCellStartX(const Cell& cellPos) const;	// Gets the X coordinate 
	
	int GetCellStartY(const Cell& cellPos) const;	// Gets the Y coordinate 

	void ClearToolBar() const;	// Clears the toolbar by drawing a filled rectangle

public:

	Output();	// A Constructor for any needed initializations

	window* CreateWind(int, int, int , int) const; // Creates the application window

	Input* CreateInput() const;	// Creates a pointer to the Input object	

	// ========== User Interface Functions ==========
	
	void ClearTextBox() const;		// Clears the textbox by drawing a filled rectangle
	void ClearGridArea() const;	    // Draws an empty grid (horizontal and vertical lines with empty cells)
	// ClearGridArea MAYBE NOT NEEDED

	void CreateToolBar() const;	// Creates the Toolbar with all its menu icons

	void PrintMessage(string msg) const;	// Prints a message on Status bar

	// ========== Circuit Drawing Functions ==========

	void DrawCell(const Cell& cellPos) const;	// Draws "Cell Rectangle"

	void DrawNode(const Cell& cellPos, int nodeNum) const;

	// will be modified to receive node1 & node2 then create the resistor component
	void DrawResistor(const Node& nodeOne, const Node& nodeTwo) const;

	// will be modified to receive node1 & node2 then create the voltage source component
	void DrawVoltageSource(const Cell& fromCellPos, const Cell& toCellPos) const;

	// will be modified to receive node1 & node2 then create the current source component
	void DrawCurrentSource(const Cell& fromCellPos, const Cell& toCellPos) const;

	// void DrawWire() const;

	~Output();	// A Destructor for any needed deallocations
};

#endif