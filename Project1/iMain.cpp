#include "iGraphics.h"

#include <iostream>
using namespace std;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int scr_width = 1200;
int scr_height = 800;
int musicon = 1;
int x, y;
int r = 255;
int g = 255;
int b = 255;
int ball_rad = 15;
int bx, by;
int gameover = 0;
int dx = 10;
int dy = 10;

void iDraw()
{
	iClear();
	/*
	//iRectangle(500, 300, 200, 200);
	iSetColor(r, g, b);
	iRectangle(x+250, y+150, 700, 350);
	//iSetColor(0, 255, 255);
	iRectangle(x + 350, y + 330, 100, 80);
	iRectangle(x + 750, y + 330, 100, 80);
	//iSetColor(255, 0, 0);
	iRectangle(x + 550, y + 152, 50, 200);
	iRectangle(x + 600, y + 152, 50, 200);
	//iSetColor(255, 255, 0);
	iLine(x + 210, y + 500, x + 600, y + 600);
	iLine(x + 990, y + 500, x + 600, y + 600);
	//iSetColor(255, 0, 0);
	iLine(x + 210, y + 500, x + 990, y + 500);  
	*/
	
	//iFilledRectangle(x, y, 1200, 800);
	iSetColor(r, g, b);
	iFilledCircle( x , y + 50 , 20);
	iSetColor(50, 150, 150);
	iFilledRectangle(bx, by, 150, 50);
	//iShowBMP(0, 0, "photos//sample_640×426.bmp");
	
}


void change()
{
	x += dx;
	y += dy;
	
	if (x  == 1200 || x  <= 0)
	{
		dx *= (-1);
	}
	if (y + 50 == 800) 
	{
		dy *= (-1);
	}
	else if ((y == 0) && (x >= bx && x <= bx + 150))
	{
		dy *= (-1);
	}
	
	
	
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;

}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	//bx = mx ;
	//y = my - 150;
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		y += 10;
	}
	else if (key == 'a')
	{
		x -= 10;
	}
	else if (key == 's')
	{
		y -= 10;
	}
	else if (key == 'd')
	{
		x += 10;
	}
	else if (key == 'r')
	{
		r = 255;
		g = 0;
		b = 0;
	}
	else if (key == 'g')
	{
		r = 0;
		g = 255;
		b = 0;
	}
	else if (key == 'b')
	{
		r =  0;
		g =  0;
		b = 255;
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		if (bx <= scr_width - 150)
			bx += 10;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		if (bx > 0)
			bx -= 10;
	}
	
	else if (key == GLUT_KEY_UP)
	{
		PlaySound("Music//1.wav", NULL, SND_LOOP | SND_ASYNC);

	}
	else if (key == GLUT_KEY_DOWN)
	{
		PlaySound(0,0,0);
	}
	
}


int main()
{
	
		iSetTimer(30, change);
		
		//cout << x << y << endl;
		///srand((unsigned)time(NULL));
		//iText(400, 380, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
		
		if (musicon)
		{
			PlaySound("Music//1.wav", NULL, SND_LOOP | SND_ASYNC);
		}
		iInitialize(scr_width,scr_height, "Birds hunting");
		
		///updated see the documentations
		iStart();
	 
	return 0;
}