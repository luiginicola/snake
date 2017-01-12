#include <iostream>
#include <conio.h>
using namespace std;
bool game_over;
const int width = 20;
const int height = 20;
int score;
enum move_direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
move_direction theDirection;
struct food{
	int x;
	int y;
};
struct heads{
	int x;
	int y;
};
heads head;
food fruit;
void setup()
{
	game_over = false;
	theDirection = STOP;
	head.x = width / 2;
	head.y = height / 2;
	fruit.x = rand() % width;
	fruit.y = rand() % height;
	score = 0;
}
void draw()
{
	system("cls");
	for (int top = 0; top <= width; top++)
		cout << "#";
	cout << endl;
	for (int side = 0; side < height; side++)
	{
		for (int sidew = 0; sidew < width; sidew++)
		{
			if (sidew == 0)
				cout << "#";
			if (side == head.y && sidew == head.x)
				cout << "O";
			else if (side == fruit.y && sidew == fruit.x)
				cout << "F";
			else cout << " ";
			if (sidew == width - 2)
				cout << "#";
		}
		cout << endl;
	}
	for (int bottom = 0; bottom <= width; bottom++)
		cout << "#";
	cout << endl;
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			theDirection = LEFT;
			break;
		case 'd':
			theDirection = RIGHT;
			break;
		case 'w':
			theDirection = UP;
			break;
		case 's':
			theDirection = DOWN;
			break;
		case 'x':
			game_over = true;
			break;
		}
	}
}
void logic()
{
	switch (theDirection)
	{
	case UP:
		head.y--;
		break;
	case DOWN:
		head.y++;
		break;
	case LEFT:
		head.x--;
		break;
	case RIGHT:
		head.x++;
		break;
	default:
		break;
	}
}
int main()
{
	setup();
	while (!game_over)
	{
		draw();
		input();
		logic();
	}
	return 0;
}