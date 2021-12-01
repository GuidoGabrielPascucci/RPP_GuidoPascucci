#ifndef INPUTS_H_
#define INPUTS_H_

/// Inputs
int getInteger(int* enteredNumber, char* message);
int getIntInMinMaxRange(int* enteredNumber, char* message, char* errorMessage, int min, int max);
int getIntHigherThan(int* enteredNumber, char* message, char* errorMessage, int min);
float getFloatInMinMaxRange(float* floatIngresado, char* message, char* errorMessage, int min, int max);
int getString(char* string, char* message, char* errorMessage, int max);

/// Validations
int validateInteger(int number);
int validateString(char* string, int length);
void customizeStringForNames(char* string, int length);

#endif







