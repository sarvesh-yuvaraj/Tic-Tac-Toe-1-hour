#include <stdlib.h>
#include "Renderer.h"

int main()
{
	Renderer rend;
	while (!rend.win){
		rend.DrawBoard();
		data PlayerData = rend.GetInput();
		rend.UpdateDisplay(PlayerData);

		bool WinX = rend.GetWinner('X');
		bool WinO = rend.GetWinner('O');
		if (WinX) {
			std::cout << "X won the match" << std::endl;
			rend.win = true;
		}
		else if (WinO) {
			std::cout << "O won the match" << std::endl;
			rend.win = true;
		}
		else if (!WinX && !WinO && rend.turn_count == 9)
		{
			std::cout << "DRAW" << std::endl;
			break;
		}
		else system("cls");

		
	}
}