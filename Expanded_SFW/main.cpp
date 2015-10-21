#include "sfwdraw.h"
#include <iostream>
using namespace sfw;
using namespace std;

void main()
{
	char blerg = '#';

	//Note: I did not initContext with SCREEN_X and SCREEN_Y so you could see
	//		everything at it's standard 500x500 look. In your code, you're going to want 
	//      to use SCREEN_X and SCREEN_Y to initialize, so everything scales if/when you 
	//      change screen size. Try messing around with the values of the two here.
	initContext(765, 500, "SFW Test");

	while (stepContext())
	{
		//In order to print out a " ' " or a "\" or use them in  "getKey()" you'll have to notate them as:
		// '\'' and '\\' respectively.
		drawStringHor("ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789`-=[]\\;',./#:?", xSpace(1, 100), ySpace(47, 100), ySpace(6, 100), xSpace(2, 100), xSpace(1, 100));
	}
}