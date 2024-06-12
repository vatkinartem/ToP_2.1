#include "myInt.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


myInt::~myInt() {

}

int& myInt::getX() {
	return this->x;
}

void myInt::setX(const int value = 0) {
	this->x = value;
}

void myInt::setX(const myInt& value) {
	this->x = value.x;
}

// friend
bool operator < (myInt& First, myInt& Second) {
	return (First.x < Second.x);
}

// method
bool myInt::operator > (myInt& Second) {

	return(this->x > Second.x);
}

// friend
bool operator == (myInt& First, myInt& Second) {
	
	return(First.x == Second.x);
}

// method
bool myInt::operator != (myInt& Second) {

	return(this->x != Second.x);
}

myInt& myInt::operator + (myInt& Second) {
	this->x += Second.x;
	return *this;
}

myInt& operator - (myInt& First, myInt& Second) {
	First.x = First.x - Second.x;
	return First;
}

myInt& myInt::operator = (myInt& Second) {
	this->x = Second.x;
	return *this;
}