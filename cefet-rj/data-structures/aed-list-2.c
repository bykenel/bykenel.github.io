#include <stdio.h>
#include <stdlib.h>

/*
void createList(int ***list, int size)
{
  int i;
  *list = (int **)malloc(sizeof(int *[size]));
  for (i = 0; i < size; i = i + 1)
    (*list)[i] = NULL;
}
*/

int elementsInList(int **list, int size)
{
  int i;
  for (i = 0; i < size; i = i + 1)
    if (list[i] == NULL)
      break;
  return i;
}

/*
int searchInList(int **list, int size, int value)
{
  int i, searchResult;
  searchResult = -1; // flag for error
  for (i = 0; i < size; i = i + 1)
  {
    if (list[i] == NULL)
      i = size;
    else if (*(list[i]) == value)
    {
      searchResult = i;
      i = size;
    }
  }
  return searchResult;
}

int insertInList(int **list, int size, int value)
{
  int i, count;
  count = elementsInList(list, size);
  if (count < size)
    if (searchInList(list, size, value) == -1)
    {
      list[count] = (int *)malloc(sizeof(int));
      *list[count] = value;
      return 1;
    }
    else
      return 0; // Element already exists
  else
    return -1; // Overflow
}

int removeFromList(int **list, int size, int value)
{
  int i, index, count = elementsInList(list, size);
  if (count == 0)
    return -1; // Underflow
  else
  {
    index = searchInList(list, size, value);
    if (index == -1)
      return 0; // Element does not exist
    else
    {
      if (index == size - 1)
      {
        free(list[index]);
        list[index] = NULL;
      }
      else
      {
        free(list[index]);
        for (i = index; i < count; i = i + 1)
          list[i] = list[i + 1];
        list[count - 1] = NULL;
      }
      return 1;
    }
  }
}

void printList(int **list, int size)
{
  int i, count;
  for (i = 0; i < size; i = i + 1)
    if (list[i] == NULL)
      printf("NULL\n");
    else
      printf("%d\n", *(list[i]));
  printf("\n");
}

void clearList(int ***list, int size)
{
  int i;
  for (i = 0; i < size; i = i + 1)
    if ((*list)[i] != NULL)
      free((*list)[i]);
  free(*list);
}
*/

// [L2] questão 2.1:
int searchInList(int **list, int size, int value)
{
  int i, count, searchResult;
  list[size] = (int *)malloc(sizeof(int)); // Allocating a new position
  count = elementsInList(list, size);
  *(list[count]) = value;
  searchResult = -1; // Flag for error
  for (i = 0; *(list[i]) != value; i = i + 1)
    ;
  if (i != count)
    searchResult = i;
  free(list[size]); // Freeing the newly allocated position
  return searchResult;
}

// [L2] questão 2.2:
int searchInOrderedList(int **list, int size, int value)
{ // size is the highest index in the list
  int i, searchResult;
  searchResult = -1; // flag for error
  for (i = 0; (list[i] != NULL) && (*(list[i]) < value); i = i + 1)
    ;
  if (list[i] != NULL && *list[i] == value)
    searchResult = i;
  return searchResult;
}

// [L2] questão 2.3:
int binarySearch(int **list, int size, int value)
{
  int lower, upper, middle, searchResult;
  lower = 0;
  upper = size - 1;
  searchResult = -1; // flag for error
  while (lower <= upper)
  {
    middle = (lower + upper) / 2;
    if (list[middle] == NULL || (*list[middle]) > value)
      upper = middle - 1;
    else if ((*list[middle]) < value)
      lower = middle + 1;
    else
      searchResult = middle;
  }
  return searchResult;
}

// [L2] questão 2.4:
void sortList(int **list, int size)
{
  int i, j, temp, count;
  count = elementsInList(list, size);
  for (i = count - 1; i > 1; i = i - 1)
    for (j = 0; j < i; j = j + 1)
      if (*list[j] > *list[j + 1])
      {
        temp = *list[j];
        *list[j] = *list[j + 1];
        *list[j + 1] = temp;
      }
}