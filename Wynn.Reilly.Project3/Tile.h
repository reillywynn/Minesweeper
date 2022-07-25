#pragma once
#include <string>
#include <vector>

using namespace std;
class Tile
{
private:
	
	int _numUnderTile;
	bool _flagged;
	bool _revealed;
	bool _mine;
	bool _number;
	bool _empty;
	bool _clicked;
	
public:
	int _x;
	int _y;
	bool checked = false;
	Tile();
	int mines;
	

	int GetNum();
	bool GetFlag();
	bool GetReveal();
	bool GetMine();
	bool GetNumber();
	bool GetEmpty();
	

	void SetMine();
	void SetNumTile(int mines);
	void SetBoolNum();
	void SetBoolEmpty();
	void SetFlag();
	void SetFlagFalse();
	void SetClick();
	void SetReveal();

};

