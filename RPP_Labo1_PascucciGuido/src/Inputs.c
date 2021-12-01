#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"

// --------------------------------------------------------------------------------------------------------------------------------------------------
/// INPUTS
// --------------------------------------------------------------------------------------------------------------------------------------------------


int getInteger(int* enteredNumber, char* message) {
	int functionReturn = 0;

	if(enteredNumber != NULL && message != NULL) {
		printf("%s", message);
		fflush(stdin);
		scanf("%d", enteredNumber);
		functionReturn = 1;
	}

	return functionReturn;
}


/**
 * @fn int getIntInMinMaxRange(int*, char*, char*, int, int)
 * @brief Permite al usuario ingresar un numero entero en un rango de un numero minimo y un numero maximo
 *
 * @param enteredNumber		---> puntero que retornara el numero entero ingresado
 * @param message			---> mensaje impreso en pantalla
 * @param errorMessage		---> mensaje de error impreso en pantalla
 * @param min				---> numero menor posible
 * @param max				---> numero mayor posible
 * @return [0] si algun dato es NULL o erroneo / [1] si OK
 */
int getIntInMinMaxRange(int* enteredNumber, char* message, char* errorMessage, int min, int max) {
	int functionReturn = 0;
	int enterIntNumber;

	if(enteredNumber != NULL && message != NULL && errorMessage != NULL && min < max) {
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enterIntNumber);

		while(enterIntNumber < min || enterIntNumber > max) {
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%d", &enterIntNumber);
		}

		*enteredNumber = enterIntNumber;
		functionReturn = 1;
	}

	return functionReturn;
}


/**
 * @fn int getNumeroMayorQueMinimo(int*, char*, char*, int)
 * @brief Permite al usuario ingresar un numero entero que sea mayor a un numero minimo establecido
 *
 * @param enteredNumber		---> puntero que retornara el numero entero ingresado
 * @param message			---> mensaje impreso en pantalla
 * @param errorMessage		---> mensaje de error impreso en pantalla
 * @param min				---> numero menor posible
 * @return Retorna [0] si algun dato es NULL / [1] si OK
 */
int getIntHigherThan(int* enteredNumber, char* message, char* errorMessage, int min) {
	int functionReturn = 0;
	int enterIntNumber;

	if(enteredNumber != NULL && message != NULL && errorMessage != NULL) {
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enterIntNumber);

		while(enterIntNumber < min) {
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%d", &enterIntNumber);
		}

		*enteredNumber = enterIntNumber;
		functionReturn = 1;
	}

	return functionReturn;
}


/**
 * @fn float getFloatInMinMaxRange(float*, char*, char*, int, int)
 * @brief Permite ingresar un numero flotante entre un rango minimo y un rango maximo establecido.
 *
 * @param floatIngresado 	---> puntero que retornara el numero flotante ingresado
 * @param message 			---> mensaje impreso en pantalla
 * @param errorMessage		---> mensaje de error impreso en pantalla
 * @param min				---> numero menor posible
 * @param max				---> numero mayor posible
 * @return Retorna [0] si algun dato es NULL o erroneo / [1] si OK
 */
float getFloatInMinMaxRange(float* floatIngresado, char* message, char* errorMessage, int min, int max) {
	int ret = 0;
	float enterFloatNumber;

	if(floatIngresado != NULL && message != NULL && errorMessage != NULL && min < max) {
		printf("%s", message);
		fflush(stdin);
		scanf("%f", &enterFloatNumber);

		while (enterFloatNumber < min || enterFloatNumber > max) {
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%f", &enterFloatNumber);
		}

		*floatIngresado = enterFloatNumber;
		ret = 1;
	}

	return ret;
}


/**
 * @fn int getString(char*, char*, char*, int)
 * @brief Permite al usuario ingresar una cadena de caracteres que no supere la cantidad maxima de caracteres establecida
 *
 * @param string
 * @param message
 * @param errorMessage
 * @param max
 * @return Retorna [0] si algun dato es NULL / [1] si OK
 */
int getString(char* string, char* message, char* errorMessage, int max) {
	int functionReturn = 0;
	char notValidateString[200];
	int length;

	if(string != NULL && message != NULL && errorMessage != NULL) {
		printf("%s", message);
		fflush(stdin);
		scanf("%[^\n]", notValidateString);
		length = strlen(notValidateString);

		while(length > max || validateString(notValidateString, length)) {
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%[^\n]", notValidateString);
			length = strlen(notValidateString);
		}

		customizeStringForNames(notValidateString, length);
		strcpy(string, notValidateString);
		functionReturn = 1;
	}


	return functionReturn;
}


// --------------------------------------------------------------------------------------------------------------------------------------------------
/// VALIDATIONS
// --------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @fn int validateInteger(int)
 * @brief Validates that the int number contains only digits from 0 to 9.
 *
 * @param number int
 * @return Return an INTEGER: [-1] if error / [0] if OK
 */
int validateInteger(int number)
{
	int value = -1;

	if (!isdigit(number))
	{
		value = 0;
	}


	return value;
}


/**
 * @fn int validateString(char*, int)
 * @brief Validates that the string is free of numbers or symbols.
 * 		  It only allows alphabetic letters (a - z) or spaces (between two letters).
 *
 * @param string char 		---> Pointer to string
 * @param length int		---> size of string
 * @return Returns an INTEGER: [-1] if error / [0] if OK
 */
int validateString(char* string, int length)
{
	int functionValue = 0;
	int i;


	for (i = 0; i < length; ++i)
	{
		if ( (isdigit(string[i])) || string[i] < 32 || (string[i] > 32 && string[i] < 65) || (string[i] > 90 && string[i] < 97) || string[i] > 122 )
		{
			functionValue = -1;
			break;
		}
	}


	for (i = 0; i < length; ++i)
	{
		if (string[i] == 32 && string[i+1] == 32)
		{
			functionValue = -1;
			break;
		}
	}


	return functionValue;
}


/**
 * @fn void customizeStringForNames(char*, int)
 * @brief Modifies the string.
 *
 * @param string char 		---> Pointer to string
 * @param length int		---> size of string
 */
void customizeStringForNames(char* string, int length)
{
	int i;

	for (i = 0; i < length; ++i)
	{
		string[i] = tolower(string[i]);
	}


	for (i = 0; i < length; ++i)
	{
		if (i == 0)
		{
			string[i] = toupper(string[i]);
		}
		else
		{
			if (string[i] == 32)
			{
				string[i+1] = toupper(string[i+1]);
			}
		}
	}

}
