#include "Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output * pOut = new Output();
	Input * pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test classes of phase 1, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 0:	
	//			Create The FULL Tool bar of Design Mode, the grid area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar, Grid and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Testing the Output Class
	///////////////////////////////////////////////////////////////////////////////////

	Cell cellNodeOne(8, 8);
	Cell cellNodeTwo(8, 15);
	Cell cellNodeThree(20, 8);

	Node Node1(cellNodeOne, 1);
	Node Node2(cellNodeTwo, 2);
	Node Node3(cellNodeThree, 3);

	pOut->DrawNode(cellNodeOne, 1);
	pOut->DrawNode(cellNodeTwo, 2);
	pOut->DrawNode(cellNodeThree, 3);

	pOut->DrawResistor(Node1, Node2);
	pOut->DrawResistor(Node1, Node3);
	

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class - Part 1
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST3: Now Time to test class [ Input ], Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.1- Getting Integer ///
	/// ===========================
	pOut->PrintMessage("3.1- (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	int number = pIn->GetInteger(pOut);
	pOut->PrintMessage("You Entered: " + to_string(number));
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("FINISHED - (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.2- Getting Cell Clicked /// WRONG VCELL VALUES
	/// =========================
	pOut->PrintMessage("3.2- (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	for (int i = 0; i < 5; i++)
	{
		Cell cellClicked = pIn->GetCellClicked();
		if (cellClicked.GetVCell() == -1 || cellClicked.GetHCell() == -1) // can use IsValidCell
		{
			pOut->PrintMessage("Not A Cell");
			pIn->GetPointClicked(x, y);
			continue;
		}
		pOut->PrintMessage("vCell: " + to_string(cellClicked.GetVCell()) + " | hCell: " + to_string(cellClicked.GetHCell()));
	}

	pOut->PrintMessage("FINISHED - (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	/// 3.3- Reading a String ///
	/// =====================
	pOut->PrintMessage("3.3- (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	string text = pIn->GetString(pOut);
	pOut->ClearTextBox();
	pOut->PrintMessage("You Entered: " + text);
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("FINISHED - (GetSrting) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4:	
	//			Test the functions of CellPosition Class
	///////////////////////////////////////////////////////////////////////////////////


/*
	pOut->PrintMessage("TEST4: Testing the [ CellPosition ] class, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.1- (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	Cell cellpos_1(0, 0);

	for (int i = 0; i < 5; i++)
	{
		number = pIn->GetInteger(pOut);
		if (!cellpos_1.SetVCell(number))
		{
			pOut->PrintMessage("Invalid vCell Number");
			pIn->GetPointClicked(x, y);
			continue;
		}
		pOut->PrintMessage("Now the vCell = " + to_string(cellpos_1.GetVCell()));
		pIn->GetPointClicked(x, y);
	}

	for (int i = 0; i < 5; i++)
	{
		number = pIn->GetInteger(pOut);
		if (!cellpos_1.SetHCell(number))
		{
			pOut->PrintMessage("Invalid hCell Number");
			pIn->GetPointClicked(x, y);
			continue;
		}
		pOut->PrintMessage("Now the hCell = " + to_string(cellpos_1.GetHCell()));
		pIn->GetPointClicked(x, y);
	}

	pOut->PrintMessage("FINISHED - (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

*/
	

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 5: 
	//			Input Class - Part2: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST5: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_NODE:
			pOut->PrintMessage("Action: ADD_NODE , Click anywhere");
			break;

		case ADD_RESISTOR:
			pOut->PrintMessage("Action: ADD_RESISTOR , Click anywhere");
			break;

		case ADD_VOLTAGE_SOURCE:
			pOut->PrintMessage("Action: ADD_VOLTAGE_SOURCE , Click anywhere");
			break;

		case ADD_CURRENT_SOURCE:
			pOut->PrintMessage("Action: ADD_CURRENT_SOURCE , Click anywhere");
			break;

		case SOLVE:
			pOut->PrintMessage("Action: SOLVE , Click anywhere");
			break;

		case EXIT:				
			break;

		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


