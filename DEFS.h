#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType
{
	// Actions

	ADD_NODE,
	ADD_RESISTOR,
	ADD_VOLTAGE_SOURCE,
	ADD_CURRENT_SOURCE,
	SOLVE,
	EXIT,

	// Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	TEXTBOX 			// Inside TextBox Area
};

#endif