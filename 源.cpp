#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<bangtal.h>



SceneID scene1；;

ObjectID startButton；;

IMAGE img[9]; 

int picture[3][3] = { 1，2，3，4，5，6，7，8，0 }；

void Rand（）
{
	int anum；
	int size = 9；
	int a[9] = {0，1，2，3，4，5，6，7，8}；

	for（int i = 0； i＜3；i++）
	{
		for（int j = 0；j＜3；j++）
	{
		anum = rand（） % size；
		picture[i][j] = a[anum]；

	 for（int k =anum；k ＜ size；k++）
	{
		a[k] = a[k+1]；
}
    size--；
}
}
}








void GameInit（）
{
	Rand（）；


	loadimage（ & img[0]，L"0.png"，400，200）；
	loadimage（ & img[1]，L"1.png"，400，200）；
	loadimage（ & img[2]，L"2.png"，400，200）；
	loadimage（ & img[3]，L"3.png"，400，200）；
	loadimage（ & img[4]，L"4.png"，400，200）；
	loadimage（ & img[5]，L"5.png"，400，200）；
	loadimage（ & img[6]，L"6.png"，400，200）；
	loadimage（ & img[7]，L"7.png"，400，200）；
	loadimage（ & img[8]，L"8.png"，400，200）；
}

void mousecallbcak(ObjictID object, int x, int y, MouseAction action) {
	if (object == startButton) {
		endGame();
	}
}





void DrawPicture()
{
	for (int i = 0; i＜3；i++)
	{
		for（int j =0；j＜3；j++）
		{
			switch（picture[i][j]）
			{
		     case 0 ：
			 putimage（i * 400，j* 200，&img[0]）；
			 break ；
			 case 1 ：
			 putimage（i * 400， j* 200，&img[8]） ；
			 break ；
			 case 2 ：
			 putimage（i * 400，j * 200， & img[3]）；
			 break ；
			 case 3 ：
			 putimage（i * 400， j * 200， & img[6]） ；
			 break ；
			 case 4 ：
			 putimage（i * 400，j * 200， & img[1]）；
			 break ；
			 case 5 ：
			 putimage（i * 400， j * 200， & img[4]） ；
			 break ；
			 case 6 ：
			 putimage（i * 400，j * 200， & img[7]）；
			 break ；
			 case 7 ：
			 putimage（i * 400， j * 200， & img[2]）；
			 break ；
			 case 8 ：
			 putimage（i * 400， j * 200，& img [5]） ；
			 break ；


			default ：
			     break ；

            }
		}
	}
}








void PlayGame（）
{
	int row， col；
	int zeroR，zeroC；



	MOUSEMSG msg；

	msg = GetMouseMsg（）；

	switch (msg.uMsg)
	{
	case WM_LBUTTIONDOWN :

		if （msg.x ＞=0 && msg.x ＜400）
		{
			row = 0；
		}
		else if （msg.x ＞= 400 && msg.x＜ 800）
		{
			row = 1；
		}
		else if（msg.x ＞=800 && msg.x ＜= 1200）
		{
			row = 2；
		}

		if（msg.y ＞=0 && msg.y ＜200）
		{
			col = 0 ；
         }
		else if（msg.y ＞=200 && msg.y ＜400）
		{
		   col = 1；
         }
		 else if（msg.y＞= 400 && msg.y ＜= 600）
		 {
		   col = 2；
         }


		 for（int i = 0 ；i ＜ 3；i++）
		 {
		    for （int j = 0；j ＜ 3；j++）
			{
				if（picture[i][j] == 0）
				{
					zeroR = i；
					zeroC = j；
			    }
			}
         }

		 if （row == zeroR && col == zeroC - 1）
		 {
			 picture[zeroR][zeroC] = picture[row][col]；
			 picture[row][col] = 0；
		 }

		 if（row ==zeroR && col == zeroC + 1）
		 {
			 picture[zeroR][zeroC] = picture[row][col]；
			 picture[row][col] = 0；
		 }

		 if（row == zeroR - 1 && col ==zeroC）
		 {
			 picture[zeroR][zeroC] = picture[row][col]；
			 pictur[row][col] = 0；
		 }


		 if（row ==zeroR + 1 && col ==zeroC）
		 {
			 picture[zeroR][zeroC] = picture[row][col]；
			 picture[row][col] = 0；
		 }

			 break ；
	}
	
}



int main（）
{
	setMouseCallback（mousecallback）；
	scene1 = createScene（"퍼즐 맞추기 게임","background.png"）；

	startGame（scene1）；


	srand（（unsigned int）time（NULL））；
	initgraph（1200，600）；
	GameInit（）；

	while（1）
	{
		DrawPicture（）；
		PlayGame（）；
    }







	getchar（）；
	closegraph（）；
	return 0；
}










