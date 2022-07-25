#include "Board.h"


bool Board::GetLose() {
	return lose;
}

void Board::NewBoard() {
	for (int i = 0; i < 16; i++) {
		
		for (int j = 0; j < 25; j++) {
			_board[i][j]._x = i;
			_board[i][j]._y = j;
		}
	}
}

void Board::SmileyButton() {
	flagCount = 0;
	memset(_board, 0, sizeof(_board[0][0]) * 16 * 25);
	
	NewBoard();
	RandomMines();
	SetNumbers();
}

void Board::RandomMines() {
	int mines = 0;
	while (mines < 50) {
		int row = Random::Int(0, 15);
		int col = Random::Int(0, 24);
		if (_board[row][col].GetMine() == false) {
			_board[row][col].SetMine();
			mines++;
		}
		
	}
}

int Board::Surrounding(int row, int col) {
	int mineCount = 0;
	
	if (row != 0) { 
		if (_board[row-1][col].GetMine() == true) { //up
			mineCount++;
			_board[row-1][col].mines++;
		}
		
	}

	if (row != 15) {
		if (_board[row+1][col].GetMine() == true) { //down
			mineCount++;
			_board[row+1][col].mines++;
		}
		
	}

	if (col != 0) {
		if (_board[row][col-1].GetMine() == true) { //left
			mineCount++;
			_board[row][col-1].mines++;
		}
		
	}

	if (col != 24) {
		if (_board[row][col+1].GetMine() == true) { //right
			mineCount++;
			_board[row][col+1].mines++;
		}
		
	}

	if (row != 0 && col != 0) {
		if (_board[row-1][col-1].GetMine() == true) { //up left
			mineCount++;
			_board[row-1][col-1].mines++;
		}
		
	}

	if (row != 0 && col != 24) {
		if (_board[row-1][col+1].GetMine() == true) { //up right
			mineCount++;
			_board[row-1][col+1].mines++;
		}
		
	}

	if (row != 15 && col != 0 ) {
		if (_board[row+1][col-1].GetMine() == true) { //down left
			mineCount++;
			_board[row+1][col-1].mines++;
		}
		
	}

	if (row != 15 && col != 24) {
		if (_board[row+1][col+1].GetMine() == true) { //down right
			mineCount++;
			_board[row+1][col+1].mines++;
		}
		
	}

	return mineCount;
}

void Board::SetNumbers() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 25; j++) {
			if (_board[i][j].GetMine() == false) {
				int mineCount = Surrounding(i, j);
				_board[i][j].SetNumTile(mineCount);
				_board[i][j].SetBoolNum();
			}
		}
	}
}


void Board::flagCountUp() {
	flagCount++;
}

void Board::flagCountDown() {
	flagCount--;
}

int Board::GetFlags() {
	return flagCount;
}

void Board::uncover(int x, int y) {
	
	if (_board[x][y].GetFlag() == false && _board[row][col].GetReveal() == false) {
		_board[x][y].SetReveal();
	}
	

	if (_board[x][y].GetMine() == true) {
		lose = true;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 25; j++) {
				if (_board[i][j].GetMine() == true) {
					_board[i][j].SetReveal();
				}
			}
		}
	}
}



bool Board::GetWin() {
	return win;
}

bool Board::GetRunning() {
	return running;
}

Board::Board() {
	NewBoard();
	RandomMines();
	SetNumbers();
}

void Board::SetDebug() {
	debug = true;
}

bool Board::GetDebug() {
	return debug;
}

int Board::GetMineCount() {
	return mineCount;
}

void Board::loadBoard(string filename) {
	flagCount = 0;
	memset(_board, 0, sizeof(_board[0][0]) * 16 * 25);
	

	ifstream inFile(filename);
	string data;
	while (getline(inFile, data)) test.push_back(data);
	
	NewBoard();
	int count = 0;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 25; j++) {
			char mine = test[i][j];

			if (mine == '1') {
				count++;
				_board[i][j].SetMine();
				_board[i][j].SetReveal();
				
			}
		}
	}
	SetMineCount(count);
	SetNumbers();
}

void Board::SetMineCount(int mines) {
	mineCount = mines;
}

void Board::SetLose() {
	lose = false;
}

void Board::SetWin() {
	win = true;
}
















































//if (_board[x][y].GetFlag() == false && _board[x][y].GetReveal() == false) {
//	_board[x][y].SetReveal();
//
//	if (row != 0) {
//		if (_board[x - 1][y].GetReveal() == false && _board[x][y].GetMine() == false) {
//			uncover(x - 1, y);
//		}
//	}
//
//	if (row != 15) {
//		if (_board[x + 1][y].GetReveal() == false && _board[x][y].GetMine() == false) {
//			uncover(x + 1, y);
//		}
//	}
//
//	if (col != 0) {
//		if (_board[x][y - 1].GetReveal() == false && _board[x][y].GetMine() == false) {
//			uncover(x, y - 1);
//		}
//	}
//
//	if (col != 24) {
//		if (_board[x + 1][y + 1].GetReveal() == false && _board[x][y].GetMine() == false) {
//			uncover(x + 1, y + 1);
//		}
//	}
//
//	if (row != 0 && col != 0) {
//		if (_board[x - 1][y - 1].GetReveal() == false && _board[x][y].GetMine() == false) {
//			uncover(x - 1, y - 1);
//		}
//	}
//
//	if (row != 0 && col != 24) {
//		if (_board[x - 1][y + 1].GetReveal() == false && _board[x][y].GetMine() == false) {
//			uncover(x - 1, y + 1);
//		}
//	}
//
//	if (row != 15 && col != 0) {
//		if (_board[x + 1][y - 1].GetReveal() == false && _board[x][y].GetMine() == false) {
//			uncover(x + 1, y - 1);
//		}
//	}
//
//	if (row != 15 && col != 24) {
//		if (_board[x + 1][y + 1].GetReveal() == false && _board[x][y].GetMine() == false) {
//			uncover(x + 1, y + 1);
//		}
//	}
//}

