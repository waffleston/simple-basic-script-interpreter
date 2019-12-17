// simple-basic-script-interpreter
// (c) 2019 Renee Waverly Sonntag
// Licensed under Apache 2.0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUMBER_OF_VARIABLES 50
#define VARIABLE_NAME_LENGTH 100+1

// Here's the place where the variables will exist when they're defined.
// Dynamic memory allocation would complicate things, so there's a maximum number of variables, and a maximum
// length for variable names.
char variableNames[NUMBER_OF_VARIABLES][VARIABLE_NAME_LENGTH];
int variableValues[NUMBER_OF_VARIABLES];
int numberOfVariables = 0;

// Function Prototypes
int getIndexFromVariableName(char*);
int resolveStringToValue(char*);

// loop pointers (not c pointers, stream pointers)
long int doStart;

/*
 * This program takes one argument, with an optional flag argument.
 * Opens a file, and treats lines within as "basic" code to execute.
 * Will exit with error upon fault in the lines of code.
 * 
 * flag of "v", after the filename, will enter "verbose" mode.
 * This prints all lines of code as they are processed.
 */
int main(int argc, char** argv) {
   char* fileName = argv[1];
   char* flags = argv[2];
   char lineOfCode[256] = "";
 
   // Open the file.
   FILE* sourceFile = fopen(fileName, "r");

   // check for error
   if (sourceFile == NULL) {
      printf("[ERROR] Source File Not Provided.\n");
      return 1;
   }

   // Loop, getting each line in the file and processing it.
   while(fgets(lineOfCode, 256, sourceFile) != NULL) {

      // Print the line of code for debugging purposes!
      if (flags != NULL) {
         if (flags[0] == 'v') {
            printf("\tLine of Code: %s", lineOfCode);
         }
      }

      // Get first part of string, ending at the first space character.
      // This is the "keyword", or the thing that tells us what the line wants to do
      char* keyword = strtok(lineOfCode, " \r\n");
      if (keyword == NULL) continue; // safety against emtpy lines

      // Check the keyword against our known commands

      //-------------------------------
      // #
      //-------------------------------
      if (strcmp(keyword, "#") == 0) {
         // Do nothing, it's a comment
      }
      //-------------------------------
      // LET
      //-------------------------------
      else if (strcmp(keyword, "LET") == 0) {
         // It's a variable!  Let's Figure out how to make a variable on the fly.
         
         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // copy the variable name into the variable name array
         strcpy(variableNames[numberOfVariables], vName);

         // check for a value after it
         char* vValue = strtok(NULL, " \r\n");
         if (vValue != NULL) {
            // Convert the string to an int.
            int iValue = atoi(vValue);

            // Place the int in the variable value array.
            variableValues[numberOfVariables] = iValue;
         } else {
            // if nothing is provided, default to 0
            // that way there's no garbage.
            variableValues[numberOfVariables] = 0;
         }

         // increment the number of variables
         numberOfVariables++;

      }
      //-------------------------------
      // PRINT
      //-------------------------------
      else if (strcmp(keyword, "PRINT") == 0) {
         // It's a print line!  Because this language has integers only,
         // we can use a very simple block of code.

         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Now we can print!
         printf("%i\n", variableValues[i]);

      }
      //-------------------------------
      // SET
      //-------------------------------
      else if (strcmp(keyword, "SET") == 0) {
         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Now we can get the value
         char* vValue = strtok(NULL, " \r\n");
         int iValue = 0;
         if (vValue != NULL) {
            // get the value, whether it's an integer or a variable name
            iValue = resolveStringToValue(vValue);

            // Finally, we can set the value!
            variableValues[i] = iValue;
         } else {
            printf("[WARNING] Missing argument to SET\n");
         }

      }
      //-------------------------------
      // ADD
      //-------------------------------
      else if (strcmp(keyword, "ADD") == 0) {
         // It's time to do addition!

         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Now we can get the value
         char* vValue = strtok(NULL, " \r\n");
         int iValue = 0;
         if (vValue != NULL) {
            // get the value, whether it's an integer or a variable name
            iValue = resolveStringToValue(vValue);

            // Finally, we can add!
            variableValues[i] += iValue;
         } else {
            printf("[WARNING] Missing argument to ADD\n");
         }
      
      }
      //-------------------------------
      // SUB
      // (copy paste of ADD, but the "Finally" line does subtraction)
      //-------------------------------
      else if (strcmp(keyword, "SUB") == 0) {
         // It's time to do subtraction!

         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Now we can get the value
         char* vValue = strtok(NULL, " \r\n");
         int iValue = 0;
         if (vValue != NULL) {
            // get the value, whether it's an integer or a variable name
            iValue = resolveStringToValue(vValue);

            // Finally, we can subtract!
            variableValues[i] -= iValue;
         } else {
            printf("[WARNING] Missing argument to SUB\n");
         }
      
      }
      //-------------------------------
      // MUL
      // (copy paste of ADD, but the "Finally" line does multiplication)
      //-------------------------------
      else if (strcmp(keyword, "MUL") == 0) {
         // It's time to do subtraction!

         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Now we can get the value
         char* vValue = strtok(NULL, " \r\n");
         int iValue = 0;
         if (vValue != NULL) {
            // get the value, whether it's an integer or a variable name
            iValue = resolveStringToValue(vValue);

            // Finally, we can multiply!
            variableValues[i] *= iValue;
         } else {
            printf("[WARNING] Missing argument to MUL\n");
         }
      
      }
      //-------------------------------
      // DIV
      // (copy paste of ADD, but the "Finally" line does division)
      //-------------------------------
      else if (strcmp(keyword, "DIV") == 0) {
         // It's time to do subtraction!

         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Now we can get the value
         char* vValue = strtok(NULL, " \r\n");
         int iValue = 0;
         if (vValue != NULL) {
            // get the value, whether it's an integer or a variable name
            iValue = resolveStringToValue(vValue);

            // Finally, we can divide!
            variableValues[i] /= iValue;
         } else {
            printf("[WARNING] Missing argument to DIV\n");
         }
      
      }
      //-------------------------------
      // MOD
      // (copy paste of ADD, but the "Finally" line does modulus)
      //-------------------------------
      else if (strcmp(keyword, "MOD") == 0) {
         // It's time to do subtraction!

         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Now we can get the value
         char* vValue = strtok(NULL, " \r\n");
         int iValue = 0;
         if (vValue != NULL) {
            // get the value, whether it's an integer or a variable name
            iValue = resolveStringToValue(vValue);

            // Finally, we can do modulus!
            variableValues[i] %= iValue;
         } else {
            printf("[WARNING] Missing argument to MOD\n");
         }
      
      }
      //-------------------------------
      // INPUT
      //-------------------------------
      else if (strcmp(keyword, "INPUT") == 0) {
         // It's time to use the standard input

         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Display prompt
         printf("? ");

         // Read from stdin
         char numbery[100];
         fgets(numbery, 100, stdin);

         // convert to an integer
         int iValue = atoi(numbery);

         // place value at variable
         variableValues[i] = iValue;

      }
      //-------------------------------
      // DO
      //-------------------------------
      else if (strcmp(keyword, "DO") == 0) {
         // get the address of the current line, save it in memory
         doStart = ftell(sourceFile);
         // we now know the start of the do-while loop
      }
      //-------------------------------
      // WHILE_NEQ
      //-------------------------------
      else if (strcmp(keyword, "WHILE_NEQ") == 0) {
         // get the variable name
         char* vName = strtok(NULL, " \r\n");

         // get variable index
         int i = getIndexFromVariableName(vName);

         // Now we can get the value
         char* vValue = strtok(NULL, " \r\n");
         int iValue = 0;
         if (vValue != NULL) {
            // get the value, whether it's an integer or a variable name
            iValue = resolveStringToValue(vValue);

            // Finally, we can do the comparison!
            if (variableValues[i] == iValue) {
               continue;
            }
         } else {
            printf("[ERROR] Missing argument to WHILE_NEQ\n");
            return 1;
         }

         // go to the start of the loop, by adjusting the stream pointer.
         fseek(sourceFile, doStart, SEEK_SET);

      }
      //-------------------------------
      // (fallthrough)
      //-------------------------------
      else {
         printf("[WARNING] The keyword is not valid: %s\n", keyword);
      }
   }
}

/*
 * Returns the index of the string containing a variable name.
 * Program will terminate with an error if the variable name does not exist.
 * This was mainly done to simplify error checking, as this is purely an
 * example of a simple interpreter.
 */
int getIndexFromVariableName(char* vName) {
   // figure out which index corresponds to the variable name, if at all.
   int i;
   for (i = 0; i < numberOfVariables; i++) {
      if (strcmp(vName, variableNames[i]) == 0) {
         // This is the one, break out.
         break;
      }
   }

   // check if i isn't valid
   if (i == numberOfVariables) {
      printf("[ERROR] Variable to index does not exist: %s\n", vName);
      exit(1);
   }

   return i;
}

/*
 * Returns the numeric value associated with the input string.
 * If the string starts with a digit, it is presumed an integer literal.
 * All other strings are interpreted as variable names.
 * This can terminate the program, as it calls getIndexFromVariableName.
 */
int resolveStringToValue(char* sValue) {
   // Is it a variable name or an integer?
  
   // pattern matching, if the first character is a number, it's an integer.
   if (sValue[0] >= '0' && sValue[0] <= '9') {
      // The string is an integer

      // Convert the string to an int.
      return atoi(sValue);
   } else {
      // The string is a variable name.
      
      // get index of second variable
      int j = getIndexFromVariableName(sValue);

      return variableValues[j];

   }
   
}
