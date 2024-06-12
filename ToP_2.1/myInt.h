
#pragma once
class myInt
{
	friend myInt& operator - (myInt& First, myInt& Second);
	friend bool operator == (myInt& First, myInt& Second); // friend
	friend bool operator < (myInt& First, myInt& Second); // friend
public:
	explicit myInt() : x(0) {}
	explicit myInt(int value) : x(value){}
	~myInt();
	int& getX();
	void setX(const int value);
	void setX(const myInt& value);

	bool operator > (myInt& Second); // method
	bool operator != (myInt& Second); // method

	myInt& operator + (myInt& Second);
	myInt& operator = (myInt& Second);

private:
	int x;
};
