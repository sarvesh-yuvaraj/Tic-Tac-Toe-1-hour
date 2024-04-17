#pragma once
#include <iostream>
#include  <string>

enum Turn{
	TURNX = 0,
	TURNO = 1,
	NONE = -1
};

struct data {
	unsigned int m_BoxNumber;
	Turn m_PlayerTurn;
};

class Renderer{
public:
	Renderer() {
		PlayData.m_BoxNumber = 0;
		PlayData.m_PlayerTurn = Turn::TURNX;

		for (int i = 0; i <= 9; i++)
			matrix[i] = ' ';
	}
	void DrawBoard();
	data GetInput();
	void UpdateDisplay(data m_Data);
	bool GetWinner(char Player);

public:
	int turn_count = 0;
	char matrix[10];
	bool win = false;
	data PlayData;

};