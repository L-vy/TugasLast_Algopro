int linearSearch(int arr[], int size, int data){
	for(int i = 0; i < size; i++){
		if(arr[i] == data){
			return i;
		}
	}
	return -1;
}

int binarySearch(int arr[], int left, int right, int data){
	if(left <= right){
		int mid = (right - left) / 2 + left;
		
		if(data == arr[mid]){
			return mid;
		}
		else if(data > arr[mid]){
			return binarySearch(arr, mid+1, right, data);
		}
		else if(data < arr[mid]){
			return binarySearch(arr, left, mid-1, data);
		}
	}
	return -1;
}

int interpolationSearch(int arr[], int left, int right, int data) {
	int mid;
	if (left <= right && data >= arr[left] && data <= arr[right]) {
		mid = left + ((double)(right - left) / (arr[right] - arr[left])) 
				* (data - arr[left]);
					
		if (arr[mid] == data) return mid;
		if (arr[mid] < data) return interpolationSearch(arr, mid + 1, right, data);
		if (arr[mid] > data) return interpolationSearch(arr, left, mid - 1, data);
	}
	return -1;
}
