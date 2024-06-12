#pragma once

class myCircleList
{
	friend const myCircleList& operator -- (myCircleList& source);
	friend const myCircleList& operator ++ (myCircleList& source, int);
public:

	typedef struct myDCircleList {
		int field;
		myDCircleList* ptr;
	} DCList;

	explicit myCircleList() : sizeUsed(0), sizeBuffer(0), head(nullptr), tail(nullptr), genesis(nullptr){}
	myCircleList(const int quantity);
	myCircleList(const myCircleList& source);
	~myCircleList();
	void addElement(int value);
	const int delElement();
	void display();
	bool isFull();
	int getSizeUsed();
	int getSizeBuffer();
	void setSizeUsed(int value);
	void setSizeBuffer(int value);
	DCList* getHead();
	DCList* getTail();
	DCList* getGenesis();
	void setHead(DCList* list);
	void setTail(DCList* list);
	void setGenesis(DCList* list);

	const myCircleList& operator + (const myCircleList& Second);
	const myCircleList& operator = (const myCircleList& Second);
	bool operator ! ();			// checking on emptiness
	const myCircleList& operator ++ ();		// prefix method - adding 1 element
	const myCircleList& operator -- (int);		// postfix method - removing 2 elments

protected:

private:
	int sizeUsed;		/*lenght of used chain*/
	int sizeBuffer;		/*full lenght of allocated chain*/
	DCList* head;		/*first element of active area*/
	DCList* tail;		/*last element of active area*/
	DCList* genesis;	/*first element in chain*/

};
