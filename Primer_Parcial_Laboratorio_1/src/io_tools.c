/*
 * input.c
 *
 *  Created on: 22 mar. 2021
 *      Author: Mariano Forte
 */
#include "io_tools.h"

int getNumber(char* message){
	char auxiliar[256];
	int integer;
	printf("%s",message);
	scanf("%s",auxiliar);
	while(isalpha(*auxiliar)){
		printf("Error. Eso no es un numero. Ingrese un numero: ");
		scanf("%s",auxiliar);
	}
	integer = atoi(auxiliar);
	return integer;
}

float getFloat(char* message)
{
    float auxiliar;
    printf("%s",message);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char* message)
{
    char aux[256];
    int integer;

    printf("%s", message);
    fflush(stdin);
    scanf("%s",aux);

    while(!isInt(aux))
    {
        printf("\nError! Eso no es un numero. Ingrese un numero: ");
        fflush(stdin);
        scanf("%s",aux);
        printf("\n");
    }
    if(isInt(aux) == 1)
    {
        integer = atoi(aux);
    }
    return integer;
 }

int isInt(char* string)
{
    int i;
    int returnValue = 1;

    for(i=0; string[i] != '\0'; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
            returnValue = 0;
            return returnValue;
        }
    }
    return returnValue;
}

int getCharString(char* message, char* errorMessage, char* input)
{
    char aux[51];
    int returnValue = 0;
    printf(message);
    fflush(stdin);
    fgets(aux,sizeof(aux),stdin);
    while(charactersOnly(aux) == 0)
    {
        printf(errorMessage);
        fflush(stdin);
        fgets(aux,sizeof(aux),stdin);
    }
    if(charactersOnly(aux) == 1)
    {
        returnValue = 1;
        strcpy(input,aux);
        return returnValue;
    }
    return returnValue;
}

int charactersOnly(char* string)
{
    int i;
    int ifIsAlpha;
    int sz;

    sz = strlen(string)-1;

    for(i=0; i< sz; i++)
    {
        if((!(isalpha(string[i]) == 0)) || string[i] == ' ')
        {
            ifIsAlpha = 1;
        }
        else
        {
            ifIsAlpha = 0;
            break;
        }
    }
    return ifIsAlpha;
}

int getAndValidateIntAndFloatNumber(const char* floatMask, void* variable)
{
    int input;
    int flagConfirmation = 0;
    int returnValue = 0;

    fflush(stdin);
    if(!scanf(floatMask, variable))
    {
        while(flagConfirmation == 0)
        {
            while((input = getchar()) != '\n' && input != EOF);
            printf("\nIngreso Invalido.\n\nVuelva a intentarlo: ");
            fflush(stdin);
            if(scanf(floatMask, variable))
            {
                fflush(stdin);
                flagConfirmation = 1;
                returnValue = 1;
            }
        }
        fflush(stdin);
        return returnValue;
    }
    if(getchar() != '\n')
    {
        while(flagConfirmation == 0)
        {
            while((input = getchar()) != '\n' && input != EOF);
            printf("\nIngreso Invalido.\n\nVuelva a intentarlo: ");
            if(scanf(floatMask, variable))
            {
                flagConfirmation = 1;
                returnValue = 1;
            }
        }
        return returnValue;
    }
    return returnValue;
}

void getStr(char* message, int size, char* output){
    printf("%s", message);
    fflush(stdin);
    fgets(output, size, stdin);
}

int getLetterStr(char* message,int size, char* output){
    char aux[256];
    getStr(message, size, aux);
    if(onlyLetters(aux))
    {
        strcpy(output,aux);
        return 1;
    }
    return 0;
}

int onlyLetters(char* str){
    int i=0;

    for(i=0; str[i] != '\0'; i++)
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
    }
    return 1;
}

void fstLettUppercase(char* array){
    int i;
    strlwr(array);
    for(i = 0; i < strlen(array); i++)
    {
        if(i == 0 || (array[i-1] == ' ' && array[i] >= 'a' && array[i] <= 'z'))
        {
        	array[i] = toupper(array[i]);
        }
    }
}

char removeLineBreak(char* array){
    int i;
    for(i=0;array[i] != '\0';i++)
    {
        if(array[i] == '\n')
        {
        	array[i] = '\0';
        }
    }
    return array[i];
}

char *strlwr(char *str){
  unsigned char *p = (unsigned char *)str;
  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }
  return str;
}

int chooseIndex(void){
	int index;
	index = getInt("\nIngrese el numero de índice donde guardarlo: ");
	return index;
}

void loadList(int* numbersList, int size){
	int userInput;
	int i;

	for(i=0; i<size; i++)
	 {
		userInput = getNumber("\nIngrese un numero: ");
		/*while(userInput < -1000 || userInput > 1000){
			printf("\nError. Numero fuera de rango.");
			userInput = getInt("\n\nIngrese un numero entre -1000 y 1000: ");
		}*/
		numbersList[i] = userInput;
		}
	 }

void positiveNumAscSorting(int* array, int size){
	int i,j, aux;
	for(i=0;i<size;i++){
		for(j=i+1; j<size; j++){
			if(array[i]>=0){
				if(array[i] > array[j]){
					aux = array[i];
					array[i] = array[i+1];
					array[i+1] = aux;
				}
			}
		}
	}
}

void negativeNumDescSorting(int* array, int size){
    int i,j, aux;
    for(i=0;i<size;i++){
    	for(j=i+1; j<size; j++){
    		if(array[i]>=0){
				if(array[i] < array[j]){
					aux = array[i];
					array[i] = array[j];
					array[j] = aux;
				}
    		}
    	}
    }
}

void printList(int* array,int size){
    int i;
    for(i=0; i<size; i++)
    {
        printf("\nIndice %d: %d",i, array[i]);
    }
}

void printPositiveList(int* array,int size){
    int i;
    for(i=0; i<size; i++)
    {
    	if(array[i] >= 0){
			printf("\nIndice %d: %d",i, array[i]);
		}
    }
}

void printNegativeList(int* array,int size){
    int i;
    for(i=0; i<size; i++)
    {
        if(array[i] < 0){
        	printf("\nIndice %d: %d",i, array[i]);
        }
    }
}


void printPairNumList(int* array, int size){
	int i;
	for(i=0; i<size; i++){
		if(array[i]%2 == 0){
			printf("\nIndice %d: %d", i, array[i]);
		}
	}
}

void printOddNumList(int* array, int size){
	int i;
	for(i=0; i<size; i++){
		if(array[i]%2 != 0){
			printf("\nIndice %d: %d", i, array[i]);
		}
	}
}


