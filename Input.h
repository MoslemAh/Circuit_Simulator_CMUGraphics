#ifndef INPUT_H
#define INPUT_H

#include "DEFS.h"
#include "UI_Info.h" 
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Cell.h"

// forward declarations (their includes are in the cpp)
class Output;  

class Input		// The application manager & grid (phase 2) should have a pointer to this class
{
private:

	window *pWind;	// Pointer to the Graphics Windo

public:

	// ========== General Functions ==========

	Input(window* pW);  // Consturctor: Points to the passed window pointer

	void GetPointClicked(int& x, int& y) const; // Wait for a Mouse Click and Gets the real coordinates (x,y) of it

	string GetString(Output* pO) const;  // Returns a string entered by the user

	int GetInteger(Output* pO) const;    // Returns an integer entered by the user

	// ========== Simulator Functions ==========

	ActionType GetUserAction() const;	 // Reads a user click and map it to its corresponding ActionType

	Cell GetCellClicked() const; 

};

#endif