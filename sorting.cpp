void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int size){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < (size - 1 - i); j++){
			if(arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void selectionSort(int arr[], int size){
	for(int i = 0; i < size; i++){
		int minIndex = i; 
		
		for(int j = i + 1; j < size; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		swap(&arr[i], &arr[minIndex]);
	}
}

void insertionSort(int arr[], int size){
	for(int i = 1; i < size; i++){
		int temp = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

int partition(int arr[], int left, int right){
	int pivot = arr[right];
	int i = left - 1;
	
	for(int j = left; j <= right - 1; j++){
		if(arr[j] < pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	i++;
	swap(&arr[i], &arr[right]);
	return i;
}

void quickSort(int arr[], int left, int right){
	if(right <= left) return;
	int pivot = partition(arr, left, right);
	quickSort(arr, left, pivot - 1);
	quickSort(arr, pivot + 1, right);
}


void merge(int arr[], int left, int mid, int right){
	int leftLenght = mid - left + 1;
	int rightLenght = right - mid;
	int L[leftLenght], R[rightLenght];
	
	for(int i = 0; i < leftLenght; i++){
		L[i] = arr[left + i];
	}
	for(int i = 0; i < rightLenght; i++){
		R[i] = arr[mid + 1 + i];
	}
	
	int i = 0, j = 0, k = left;
	while(i < leftLenght && j < rightLenght){
		if(L[i] < R[j]){
			arr[k] = L[i];
			i++;
		} 
		else {
			arr[k] = R[j];
			j++;			
		}
		k++;
	}
	
	while(i < leftLenght){
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while(j < rightLenght){ 
		arr[k] = R[j];
		j++;
		k++;
	}	
}

void mergeSort(int arr[], int left, int right){
	if(left >= right) return ;
	int mid = left + (right - left) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}
