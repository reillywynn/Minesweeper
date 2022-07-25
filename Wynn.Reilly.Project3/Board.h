#pragma once
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Random.h"



using namespace std;

class Board
{
private:
	int row;
	int col;
	int flagCount = 0;
	bool win = false;
	bool lose = false;
	bool running = true;
	bool debug = false;
	int mineCount = 50;
	vector <string> test;
	
public:
	Tile _board[16][25];
	Board();
	void SetMineCount(int mines);
	void SetWin();
	bool GetLose();
	void SetLose();
	void NewBoard();
	void SmileyButton();
	void RandomMines();
	int Surrounding(int row, int col);
	void SetNumbers();
	void flagCountUp();
	void flagCountDown();
	int GetFlags();
	void uncover(int x, int y);
	bool GetWin();
	bool GetRunning();
	void SetDebug();
	bool GetDebug();
	int GetMineCount();
	void loadBoard(string filename);
	
};

