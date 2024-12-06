#include "Input.h"

#include "Output.h"

//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW) 
{
	pWind = pW; // point to the passed window
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->FlushMouseQueue();
	pWind->WaitMouseClick(x, y); // Note: x and y of WaitMouseClick are sent by reference
}

////////////////////////////////////////////////////////////////////////////////////////// 

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if(Key == 13 )	// ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

////////////////////////////////////////////////////////////////////////////////////////// 

int Input::GetInteger(Output *pO) const 
{

	string input = GetString(pO);
	// Checking if String is Numeric
	for (int i = 0; i < input.length(); i++)
	{
		if (!isdigit(input.at(i)))
		{
			return -1;
		}
	}

	int num = (stoi(input) >= 0) ? stoi(input) : -1;

	return num;
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	// [1] If user clicks on the Toolbar
	if (y >= 0 && y < UI.ToolBarHeight)
	{
		// Check which Menu item was clicked
		// ==> This assumes that menu items are lined up horizontally <==

		int ClickedItemOrder = (x / UI.MenuItemWidth);

		// Divide x coord of the point clicked by the menu item width (integer division)
		// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

		switch (ClickedItemOrder)
		{
		case ITM_ADD_NODE: return ADD_NODE;
		case ITM_ADD_RESISTOR: return ADD_RESISTOR;
		case ITM_ADD_VOLTAGE_SOURCE: return ADD_VOLTAGE_SOURCE;
		case ITM_ADD_CURRENT_SOURCE: return ADD_CURRENT_SOURCE;
		case ITM_SOLVE: return SOLVE;
		case ITM_EXIT: return EXIT;

		default: return EMPTY;	// A click on empty place in toolbar
		}
	}

	// [2] User clicks on the grid area
	if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.TextBoxHeight))
	{
		return GRID_AREA;
	}

	// [3] User clicks on the status bar
	return TEXTBOX;

}

////////////////////////////////////////////////////////////////////////////////////////// 

Cell Input::GetCellClicked() const
{
	int x,y;
	pWind->WaitMouseClick(x, y);	// Get the coordinates of the user click

	Cell cellPos;

	if (y >= UI.ToolBarHeight && y <= (UI.height - UI.TextBoxHeight))
	{

		cellPos.SetHCell(x / UI.CellWidth);
		cellPos.SetVCell((y / UI.CellHeight) - 1);

	}
	// If Click Not on a Cell
	else
	{
		cellPos.SetHCell(-1);
		cellPos.SetVCell(-1);
	}

	return cellPos;
}

////////////////////////////////////////////////////////////////////////////////////////// 
