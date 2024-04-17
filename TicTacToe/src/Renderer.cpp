#include "Renderer.h"

void Renderer::DrawBoard()
{
	std::cout << "\t \t \t \t" << "WELCOME TO "  << std::endl  << "\t \t \t     " << "TIC TAC TOE GAME" << std::endl;
	std::cout << std::endl;
	std::cout << "\t \t  Enter number for the specific spots" << std::endl;
	std::cout << std::endl;
	std::cout << "    Sample Grid of Numbers" << std::endl;
	std::cout << std::endl;
	std::cout << "\t "<< "1|2|3" << std::endl;
	std::cout << "\t "<< "-----" << std::endl;
	std::cout << "\t "<< "4|5|6" << std::endl;
	std::cout << "\t "<< "-----" << std::endl;
	std::cout << "\t "<< "7|8|9" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	const char* localTurn = PlayData.m_PlayerTurn == Turn::TURNX ? "X" : "O";
	std::cout<< "\t" << localTurn << "'s Turn" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	int count = 0;

	for (int i = 1; i <= 5; i++){
		std::cout << "\t";
		for (int j = 1; j <= 5; j++){
			if (i % 2 == 0 )                   std::cout << "_";
			else if (j % 2 == 0 && i %2 != 0)  std::cout << "|";
			else {
				std::cout << matrix[count];
				count++;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout <<"Enter A Number From (1 To 9)";
}

data Renderer::GetInput()
{
	unsigned int boxNum = 0;
	std::cin >> boxNum;

	if (matrix[boxNum - 1] == ' ' && boxNum > 0 && boxNum < 10) {
		turn_count++;
		return { boxNum, PlayData.m_PlayerTurn };
	}
	else {
		std::cout << "Enter another number !!!" << std::endl;
		return { 0, Turn::NONE };
	}
}
void Renderer::UpdateDisplay(data m_Data)
{
	char outVal = ' ';
	if (m_Data.m_PlayerTurn ==      Turn::TURNX)  outVal = 'X';
	else if (m_Data.m_PlayerTurn == Turn::TURNO)  outVal = 'O';
	else if (m_Data.m_PlayerTurn == Turn::NONE )  exit(0);

	matrix[ m_Data.m_BoxNumber - 1 ] = outVal ;

	if (m_Data.m_PlayerTurn     == Turn::TURNX) PlayData.m_PlayerTurn = Turn::TURNO;
	else if(m_Data.m_PlayerTurn == Turn::TURNO) PlayData.m_PlayerTurn = Turn::TURNX;
}

bool Renderer::GetWinner(char player)
{

	if (
		(matrix[0] == player && matrix[1] == player && matrix[2] == player) ||
		(matrix[3] == player && matrix[4] == player && matrix[5] == player) ||
		(matrix[6] == player && matrix[7] == player && matrix[8] == player) ||

		(matrix[0] == player && matrix[3] == player && matrix[6] == player) ||
		(matrix[1] == player && matrix[4] == player && matrix[7] == player) ||
		(matrix[2] == player && matrix[5] == player && matrix[8] == player) ||

		(matrix[0] == player && matrix[4] == player && matrix[8] == player) ||
		(matrix[2] == player && matrix[4] == player && matrix[6] == player)
		) return true;
	else  return false;
}