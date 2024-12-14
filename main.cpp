#include <stdio.h>

void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int left, int right);
void mergeSort(int arr[], int left, int right);

int linearSearch(int arr[], int size, int data);
int binarySearch(int arr[], int left, int right, int data);
int interpolationSearch(int arr[], int left, int right, int data);

int main(){
	int arr[] = {734, 19, 862, 298, 407, 753, 183, 604, 530, 247, 68, 911, 345, 416, 725, 378, 592, 869, 101, 672, 
	215, 583, 497, 836, 962, 44, 123, 754, 238, 540, 906, 381, 497, 89, 621, 357, 790, 246, 837, 412, 95, 629, 710, 
	315, 482, 729, 593, 851, 48, 902, 768, 230, 15, 642, 91, 378, 602, 504, 812, 394, 675, 250, 13, 739, 498, 823, 47, 
	910, 371, 586, 237, 609, 452, 830, 291, 480, 672, 194, 705, 826, 341, 509, 647, 24, 732, 975, 498, 319, 621, 467, 852, 
	284, 783, 650, 149, 403, 520, 396, 871, 908};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("Before sorting : ");
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	
//	Sorting
//	bubbleSort(arr, size);
//	selectionSort(arr, size);
//	insertionSort(arr, size);
//	quickSort(arr, 0, size - 1);
	mergeSort(arr, 0, size - 1);
	
	printf("After sorting : ");
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	
	int data;
	printf("Search data : ");
	scanf("%d", &data); getchar();
	
//	Searching
	int index;
//	index = linearSearch(arr, size, data);
//	index = binarySearch(arr, 0, size - 1, data);
	index = interpolationSearch(arr, 0, size - 1, data);
	
	if(index != -1){
		printf("%d ditemukan pada index %d\n", data, index);
	}	
	else{
		printf("%d tidak ditemukan\n", data);
	}
	
	return 0;
}
