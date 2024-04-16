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
		bool WinY = rend.GetWinner('Y');
		if (WinX) {
			std::cout << "X won the match" << std::endl;
			rend.win = true;
		}
		else if (WinY) {
			std::cout << "Y won the match" << std::endl;
			rend.win = true;
		}
		else system("cls");
	}
}