#include <graphics.h> 
#include <conio.h>
#include<stdio.h>
#include<bangtal.h>



typedef enum { UP, DOWN, LEFT, RIGHT, UNKOWN } DRCT;

const int level = 5;

DRCT getKey()
{
	char key;
	DRCT ret;
	key = _getch();

	switch (key)
	{
	case 'a':
	case 'A':
		ret = LEFT;
		break;
	case 's':
	case 'S':
		ret = DOWN;
		break;
	case 'd':
	case 'D':
		ret = RIGHT;
		break;
	case 'w':
	case 'W':
		ret = UP;
		break;
	default:
		ret = UNKOWN;
		break;

	}

	return ret;
}

void drawImage(int layout[level][level], IMAGE* pimg)
{
	int w, h;
	w = h = pimg->getwidth() / level;

	int x1, y1, x2, y2;

	setcolor(RGB(255, 255, 255));
	setfillcolor(RGB(0, 0, 0));

	for (int i = 0; i < level; ++i)
	{
		for (int j = 0; j < level; ++j)
		{
			x1 = j * w;
			y1 = i * h;

			if (layout[i][j] != -1)
			{
				x2 = layout[i][j] % level * w;
				y2 = layout[i][j] / level * h;
				putimage(x1, y1, w, h, pimg, x2, y2);
			}
			else
			{
				fillrectangle(x1, y1, x1 + w, y1 + h);
			}
		}
	}

	for (int i = 1; i < level; ++i)
	{
		line(0, i * h, pimg->getwidth(), i * h);
	}

	for (int i = 1; i < level; ++i)
	{
		line(i * w, 0, i * w, pimg->getheight());
	}
}

int isGameOver(int layout[level][level])
{
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			if (!(i == level - 1 && j == level - 1))
			{
				if (layout[i][j] != i * level + j)
				{
					return 0;
				}
			}
		}
	}

	return 1;
}
int updateLayout(int layout[level][level], DRCT d)
{
	int x = 0, t = 0;


	int row, col, i, j, a, b;
	for (i = 0; i < level; i++)
	{
		for (j = 0; j < level; j++)
		{
			if (layout[i][j] == -1)
			{
				a = i;
				b = j;
			}
		}
	}
	switch (d)
	{
	case UP: { row = a + 1; col = b; break; }
	case DOWN: { row = a - 1; col = b; break; }
	case LEFT: { row = a; col = b + 1; break; }
	case RIGHT: { row = a; col = b - 1; break; }
	default: {row = a, col = b; break; }
	}
	
	if (row<0 || row>level - 1 || col<0 || col>level - 1)
	{
		x = 0;
	}
	else
	{
		x = 1;
		t = layout[a][b];
		layout[a][b] = layout[row][col];
		layout[row][col] = t;
	}
	
	return x;
}

int main()
{
	int layout[level][level] =
	{
	0,1,2,3,4,
	5,6,7,8,9,
	10,11,12,13,14,
	15,16,17,18,19,
	20,21,-1,22,23
	};


	initgraph(850, 500); 

	IMAGE img, imgTip;
	loadimage(&img, _T("./image/0.png")); 
	loadimage(&img, _T("./image/1.png"));
	loadimage(&img, _T("./image/2.png"));
	loadimage(&img, _T("./image/3.png"));
	loadimage(&img, _T("./image/4.png"));
	loadimage(&img, _T("./image/5.png"));
	loadimage(&img, _T("./image/6.png"));
	loadimage(&img, _T("./image/7.png"));
	loadimage(&img, _T("./image/8.png"));
	loadimage(&imgTip, _T("./image/0.png"), 200, 200);
	drawImage(layout, &img);
	putimage(650, 0, &imgTip);

	while (!isGameOver(layout))
	{
		DRCT d = getKey();

		
		if (updateLayout(layout, d))
			drawImage(layout, &img);
	}
	putimage(0, 0, &img);
	outtextxy(100, 50, _T("good"));

	_getch();
	closegraph(); 
}