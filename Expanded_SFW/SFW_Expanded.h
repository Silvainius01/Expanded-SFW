#pragma once
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include "sfwdraw.h"
using namespace sfw;
using namespace std;

//In menuDraw.cpp
extern float xSpace(float num, float den);
extern float ySpace(float num, float den);

extern void drawChar(char a, float x, float y, float h, float w);
extern void drawStringHor(char text[], float x, float y, float h, float w, float spcX);
extern void drawStringVer(char text[], float x, float y, float h, float w, float spcY);
extern void drawBox(float x, float y, float h, float w);
extern void restartScreen();
extern void drawTestMenu();

//in menuSel.cpp
extern int sel;
extern int menuChoice(int opts, bool isVertical);
extern int getControls();

extern bool checkSel();

extern char key[5];
extern char getNumInput();
extern char getLetInput();