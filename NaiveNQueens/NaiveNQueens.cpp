// NaiveNQueens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include<iomanip>


using std::cout; 
using std::string; 
using std::vector; 
using std::left; 
using std::setw; 

const int N = 4;

void printChessBoard(const vector<vector<string>> &chessboard)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << left << setw(3) << chessboard[i][j];
		}

		cout << "\n";
	}
}

void reinitializeBoard(vector<vector<string>>& chessboard)
{
	chessboard =
	{
		{"_", "_", "_", "_"},
		{"_", "_", "_", "_"},
		{"_", "_", "_", "_"},
		{"_", "_", "_", "_"}
	};
}
int main()
{

	vector<vector<string>> chessboard =
	{
		{"_", "_", "_", "_"},
		{"_", "_", "_", "_"},
		{"_", "_", "_", "_"},
		{"_", "_", "_", "_"}
	};

	printChessBoard(chessboard); 

	/*make all possible boards with no two queens in same loc*/
	for (int Q1 = 0; Q1 < N; Q1++)
	{
		for (int Q2 = 1; Q2 < N; Q2++)
		{
			for (int Q3 = 2; Q3 < N; Q3++)
			{
				for (int Q4 = 3; Q4 < N; Q4++) 
				//N(N-1)(N-2)...1 = N! loop iters
				{
					for (int ROW = 0; ROW < N; ROW++)
					{
						chessboard[ROW][Q1] = "Q1";
						chessboard[ROW][Q2] = "Q2";
						chessboard[ROW][Q3] = "Q3";
						chessboard[ROW][Q4] = "Q4";

						printChessBoard(chessboard); 
						
						cout << "Next possible board ...\n\n\n";
						system("pause"); 
						reinitializeBoard(chessboard); 

					}
				}
			}
		}
	}
}
