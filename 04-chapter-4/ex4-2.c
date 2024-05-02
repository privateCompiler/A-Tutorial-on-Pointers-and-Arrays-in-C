#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *string);
char* my_strcat(const char* stringArray[]);
char *my_strchr(const char array[], int character);

int main(void)
{
    // sample string for my_strlen()
    char strA[80] = "An example text to be used as demonstration.";

    // set the function return to variable `length`    
    int length = my_strlen(strA);
    printf("%i\n", length);

    // sample strings for my_strcat()
    const char *string1 = "Hello world! ";
    const char *string2 = "I am Christopher. ";
    const char *string3 = "That is all.";

    // create an array of the strings with a sentinel value in the last index for the function parameter
    const char *stringArray[4] = {string1, string2, string3, NULL}; 

    // set pointer variable to return value of function & print
    char *concatenatedStrings = my_strcat(stringArray);
    printf("%s\n", concatenatedStrings);

    free(concatenatedStrings);

    // sample string for my_strchr()
    char string4[] = "An example text to be used as demonstration";
    char *charLocation = my_strchr(string4, 'e');

    // print the dereferenced pointer value, and the location
    printf("First Instance of %c:  %p\n", *charLocation, (void*)charLocation);

    return 0;
}

int my_strlen(const char *string)
{
    int i = 0;

    while (string[i])
    {
        i++;
    }

    return i;
}

char* my_strcat(const char* stringArray[])
{
    int numberOfElements = 0;
    int characterLength = 0;

    // Calculate the number of elements and total length
    while (stringArray[numberOfElements] != NULL)
    {
        characterLength += my_strlen(stringArray[numberOfElements]);
        numberOfElements++;
    }

    // Allocate memory for the concatenated string
    char *concatenation = (char*)malloc(sizeof(char) * (characterLength + 1));
    if (concatenation == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    // Concatenate strings
    char *index = concatenation;
    for (int i = 0; i < numberOfElements; i++)
    {
        const char *currentString = stringArray[i];
        while (*currentString != '\0')
        {
            *index = *currentString;
            index++;
            currentString++;
        }
    }
    *index = '\0';

    return concatenation;
}

char *my_strchr(const char array[], int character)
{
    for (int i = 0; i <= my_strlen(array); i++)
    {
        if (array[i] == character)
        {
            return (char*)&array[i];
            break;
        }
    }

    return NULL;
}