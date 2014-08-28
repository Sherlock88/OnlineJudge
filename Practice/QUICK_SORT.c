#include <stdio.h>
#include <stdlib.h>

#define DEBUG
#define BUFFERSIZE 20

void quickSort(int n[], int low, int high)
{
	#ifdef DEBUG
	int i;
	#endif
	int pivot = n[low], temp, lowIndex = low, highIndex = high + 1;
	
	if(low >= high)
		return;
		
	while(1)
	{
		while(n[++lowIndex] <= pivot);
		while(n[--highIndex] > pivot);
		if(lowIndex < highIndex)
		{
			temp = n[highIndex];
			n[highIndex] = n[lowIndex];
			n[lowIndex] = temp;
		}
		else
			break;
	}
	
	#ifdef DEBUG
	printf("Low: %d, High: %d, LowIndex: %d, HighIndex: %d, Pivot: %d: ", low, high, lowIndex, highIndex, pivot);
	#endif
	
	n[low] = n[highIndex];
	n[highIndex] = pivot;
	
	#ifdef DEBUG
	for(i = low; i <= high; i++)
		printf("%d ", n[i]);
	printf("\n");
	#endif
	
	quickSort(n, low, highIndex - 1);
	quickSort(n, highIndex + 1, high);
}

int main(int argc, char* argv[])
{
	int i, n[BUFFERSIZE];
	
	argc--;
	for(i = 0; i < argc; i++)
		n[i] = atoi(argv[i + 1]);
		
	quickSort(n, 0, argc - 1);
	
	for(i = 0; i < argc; i++)
		printf("%d ", n[i]);
	printf("\n");
	
	return 0;
}
	