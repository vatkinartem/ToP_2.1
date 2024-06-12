#include "myCircleList.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#define my_debug_Mode 0

/*Constructor for faster element allocation. Making list of "quantity" elements*/
myCircleList::myCircleList(const int quantity = 0)
{
	this->sizeUsed = 0;
	this->sizeBuffer = 0;
	this->head = NULL;
	this->tail = NULL;
	this->genesis = NULL;
	
	for (int i = 0; i < quantity; i++)
	{
		++(*this);
	}
}
/*Copy constructor*/
myCircleList::myCircleList(const myCircleList& source)
{
	this->operator=(source);
}
/*Destructor*/
myCircleList::~myCircleList() 
{
	/*freeng list*/
	DCList* plist = this->genesis;

	if (this->genesis != NULL) // if there is at least one element
	{
		for (int i = 0; i < this->sizeBuffer; i++)
		{
			plist = this->genesis;
			this->genesis = this->genesis->ptr;
			free(plist);
		}
	}
	else // if there is none
	{
		//nothing to free there
	}
}

/*Adding inputed value in first accessible element after tail. If list is full then moving head forward.*/
void myCircleList::addElement(int value) 
{
	if (this->sizeBuffer == 0)				/*if list is empty*/
	{
		printf("Cannot add element in empty list\n");
		return;
	}
	if (this->operator!())					/*if chain is empty*/
	{
		this->head = this->genesis;
		this->tail = this->genesis;
		this->tail->field = value;
		this->sizeUsed++;
		return;
	}
	if (this->sizeBuffer == this->sizeUsed)	/*if overwhelming*/
	{
		this->head = this->head->ptr;
		this->tail = this->tail->ptr;
		this->tail->field = value;
		return;
	}
	/*default case (if there is free space bw tail and head)*/
	this->tail = this->tail->ptr;
	this->tail->field = value;
	this->sizeUsed++;
	
}
/*Moving head mark forward. If cant making it NULL*/
const int myCircleList::delElement() 
{
	int tempValue = 0;
	if (this->operator!())
	{
		printf("Nothing to delete\n");
		return 0;
	}
	if (this->sizeUsed == 1)
	{
		tempValue = this->head->field;
		this->head = NULL;
		this->tail = NULL;
		this->sizeUsed--;
		return tempValue;
	}
	
	tempValue = this->head->field;
	this->head = this->head->ptr;
	this->sizeUsed--;
	return tempValue;
}

/*Displaying queue (including mark, full list, and chain)*/
void myCircleList::display() {
	DCList* pList = NULL;
	
	if (this->sizeBuffer == 0)
	{
		printf("Nothing to display in list\n");
		return;
	}

	pList = this->genesis;
	printf("sizeUsed: %d, sizeBuffer: %d\n",this->sizeUsed, this->sizeBuffer);

#if my_debug_Mode == 1
	printf("DEBUG mode is ON. It nay cause slow work with big queues.\nFull list with marks - ", this->sizeUsed, this->sizeBuffer);
	for (int i = 0; i < this->sizeBuffer; i++)	/*Prints all list*/
	{
		if (pList == this->genesis) { printf("G"); }	/*Print mark of Genesis*/
		if (pList == this->head) { printf("H"); }		/*Print mark of Head*/
		if (pList == this->tail) { printf("T"); }		/*Print mark of Tail*/
		printf("%d ", pList->field);
		pList = pList->ptr;
	}
	printf("\n");
#endif // my_debug_Mode

	if (this->operator!())
	{
		printf("Nothing to display in chain\n");
		return;
	}
	printf("chain - ");
	pList = this->head;			/*Prints only circular chain (from H to T)*/
	for (int i = 0; i < this->sizeUsed; i++)
	{
		printf("%d ", pList->field);
		pList = pList->ptr;
	}
	printf("\n");
}

/*Returns true if sizeUsed == sizeBuuffer else false*/
bool myCircleList::isFull() {
	if (this->sizeBuffer == this->sizeUsed)
	{
		return true;
	}
	else {
		return false;
	}
}

/*Getting SizeUsed*/
int myCircleList::getSizeUsed() 
{
	return this->sizeUsed;
}
/*Setting SizeBuffer*/
int myCircleList::getSizeBuffer()
{
	return this->sizeBuffer;
}

/*Setting SizeUsed*/
void myCircleList::setSizeUsed(int value)
{
	this->sizeUsed = value;
}
/*Setting SizeBuffer*/
void myCircleList::setSizeBuffer(int value)
{
	this->sizeBuffer = value;
}

/*Getting Head*/
myCircleList::DCList* myCircleList::getHead()
{
	return this->head;
}
/*Setting Tail*/
myCircleList::DCList* myCircleList::getTail()
{
	return this->tail;
}
/*Setting Genesis*/
myCircleList::DCList* myCircleList::getGenesis()
{
	return this->genesis;
}

/*Setting Head*/
void myCircleList::setHead(DCList* list) {
	this->head = list;
}
/*Setting Tail*/
void myCircleList::setTail(DCList* list) {
	this->tail = list;
}
/*Setting Genesis*/
void myCircleList::setGenesis(DCList* list) {
	this->genesis = list;
}

/*Operator of sum*/
const myCircleList& myCircleList::operator + (const myCircleList& Second)
{
	DCList* pSecondList = Second.head; /*firstly adding chain*/
	for (int i = 0; i < Second.sizeUsed; i++)
	{
		if (this->sizeUsed == this->sizeBuffer)
		{
			++(*this);
		}
		this->addElement(pSecondList->field);
		pSecondList = pSecondList->ptr;
	}

	return *this;
}

/* Coping everything (including index of head and tail)*/
const myCircleList& myCircleList::operator = (const myCircleList& source)
{
	/*freeng list*/
	DCList* plist = this->genesis;

	if (this->genesis != NULL) // if there is at least one element
	{
		for (int i = 0; i < this->sizeBuffer; i++)
		{
			plist = this->genesis;
			this->genesis = this->genesis->ptr;
			free(plist);
		}
	}
	else // if there is none
	{
		//nothing to free there
	}

	DCList* pSourceList = NULL;

	this->sizeUsed = 0;
	this->sizeBuffer = 0;
	this->head = NULL;
	this->tail = NULL;
	this->genesis = NULL;
	
	pSourceList = source.head;	/*firstly adding chain*/
	for (int i = 0; i < source.sizeUsed; i++)
	{
		if (this->sizeUsed == this->sizeBuffer)
		{
			++(*this);
		}
		this->addElement(pSourceList->field);
		pSourceList = pSourceList->ptr;
	}

	/*then adding free space*/
	for (int i = 0; i < (source.sizeBuffer - source.sizeUsed); i++)
	{
		++(*this);
	}

	return *this;
}

/* if empty returns TRUE if no FALSE*/
bool myCircleList::operator ! ()
{
	if (this->head == NULL) // if empty then return 1 else 0
	{
		return true;
	}
	else {
		return false;
	}
}

/* adds one element in list */
const myCircleList& myCircleList::operator ++ ()
{
	DCList* temp = NULL;
	temp = (DCList*)calloc(1, sizeof(DCList));
	if (temp == NULL)
	{
		printf("Failed to allocate memory for one element for list in operator++()\n");
		return *this;
	}

	if (this->sizeBuffer == 0) /*if list is empty than initialise one element*/
	{
		this->genesis = temp;
		this->genesis->ptr = this->genesis;
		this->sizeBuffer++;
		return *this;
	}
	
	if (this->sizeUsed > 0) /*if list is atlest 1 elem long*/
	{
		temp->ptr = this->tail->ptr;
		this->tail->ptr = temp;
		this->sizeBuffer++;
		return *this;
	}

	/*default case (if sizeUsed == 0)*/
	temp->ptr = this->genesis->ptr;
	this->genesis->ptr = temp;
	this->sizeBuffer++;
	return *this;
}
/* adds two elements in list*/
const myCircleList& operator ++ (myCircleList& source, int)
{
	++(source);
	++(source);
	return source;
}

/*Deleting oldest one element from list*/
const myCircleList& operator -- (myCircleList& source)
{
	myCircleList::DCList* pList = NULL;	/*remembering adress of tail*/
	myCircleList::DCList* temp = NULL;	/*future element to be deleted*/

	if (source.getSizeBuffer() == 0) /*if list empty*/
	{
		printf("Nothing to delete in list\n");
		return source;
	}

	if (source.getSizeUsed() == 0) /*if chain is empty (head, tail = NULL)*/
	{
		pList = source.getGenesis();
		temp = source.getGenesis()->ptr; /*element to be freed*/
		
		pList->ptr = temp->ptr;	/*making circle list smaller on 1*/
		free(temp);
		source.setSizeBuffer(source.getSizeBuffer()-1);
		if (source.getSizeBuffer() == 0)
		{
			source.setGenesis(NULL);
		}
		return source;
	}

	/*default case (if chain is initialised sizeUsed is atleast 1)*/
	if (source.getSizeUsed() > 0)
	{
		pList = source.getTail();
		temp = source.getTail()->ptr;	/*element to be freed*/

		if (source.getTail() == temp)	/* that means there is only 1 element (also means that temp is G H T)*/ 
		{ 
			source.setTail(NULL);
			source.setHead(NULL);
			source.setGenesis(NULL);
			source.setSizeUsed(source.getSizeUsed() - 1);
		}

		if (source.getHead() == temp)	/*there atleast 2 elements (temp is atleast is H)*/
		{ 
			source.getTail()->ptr = source.getHead()->ptr;
			source.setHead(source.getHead()->ptr);
			source.setSizeUsed(source.getSizeUsed() - 1); /*because head was moved*/
		}

		if (source.getGenesis() == temp)	/*case where temp is G (also works with temp being H)*/
		{
			source.getTail()->ptr = source.getGenesis()->ptr;
			source.setGenesis(source.getGenesis()->ptr);
		}
		
		if ((temp != source.getGenesis()) && (temp != source.getHead()) && (temp != source.getTail()) && (source.getTail() != NULL)) /*Case where with next after tail is without a mark*/
		{
			source.getTail()->ptr = temp->ptr; 
		}

		free(temp);
		source.setSizeBuffer(source.getSizeBuffer() - 1);
		return source;
	}

	printf("Nothing was deleted from list\n");
	return source;
}
/*Deleting oldest two element from list*/
const myCircleList& myCircleList::operator -- (int)
{
	--(*this);
	--(*this);
	return *this;
}
