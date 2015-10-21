#pragma once

/*******************************************************************\
 * Simple Framework, sfw (really creative- I KNOW)                 *
 *                                                                 *
 * This framework is intended to provide the simplest possible     *
 * implementation of OpenGL for use in schools and demonstration.  *
 *                                                                 *
 * It hides the matrix stack, projection and view management and   *
 * pretty much anything else that is remotely interesting. It      *
 * currently uses immediate mode rendering- does not support       *
 * changing colors.                                                *
 *                                                                 *
 * It uses a fixed pixel-aligned orthographic viewport.            *
 *                                                                 *
 *                                                                 *
 * Author: Esmeralda Salamone, esmes@aie.edu.au                    *
\*******************************************************************/

#define PI 3.14159265359

namespace sfw
{
	/**********************************************************************\
	 * Initializes a very simple OpenGL rendering context (Window).       *
	 * This has fixed formatting ala 'pixel perfect': no camera support.  *
	 * 0,0 is the top-left corner.                                        *
	\**********************************************************************/
	void initContext(int width, int height, const char *title);

	/***********************************************************************\
	 *  Needs to be called each time the game loops. It's responsible for: *
	 *		Buffering the draws                                            *
	 *		polling input                                                  *
	 *		clearing out old buffer                                        *
	 *		update delta time                                              *
	\***********************************************************************/
	bool stepContext();

	/***********************************************\
	 *  Properly shuts down the windowing context. *
	\***********************************************/
	void termContext();

	/********************************************************************************\
	 *	The amount of time passed since the last stepContext was called.            *
	 *	Usually a very small number.                                                *
	 *	Useful for frame-independent movement (multiply this by an object's speed). *
	\********************************************************************************/
	float getDeltaTime();

	/***************************************************************************************\
	 * Determines whether a key was pressed.                                               *
	 * @param key, should be a character corresponding to the key you'd like to check for. *
	 *			special codes are not supported(?)                                         *
	\***************************************************************************************/
	bool getKey(char key);

	// draws a line from x1,y1 to x2,y2
	void drawLine(float x1, float y1, float x2, float y2);

	//draws a circly at pixel x,y with a radius of r
	void drawCircle(float x, float y, float r);

	/*************************************************************************\
	 *	Everything below this point is an expansion to SFW.                  *
	 *	While it doesn't add any visual functionality to it's capabilities,  *
	 *		it does make it so YOU don't have to do any excess work for GUI  *
	 *		implementation.                                                  *
	 *                                                                       *
	 *		Author:                                                          *
	 *		A. Connor "Silvainius" Adam, connor.adam@ymail.com               *
	 *		Last Edit: 10/20/2015                                            *
	\*************************************************************************/

	// In SFW_Draw.cpp \\

	extern float SCREEN_X;
	extern float SCREEN_Y;

	/* Allows for scaling positions/sizes for the UI on the X-Axis */
	float xSpace(float num, float den);
	/* Allows for scaling positions/sizes for the UI on the Y-Axis */
	float ySpace(float num, float den);

	/* Draws a box starting from the Top-Left Corner */
	void drawBox(float x, float y, float h, float w);
	/*******************************************************************\
	*  This function was desined to print at a 3:1 h/w ratio!         *
	*  While it CAN print other ratios, they might not look as good!  *
	*  Also: It draws from the TOP-LEFT corner!                       *
	\*******************************************************************/
	void drawChar(char a, float x, float y, float h, float w);
	/************************************************************************\
	* Sends an array of chars to drawChar().                               *
	* spcX is how far apart the chars are drawn inaddition to their width. *
	\************************************************************************/
	void drawStringHor(char text[], float x, float y, float h, float w, float spcX);
	/*************************************************************************\
	* Sends an array of chars to drawChar().                                *
	* spcX is how far apart the chars are drawn inaddition to their height. *
	\*************************************************************************/
	void drawStringVer(char text[], float x, float y, float h, float w, float spcY);

	// In SFW_Input.cpp \\

	/* Return true when the SELECT key is pressed */
	bool checkSel();

	/* Returns which menu option should be highlighted */
	int menuChoice(int opts, bool isVertical);
	/* returns an int value depending on which MOVE key was pressed*/
	int getControls();

	/* Returns any key supported by SFW when false. Only returns numbers when true. */
	char getInput(bool onlyNum);
}