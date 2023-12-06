#include "btd.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>


using namespace std;


btd::btd() //constructor//
{
	num = 0; //setting a value to binary numbers//
	DecEq = 0; //Setting a value to decimal equivalents//
}
btd::~btd() //destructor//
{
}

void btd::setNum(int num_) //set function for binary numbers//
{
	num = num_;
}

void btd::setDecEq(int DecEq_) //set function for decimal equivalents//
{
	DecEq = DecEq_;
}



void btd::outputNumbers() //Function definintion for outputting the binary and decimal equivalent//
{
	ifstream inFile; //opening up the data file//
	inFile.open("Binaryln.dat");

	if (!inFile) //making sure the data file is properly accessible//
	{
		cout << "Data file error" << endl;

		inFile.close();
	}

	while (inFile)
	{
		char b; 

		inFile.get(b); //having it so the data files characters are read individually//

		num = b - 48; //converting from char to int//

		setNum(num); //setting new int value//

		if (num == -16) //Ignoring if there are spaces//
		{
			inFile.ignore(0);
		}
		else
		{
			if (num == 1 || num == 0) //Making sure number is binary//
			{
				numberConverter(); //storing a value for the decimal equivalent//

				cout << num; //outputting the binary number//

			}
			else
			{
				if (num == -38) //What to do when the data file reaches an end of line character//
				{
					cout << setw(25) << DecEq; //outputs the calculated decimal equivalent//
					DecEq = 0; //Resets the decimal equivalent for the next line//
					setDecEq(DecEq);

					cout << endl;
				}
				else
				{
					cout << "invalid data"; //Invalid statement if the data file reads anything other than a 1, 0, space, or new line character//
				}
			}
		}
	}
}


void btd::numberConverter() //Defintion for converting binary to decimal equivalent//
{
	DecEq = (DecEq * 2) + num; //Binary to decimal formula//

	setDecEq(DecEq);
}

