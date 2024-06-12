#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "myExeptions.h"
#include "myClassHeaders.h"

namespace myNSforList {
	enum CommandForList {
		DEFAULT = -1,
		HELP,
		ADD,
		DELETE,
		DISPLAY,
		INCREASE,
		DECREASE,
		EXIT,
		COPY,
		PLUS,
	};
}
namespace myNSforInt {
	enum CommandForInt {
		DEFAULT = -1,
		HELP,
		PLUS,
		MINUS,
		EQUAL,
		EQUASION,
		NOT_EQ,
		BIGGER,
		SMALLER,
		EXIT,
	};
}
using namespace myNSforList;
using namespace myNSforInt;

int main(void) {
	CommandForList comList;
	CommandForInt comInt;
	int tempValue = 0;
	myCircleList queue;
	myInt integer({ 0 });
	myInt tempInt({ 0 });

	myCircleList queue1;
	queue1++;queue1++;++queue1;/*allocating mem for 5 elements in test list*/
	for (int i = 0; i < queue1.getSizeBuffer()-1; i++) /*adding 5,6,7,8 (last is empty)*/
	{
		queue1.addElement(i+5);
	}

	printf("%d - help.\n", CommandForList::HELP);

	do
	{
		comList = CommandForList::DEFAULT;
		printf("\nAwaiting comand number...\n");
		try
		{
			if (scanf("%d", &comList) == 0)
			{
				throw NonNumericInputException("Exception. Non Numeric input found in command input option.");
			};

			switch (comList)
			{

			case CommandForList::ADD: // Adding new element(s) in queue
				printf("Input value of new element in queue\n");
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in add option.");
				}
				queue.addElement(tempValue);
				break;

			case CommandForList::DELETE: // deleting one element from queue
				printf("deleting first element\n");
				printf("deleted element: %d \n", queue.delElement() );
				break;

			case CommandForList::DISPLAY: // Displaying all queue
				printf("Displaying queue\n");
				queue.display();
				break;

			case CommandForList::INCREASE: // // INCREASING queue per N
				printf("Increasing size of queue\n");
				printf("Input number of empty elements to added to list\n");
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in increase option.");
				}
				for (int i = 0; i < tempValue; i++)
				{
					++queue;
				}
				break;

			case CommandForList::DECREASE: // DECREASING queue per N
				printf("Decreasing size of queue\n");
				printf("Input number of elements to removed from list\n");
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in decrease option.");
				}
				if (tempValue > queue.getSizeBuffer())
				{
					printf("Inputed number is bigger then size of queue\nProceeds to delete all element\n");
					tempValue = queue.getSizeBuffer();
				}
				for (int i = 0; i < tempValue; i++)
				{
					--queue;
				}
				break;

			case CommandForList::EXIT: // Exiting program
				printf("Exiting program...\n");
				break;
			case CommandForList::COPY: // Coping second one in first list
				printf("Coping second one in first list\n");
				printf("First list\n");
				queue.display();
				printf("Second list\n");
				queue1.display();
				queue = queue1;
				break;
			case CommandForList::PLUS: // Adding this two lists to each other
				printf("Adding this two lists to each other\n");
				printf("First list\n");
				queue.display();
				printf("Second list\n");
				queue1.display();
				queue + queue1;
				break;

			case CommandForList::HELP: //	Prints all commands
				printf("List of available commands\n");
				printf("%d - add elem.\n%d - del elem.\n%d - display queue.\n%d - increasing size of queue.\n%d - decreasing size of queue.\n%d - exit program.\n%d - help.\n%d - Coping second one in first list.\n%d - Adding this two lists to each other\n", \
					CommandForList::ADD, CommandForList::DELETE, CommandForList::DISPLAY, CommandForList::INCREASE, CommandForList::DECREASE, CommandForList::EXIT, CommandForList::HELP, CommandForList::COPY, CommandForList::PLUS);
				break;

			default: // Default case
				printf("Invalid comList\n");
				break;
			}
		}
		catch (const NonNumericInputException& MetNonNumericExeption)
		{
			char c;
			do
			{
				c = getc(stdin);
			} while ((c != EOF) and (c != '\n') and (c != ' '));
			printf("%s\n", MetNonNumericExeption.what());
		}
		catch (...) {
			printf("Undefined exeption cought\n");
			break;
		}

	} while (comList != CommandForList::EXIT); // Exiting program 

	printf("\nThis area is about myInt\n");
	printf("%d - help.\n", CommandForList::HELP);

	do
	{
		comInt = CommandForInt::DEFAULT;
		printf("Input comList...\n");
		try
		{
			if (scanf("%d", &comInt) == 0)
			{
				throw NonNumericInputException("Exception. Non Numeric input found in command input option.");
			};

			switch (comInt)
			{

			case CommandForInt::PLUS: // x plus value
				printf("%d + ", integer.getX());
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in + option.");
				}
				tempInt.setX(tempValue);
				printf("= %d\n", integer = (integer + tempInt));

				break;

			case CommandForInt::MINUS: // x minus value 
				printf("%d - ", integer.getX());
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in - option.");
				}
				tempInt.setX(tempValue);
				printf("= %d\n", integer = (integer - tempInt));
				break;

			case CommandForInt::EQUAL: // making equal
				printf("%d = ", integer.getX());
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in = option.");
				}
				tempInt.setX(tempValue);
				printf("= %d\n", integer = tempInt);
				break;

			case CommandForInt::EQUASION: // Compares if equal
				printf("%d == ", integer.getX());
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in == option.");
				}
				tempInt.setX(tempValue);
				printf("= %d\n", integer == tempInt);
				break;

			case CommandForInt::NOT_EQ: // Compares if not equal
				printf("%d != ", integer.getX());
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in != option.");
				}
				tempInt.setX(tempValue);
				printf("= %d\n", integer != tempInt);
				break;

			case CommandForInt::BIGGER: // Compares if bigger
				printf("%d > ", integer.getX());
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in > option.");
				}
				tempInt.setX(tempValue);
				printf("= %d\n", integer > tempInt);
				break;

			case CommandForInt::SMALLER: // Compares if smaller
				printf("%d < ", integer.getX());
				if (scanf("%d", &tempValue) == 0) {
					throw NonNumericInputException("Exception. Non Numeric input found in < option.");
				}
				tempInt.setX(tempValue);
				printf("= %d\n", integer < tempInt);
				break;

			case CommandForInt::EXIT: // Exiting program
				printf("Exiting program\n");
				break;

			case CommandForInt::HELP: // Help
				printf("List of available commands\n");
				printf("%d - plus\n%d - minus\n%d - making equal to\n%d - is equal to?\n%d - is not equal to?\n%d - is bigger?\n%d - is smaller?\n%d - help\n%d - exit\n", \
					CommandForInt::PLUS, CommandForInt::MINUS, CommandForInt::EQUAL, CommandForInt::EQUASION, CommandForInt::NOT_EQ, \
					CommandForInt::BIGGER, CommandForInt::SMALLER, CommandForInt::HELP, CommandForInt::EXIT);
				break;

			default: // Default case
				printf("Invalid comList\n");
				break;
			}
		}
		catch (const NonNumericInputException& MetNonNumericExeption)
		{
			char c;
			do
			{
				c = getc(stdin);
			} while ((c != EOF) and (c != '\n'));
			printf("%s\n", MetNonNumericExeption.what());
		}
		catch (...) {
			printf("Undefined exeption cought\n");
			break;
		}

	} while (comInt != CommandForInt::EXIT); // Exiting program 

	return 1;
}