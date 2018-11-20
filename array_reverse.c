#include <stdio.h>   // for printf(), scanf(), putchar(), stderr
#include <stdlib.h>  // for exit(), malloc(), free() EXIT_FAILURE, EXIT_SUCCESS, size_t


void fillArray(char array[], size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("Enter array[%zu]: ", i);
	scanf("%c", array + i);
	scanf("%*c");  // consumes the '\n' at the end of input
    }
}


void reverseArray(char array[], size_t size)
{
    char temp = '\0';
    size_t mid = size / 2;
    size_t last = size - 1;
    for (size_t i = 0; i < mid; ++i) {
        temp = array[i];
	array[i] = array[last - i];
	array[last - i] = temp;
    }
}


void printArray(char array[], size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        printf("%c ", array[i]);
    }
    putchar('\n');
}


int main(void)
{
    printf("Enter the size of the array: ");
    size_t size = 0;

    scanf("%zu", &size);
    scanf("%*c");  // consumes the '\n' at the end of input

    if (size == 0) {
        fprintf(stderr, "size should be > %d\n", 0);
	exit(EXIT_FAILURE);
    }

    char* array = NULL;
    array = malloc(sizeof(char) * size);

    fillArray(array, size);
    printArray(array, size);
    reverseArray(array, size);
    printArray(array, size);

    free(array);

    return EXIT_SUCCESS;
}
