#ifndef UI_INFO_H
#define UI_INFO_H

#include "CMUgraphicsLib\CMUgraphics.h"

// User Interface information file.
// This file contains info that is needed by Input and Output classes to
// handle the user interface

#define NumHorizontalCells 60
#define NumVerticalCells 30

enum TOOLBAR_ITEMS
{
	// Note: Items are ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_ADD_NODE,
	ITM_ADD_RESISTOR,
	ITM_ADD_VOLTAGE_SOURCE,
	ITM_ADD_CURRENT_SOURCE,
	ITM_SOLVE,
	ITM_EXIT,

	TOOLBAR_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};


__declspec(selectany) // This line to prevent "redefinition error"

struct UI_Info	// User Interface Info.
{

	int	width, height,			// Window width and height
		wx, wy,					// Window starting coordinates
		TextBoxHeight,			// Status Bar Height
		ToolBarHeight,			// Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;			// Width of each item in toolbar menu

	int CellHeight;				// Height of 1 CELL
	int CellWidth;				// Width of 1 CELL

	color MsgColor;				// Messages color (usually used in statusbar)
	color CellColor;			// Cell color ( maybe not needed )

	int NodeNumFont;			// Font size of cell numbers
	color NodeNumColor;			// Cell number color

	color ToolBarColor;			// Toolbar color (toolbar background)
	color StatusBarColor;		// Statusbar color (statusbar background)

	int NodeRadius;
	color NodeColor;

	color GridLineColor;		// Color of the Lines separating adjacent cells

} UI;	// create a global object UI
#endif