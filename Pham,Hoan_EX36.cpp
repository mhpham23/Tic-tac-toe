// Pham,Hoan_EX36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Tile {
	char symbol;
public:
	Tile() {}
	char get_symbol() { return symbol; } // access function
	void set_symbol(char a) { symbol = a; }
};

void map_tile(char x, int& a, int& b) {
	switch (x) {
	case 'A':
		a = 0;
		b = 0;
		break;
	case 'B':
		a = 0;
		b = 1;
		break;
	case 'C':
		a = 0;
		b = 2;
		break;
	case 'D':
		a = 1;
		b = 0;
		break;
	case 'E':
		a = 1;
		b = 1;
		break;
	case 'F':
		a = 1;
		b = 2;
		break;
	case 'G':
		a = 2;
		b = 0;
		break;
	case 'H':
		a = 2;
		b = 1;
		break;
	case 'I':
		a = 2;
		b = 2;
		break;
	}
}

bool checkVictory(Tile** cells, bool done) {
	int countX = 0;
	int countO = 0;

	//check row
	for (int i = 0; i < 3; i++)
	{
		//make sure each row count is reset
		countX = 0;
		countO = 0;

		//columns
		for (int j = 0; j < 3; j++)
		{
			//increment which ever marker is found
			//or if empty space, forget checking the rest
			
			if (cells[i][j].get_symbol() == 'O')
				countO++;
			else if (cells[i][j].get_symbol() == 'X')
				countX++;
			else 
				break;
		}

		//did we find a winner?
		if (countX == 3) {
			cout << "X has won! " ;
			done = true;
				return true;
		}
		else if (countO == 3) {
			cout << "O has won! ";
			done = true;
			return true;
		}
	}
	//if not, check columns for victory
	for (int j = 0; j < 3; j++)
	{
		//make sure each column count is reset
		countX = 0;
		countO = 0;

		//loop through rows
		for (int i = 0; i < 3; i++)
		{
			//increment which ever marker is found
			//or if empty space, forget checking the rest
			
			if (cells[i][j].get_symbol() == 'O')
				countO++;
			else if (cells[i][j].get_symbol() == 'X')
				countX++;
			else
				break;

		}

		if (countX == 3) {
			cout << "X has won! ";
			done = true;
			return true;
		}
		else if (countO == 3) {
			cout << "O has won! ";
			done = true;
			return true;
		}
		//did we find a winner?
		
	}
	//if not, check left to right diagonal
	   //make sure count is reset outside of the loop
	countX = 0;
	countO = 0;
	for (int i = 0; i < 3; i++)
	{
		//increment which ever marker is found
		//or if empty space, forget checking the rest
		
		if (cells[i][i].get_symbol() == 'O')
			countO++;
		else if (cells[i][i].get_symbol() == 'X')
			countX++;
		else
			break;
	}

	//did we find a winner?
	if (countX == 3) {
		cout << "X has won! ";
		done = true;
		return true;
	}
	else if (countO == 3) {
		cout << "O has won! ";
		done = true;
		return true;
	}

	//if not, check last diagonal right to left
	//make sure count is reset outside of the loop
	countX = 0;
	countO = 0;
	for (int i = 0, j = (3 - 1); i < 3; i++, j--)
	{
		//increment which ever marker is found
		//or if empty space, forget checking the rest
		if (cells[i][i].get_symbol() == 'O')
			countO++;
		else if (cells[i][i].get_symbol() == 'X')
			countX++;
		else
			break;
	}

	//did we find a winner?
	if (countX == 3) {
		cout << "X has won! ";
		done = true;
		return true;
	}
	else if (countO == 3) {
		cout << "O has won! ";
		done = true;
		return true;
	}
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (cells[i][j].get_symbol() == 'X' || cells[i][j].get_symbol() == 'O') {
				count++;

			}
		}
	}
	if (count == 9) {
		cout << "DRAW! ";
		done = true;
		return true;
	}
	//if we found no winning conditions
	done = false;
	return false;

}

int main()
{
	Tile** cells; // allocating an array of arrays
	Tile* cell_ptr;
	char s = 'A';
	int i, j, a, b;
	
	char inp;
	bool game = false;
	char answer;
	while (!game) {
		int turn = 1;
		bool done = false;
		cells = new Tile * [3];
		for (i = 0; i < 3; i++) {
			cells[i] = new Tile[3];
			cell_ptr = cells[i]; // point to cells[i][0]
			for (j = 0; j < 3; j++) {
				cell_ptr->set_symbol(s);
				s++; // advance s to the next character in the ascii code
				cell_ptr++; // point to cells[i][j]
			}
		}
		
		while (!done) {
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					cout << " " << cells[i][j].get_symbol();
					if (j < 2)
						cout << " |";
					else
						cout << endl;
				} // for j

				if (i < 2)
					cout << "---+---+---\n";
			} // for i
			if (turn == 1) {
				cout << "Please enter a tile [O]: ";
				cin >> inp;
				if (inp < 'A' || inp > 'I')
					done = true;
				else {
					map_tile(inp, a, b);
					cells[a][b].set_symbol('O');
				}
				turn *= -1;
			}
			else {
				cout << "Please enter a tile [X]: ";
				cin >> inp;
				if (inp < 'A' || inp > 'I')
					done = true;
				else {
					map_tile(inp, a, b);
					cells[a][b].set_symbol('X');
				}
				turn *= -1;
			}
			//checkVictory(cells, done);
			if (checkVictory(cells, done) == true) {
				done = true;
				break;
			}
			else
				done = false;
			
		} // while 
		cout << "Do you want to start a new game? [Y/N]  ";
		cin >> answer;
		if ((answer == 'Y') | (answer == 'y')) {
			game = false;
			done = false;
		}
		else if ((answer == 'N') | (answer == 'n')) {
			game = true;
			done = true;
			break;
		}
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
