#ifndef BTD_H
#define BTD_H

class btd //creating a class//

{
public:
	btd(); //constructor//
	~btd(); //destructor//

	void setNum(int num_); //prototype for setting binary numbers//
	void setDecEq(int DecEq_); //prototype for setting Decimal equivalent//
	
	void outputNumbers(); //Function that will output the numbers//
	void numberConverter(); //Function that will convert the binary numbers to decimal equivalents//

private:
	int num; //Creating class scope for binary numbers//
	int DecEq; //Creating class scope for Decimal Equivalents//
};

#endif !BTD_H