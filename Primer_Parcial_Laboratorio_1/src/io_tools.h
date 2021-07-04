/*
 * input.h
 *
 *  Created on: 22 mar. 2021
 *      Author: Mariano Forte
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifndef IO_TOOLS_H_
#define IO_TOOLS_H_


int getNumber(char* message);

float getFloat(char* message);

/**
 * \brief Asks for an integer number and calls isInt function to validate it,
            shows error message if it isn't an integer number
 * \param message It is the entry request message
 * \return The integer value
 *
 */
int getInt(char* message);

/**
 * \brief Takes the integer given by getInt function and verifies if it is a valid input
 * \param string It is the array with the number to be analized
 * \return 1 if it is a valid integer; 0 if it is not an integer
 *
 */
int isInt(char* string);

/**
 * \brief Allows the entry of a text string
 * \param message It is the entry request message
 * \param errorMessage It is the error message in case of an invalid entry
 * \param input It is the array where text to be loaded up
 * \return 1 if the text only contains letters and spaces
 *
 */
int getCharString(char* message, char* errorMessage, char* input);

/**
 * \brief Verifies if the received value contains only letters and spaces
 * \param string It is the array with the string to be analized
 * \return 1 if the text only contains letters and spaces; 0 if there is more than letters and spaces
 *
 */
int charactersOnly(char* string);

/**
 * \brief Asks for an integer and float number and verifies it
 * \param floatMask It is the mask to put into the scanf function
 * \param variable It is the variable where to place the validated number
 * \return 1 if it is a valid number; 0 if it isn't
 *
 */
int getAndValidateIntAndFloatNumber(const char* floatMask, void* variable);

void getStr(char* message, int size, char* output);

int getLetterStr(char* message,int size, char* output);

int onlyLetters(char* str);

/**
 * \brief Converts the first character of one or more words to uppercase
 * \param string It is the array in which to search
 * \return A confirmation value of the modify
 *
 */
void fstLettUppercase(char* array);

/**
 * \brief Looks for a newline character inside the array and replaces it with a '\0'
 * \param string It is the array in which to search
 * \return The modified string
 *
 */
char removeLineBreak(char* array);

char *strlwr(char *str);

int chooseIndex(void);

void loadList(int* numbersList, int size);

void positiveNumAscSorting(int* array, int size);

void negativeNumDescSorting(int* array, int size);

void printList(int* array,int size);

void printPositiveList(int* array,int size);

void printNegativeList(int* array,int size);

void printPositivesCount(int* array,int size);

void printNegativesCount(int* array,int size);

void printPairNumSum(int* array, int size);

void printBiggestOddNum(int* array, int size);

void printPairNumList(int* array, int size);

void printOddNumList(int* array, int size);

void printPositivesAverage(int* array, int size);

void printNegNumPredecessorsAddition(int* array, int size);



#endif /* IO_TOOLS_H_ */
