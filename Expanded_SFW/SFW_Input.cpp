
/*********************************************************************************************\
 *	IMPORTANT:                                                                               *
 *                                                                                           *
 *	None of the input reader methods work unless 'initContext()' is called AND you are in a  *
 *	'while(stepContext())' loop!                                                             *
\*********************************************************************************************/

#include "sfwdraw.h"

int sel = 0;

char bindings[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789`-=[]\\;',./"; //Holds a value that "getKey()" can use for every valid key
bool bindPress[48] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

char key[5] = { 'W', 'S', 'A', 'D', ' ' }; //Holds a value for every BOUND key.
bool keyPress[5] = { 0, 0, 0, 0, 0 }; 

void resetKeys()
{
	for (int a = 0; a < 5; ++a)
	{
		if (!sfw::getKey(key[a]) && keyPress[a]) { keyPress[a] = false; }
	}

	for (int a = 0; bindings[a] != '\0'; ++a)
	{
		if (!sfw::getKey(bindings[a]) && bindPress[a]) { bindPress[a] = false; }
	}

	if (!sfw::getKey(' ') && bindPress[26]) { bindPress[26] = false; }
}

bool sfw::checkSel()
{
	if (getKey(key[4]) && !keyPress[4])
	{
		keyPress[4] = true;
		if (key[4] == ' ') { bindPress[26] = true; }
		else
		{
			for (int a = 0; bindings[a] != '\0'; a++)
			{
				if (key[4] == bindings[a]) { bindPress[a] = true; }
			}
		}
		return true;
	}
	else
	{
		resetKeys();
		return false;
	}
}
int sfw::getControls()
{
	for (int a = 0; a < 4; a++)
	{
		if (getKey(key[a]) && !keyPress[a])
		{
			keyPress[a] = true;
			return a;
		}
	}

	resetKeys();
	return -1;
}
int sfw::menuChoice(int opts, bool isVertical)
{
	opts -= 1;

	if (isVertical)
	{
		/********************************************************\
		* This isn't one switch becasue that would allow the   *
		* "sideways" keys to function in vertical menus, which *
		* I find undesireable.                                 *
		\*******************************************************/
		switch (getControls())
		{
		case 0:
			sel--;
			break;
		case 1:
			sel++;
			break;
		}
	}
	else if (!isVertical)
	{
		switch (getControls())
		{
		case 2:
			sel--;
			break;
		case 3:
			sel++;
			break;
		}
	}

	if (sel > opts) { sel = 0; }
	else if (sel < 0) { sel = opts; }

	resetKeys();
	return sel;
}
char sfw::getInput(bool onlyNum)
{
	char press = '#';

	if (!onlyNum)
	{
		for (int a = 0; bindings[a] != '\0'; a++)
		{
			if (getKey(bindings[a]) && !bindPress[a])
			{
				press = bindings[a];
				bindPress[a] = true;
			}
		}
	}
	else
	{
		for (int a = 27; bindings[a] != '`'; a++)
		{
			if (getKey(bindings[a]) && !bindPress[a])
			{
				press = bindings[a];
				bindPress[a] = false;
			}
		}
	}

	resetKeys();
	return press;
}

char getLetInput()
{
	char bindTo = '#';

	for (int a = 0; bindings[a] != '\0'; ++a)
	{
		if (!bindPress[a] && sfw::getKey(bindings[a]))
		{
			bindTo = bindings[a];
			bindPress[a] = true;
		}
	}

	if (bindTo == bindings[44]) { bindTo = '"'; }
	resetKeys();
	return bindTo;
}