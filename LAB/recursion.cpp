 #include <iostream>

/* Lab week 1, 18.10.2023 */


using namespace std;
//3
int multiply(int arr[], int n) {
	if (n == 1) {
		return arr[0];
	}
	else {
		return arr[n - 1] * multiply(arr, n - 1);
	}
}
//2
void reverse(char str[], int size) {
	if (size < 0) {
		return;
	}
	cout << str[size];
	reverse(str, size - 1);
}
//1

struct DataType {
	int value;
	
};
DataType findMin(DataType arr[], int start, int end) {
	if (start == end) {
		return arr[start];
	}

	int mid = (start + end) / 2;

	DataType leftMin = findMin(arr, start, mid);
	DataType rightMin = findMin(arr, mid + 1, end);

	return (leftMin.value < rightMin.value) ? leftMin : rightMin;
}
DataType findMax(DataType arr[], int start, int end) {
	if (start == end) {
		return arr[start];
	}

	int mid = (start + end) / 2;

	DataType leftMax = findMax(arr, start, mid);
	DataType rightMax = findMax(arr, mid + 1, end);

	return (leftMax.value > rightMax.value) ? leftMax : rightMax;
}

int main() {

	//3         multiply all the elements in an array
	int arr[5];
	for (int i = 0; i < 5; i++) {
		cout << "element " << i + 1 << ": ";
		cin >> arr[i];
	}
	cout << "array is: ";
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	int n = sizeof(arr) / sizeof(arr[0]);
	int result = multiply(arr, n);
	cout << "Product of array elements are : " << result << endl;


	//2     reverse string using recursion
	int size;

	cout << "Enter the size of the string: ";
	cin >> size;

	char str[30]; 

	for (int i = 0; i < size; i++) {
		
		cin >> str[i];
	}

	cout << "\n";
	reverse(str, size - 1);
	cout << endl;


	//1  find minimum and maximum in an array using recursion
	int n;
	cout << "Enter the number of elements in the array: ";
	cin >> n;

	DataType arr[30];

	
	for (int i = 0; i < n; i++) {
		cout << "Enter element " << i + 1 << ": ";
		cin >> arr[i].value;
	}

	DataType minElement = findMin(arr, 0, n - 1);
	DataType maxElement = findMax(arr, 0, n - 1);

	cout << "Minimum element: " << minElement.value << endl;
	cout << "Maximum element: " << maxElement.value << endl;

	return 0;
}
