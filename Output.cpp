#include "Output.h"

Output::Output()
{
	// Widths and Heights

	UI.TextBoxHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.width = 1200; // make it divisible by NumHorizontalCells
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;

	UI.NodeRadius = 10;

	UI.CellWidth = UI.width / NumHorizontalCells;
	UI.CellHeight = (UI.height - UI.ToolBarHeight - UI.TextBoxHeight) / NumVerticalCells;
	
	UI.NodeNumFont = 13;
	UI.NodeNumColor = WHITE;

	// Pen Colors of messages of text box
	UI.MsgColor = DARKRED;

	// Background Colors of toolbar and statusbar 
	UI.ToolBarColor = WHITE;
	UI.StatusBarColor = LIGHTGRAY;

	// Line Colors of the borders of each cell
	UI.GridLineColor = LIGHTGRAY;
	UI.NodeColor = RED;

	// Cell Color
	// UI.CellColor = LIGHTSLATEBLUE;

	// Create the output window
	pWind = CreateWind(UI.width + 15, UI.height, UI.wx, UI.wy);

	// Change the title
	pWind->ChangeTitle("Circuit Simulator");

	// Create the toolbar, grid area and status bar
	CreateToolBar();
	ClearGridArea();
	ClearTextBox();

}

////////////////////////////////////////////////////////////////////////////////////////// 

window* Output::CreateWind(int w, int h, int x, int y) const
{
	// The Window Object is created inside the Ouput class
	window* pW = new window(w, h, x, y);
	return pW;
}

////////////////////////////////////////////////////////////////////////////////////////// 

Input* Output::CreateInput() const
{
	// The Input Object is created inside the Output class
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Some Utility Functions									//
//======================================================================================//

int Output::GetCellStartX(const Cell& cellPos) const
{

	int cellStartX = cellPos.GetHCell() * UI.CellWidth;
	return cellStartX;

}

//////////////////////////////////////////////////////////////////////////////////////////

int Output::GetCellStartY(const Cell& cellPos) const
{

	int cellStartY = (cellPos.GetVCell() * UI.CellHeight) + UI.ToolBarHeight;
	return cellStartY;

}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//


void Output::ClearToolBar() const
{
	// Clear by drawing a rectangle filled with toolbar background color
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearTextBox() const
{
	// Clear drawing a rectangle filled with textbox background color
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.TextBoxHeight, UI.width, UI.height);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearGridArea() const
{
	// Draw each cell in the Grid: ( NumVerticalCells * NumberHorizontalCells )
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			Cell cellPos(i, j);
			DrawCell(cellPos);
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateToolBar() const
{
	ClearToolBar();

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// reoder them in UI_Info.h ==> enum DESIGN_MODE_ITEMS
	// ** MAKE SURE THAT THE IMAGES ARE .JPG FILES **
	string MenuItemImages[TOOLBAR_ITM_COUNT];
	MenuItemImages[ITM_ADD_NODE] = "images\\Menu_Add_Node1.jpg";
	MenuItemImages[ITM_ADD_RESISTOR] = "images\\Menu_Add_Resistor1.jpg";
	MenuItemImages[ITM_ADD_VOLTAGE_SOURCE] = "images\\Menu_Add_Voltage_Source1.jpg";
	MenuItemImages[ITM_ADD_CURRENT_SOURCE] = "images\\Menu_Add_Current_Source1.jpg";
	MenuItemImages[ITM_SOLVE] = "images\\Menu_Solve.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu_Exit.jpg";

	// Draw menu item one image at a time
	for (int i = 0; i < TOOLBAR_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearTextBox();	// First clear the status bar from any previous writing

	// Set pen and font before drawing the string on the window
	pWind->SetPen(UI.MsgColor);
	pWind->SetFont(18, BOLD, BY_NAME, "Verdana");
	pWind->DrawString(10, UI.height - (int)(UI.TextBoxHeight / 1.3), msg);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawCell(const Cell& cellPos) const
{
	// Get the X & Y of the Cell's upper left corner
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);
	int cellEndX = cellStartX + UI.CellWidth;
	int cellEndY = cellStartY + UI.CellHeight;

	pWind->SetPen(UI.GridLineColor, 1);
	pWind->DrawRectangle(cellStartX, cellStartY, cellEndX, cellEndY);

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawNode(const Cell& cellPos, int nodeNum) const
{
	int nodeCentreX = GetCellStartX(cellPos) + UI.CellWidth / 2;  // Center X of the node
	int nodeCentreY = GetCellStartY(cellPos) + UI.CellHeight / 2; // Center Y of the node

	// Draw Node Circle //
	pWind->SetBrush(UI.NodeColor);
	pWind->DrawCircle(nodeCentreX, nodeCentreY, UI.NodeRadius);

	// Draw Node Number in the center of the circle //
	pWind->SetPen(UI.NodeNumColor);
	pWind->SetFont(18, BOLD, BY_NAME, "Verdana");

	int textWidth = 0, textHeight = 0;

	// Get the size of the number (width and height)
	pWind->GetIntegerSize(textWidth, textHeight, nodeNum);

	// Position the text so it is centered
	int textX = nodeCentreX - textWidth / 2 - 0.5;
	int textY = nodeCentreY - textHeight / 2;

	// Draw the node number
	pWind->DrawInteger(textX, textY, nodeNum);


}


void Output::DrawResistor(const Node& nodeOne, const Node& nodeTwo) const
{
	Cell cellNodeOne = nodeOne.GetCell();
	Cell cellNodeTwo = nodeTwo.GetCell();
	int startX = GetCellStartX(cellNodeOne);
	int startY = GetCellStartY(cellNodeOne);
	int endX = GetCellStartX(cellNodeTwo);
	int endY = GetCellStartY(cellNodeTwo);

	// Horizontal resistor (same row)
	if (cellNodeOne.GetVCell() == cellNodeTwo.GetVCell())
	{
		// Calculate the length of wire before and after the resistor (half of the remaining distance)
		int x1 = startX + UI.CellWidth;
		int wireLength = (endX - x1 - 100) / 2;
		int x2 = x1 + wireLength;
		int y = startY + (UI.CellHeight / 2);

		// Draw wire before the resistor image
		pWind->SetPen(BLACK, 3); // Set wire color (adjust as needed)
		pWind->DrawLine(x1, y, x2, y); // Wire before image

		// Draw the resistor image (assumed width is 100)
		pWind->DrawImage("images\\Menu_Horizontal_Resistor.jpg", x2, startY, 100, 60); // Image of the resistor

		// Draw wire after the resistor image
		pWind->SetPen(BLACK, 3); // Set wire color (adjust as needed)
		pWind->DrawLine(x2 + 100, y, endX, y); // Wire after image
	}
	// Vertical resistor (same column)
	else if (cellNodeOne.GetHCell() == cellNodeTwo.GetHCell())
	{
		// Calculate the length of wire before and after the resistor (half of the remaining distance)
		int x = startX + (UI.CellWidth / 2);
		int y1 = startY + UI.CellHeight;
		int wireLength = (endY - y1 - 100) / 2;
		int y2 = y1 + wireLength;

		// Draw wire before the resistor image
		pWind->SetPen(BLACK, 3); // Set wire color (adjust as needed)
		pWind->DrawLine(x, y1, x, y2); // Wire before image

		// Draw the resistor image (assumed height is 100)
		pWind->DrawImage("images\\Menu_Vertical_Resistor.jpg", startX, y2, 60, 100); // Image of the resistor

		// Draw wire after the resistor image
		pWind->SetPen(BLACK, 3); // Set wire color (adjust as needed)
		pWind->DrawLine(x, y2 + 100, x, endY); // Wire after image
	}
	else
	{
		// In case diagonals
		cerr << "Invalid connection: Resistors must be horizontal or vertical." << endl;
	}
}



void Output::DrawVoltageSource(const Cell& fromCellPos, const Cell& toCellPos) const
{

}

void Output::DrawCurrentSource(const Cell& fromCellPos, const Cell& toCellPos) const
{

}

Output::~Output()
{
	// deallocating the window object
	delete pWind;
}