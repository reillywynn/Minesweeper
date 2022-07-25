#include "Tile.h"

Tile::Tile() {
	_x = 0;
	_y = 0;
	_numUnderTile = 0;
	_flagged = false;
	_revealed = false;
	_mine = false;
	_number = false;
	_empty = false;
	_clicked = false;
	mines = 0;
}


int Tile::GetNum() {
	return _numUnderTile;
}

bool Tile::GetFlag() {
	return _flagged;
}

bool Tile::GetReveal() {
	return _revealed;
}

bool Tile::GetMine() {
	return _mine;
}

bool Tile::GetNumber() {
	return _number;
}

bool Tile::GetEmpty() {
	return _empty;
}

void Tile::SetMine() {
	_mine = true;
}

void Tile::SetNumTile(int mines) {
	_numUnderTile = mines;
}

void Tile::SetBoolNum() {
	_number == true;
}

void Tile::SetBoolEmpty() {
	_empty = true;
}

void Tile::SetFlag() {
	_flagged = true;
}

void Tile::SetClick() {
	_clicked = true;
}

void Tile::SetReveal() {
	_revealed = true;
}

void Tile::SetFlagFalse() {
	_flagged = false;
}