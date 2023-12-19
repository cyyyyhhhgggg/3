#include<iostream>
#include<vector>
#include<string>
using namespace std;

//øÏ≈≈
int partion(vector<int>& arr, int i, int j) {
	int p = arr[i];
	while (i < j) {
		while (i < j && arr[j] >= p) j--;
		arr[i] = arr[j];
		while (i < j && arr[i] <= p) i++;
		arr[j] = arr[i];
	}
	arr[i] = p;
	return i;
}

void quicksort(vector<int>& arr, int i, int j) {
	if (i < j) {
		int p = partion(arr, i, j);
		quicksort(arr, i, p - 1);
		quicksort(arr, p + 1, j);
	}
}

//πÈ≈≈
void Merge(vector<int>& arr, vector<int>& help, int low, int mid, int high) {
	for (int i = 0; i < arr.size(); i++) help[i] = arr[i];
	int i = low, j = mid + 1, k = i;
	for (; i <= mid && j <= high; ) {
		if (help[i] <= help[j]) arr[k++] = help[i++];
		else arr[k++] = help[j++];
	}
	while(i <= mid) arr[k++] = help[i++];
	while(j <= high) arr[k++] = help[j++];
}

void mergeSort(vector<int>& arr, vector<int>& help, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(arr, help, low, mid);
		mergeSort(arr, help, mid + 1, high);
		Merge(arr, help, low, mid, high);
	}
}

//∂—≈≈
void headAdjust(vector<int>& arr, int k, int len) {
	int tmp = arr[k];
	for (int i = 2 * k + 1; i <= len; i *= 2) {
		if (i < len && arr[i + 1] > arr[i]) i++;
		if (tmp >= arr[i]) break;
		else {
			arr[k] = arr[i];
			k = i;
		}
	}
	arr[k] = tmp;
}

void buildHeap(vector<int>& arr) {
	int sz = arr.size() - 1;
	for (int i = arr.size() / 2 - 1; i >= 0; i--) {
		headAdjust(arr, i, sz);
	}
}

void heapSort(vector<int>& arr) {
	buildHeap(arr);
	for (int i = arr.size() - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		headAdjust(arr, 0, i - 1);
	}
}

void selectSort(vector<int>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int tmp = i, min = arr[i];
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < min) {
				tmp = j; min = arr[j];
			}
		}
		swap(arr[i], arr[tmp]);
	}
}

int main() {
	vector<int> v = { 7,2,4,1,10,6,3,9,5 };
	//quicksort(v, 0, v.size() - 1);
	vector<int> hp(v.size());
	int sz = v.size() - 1;
	//mergeSort(v, hp, 0, sz);
	heapSort(v);
	//for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	selectSort(v);
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	return 0;
}

