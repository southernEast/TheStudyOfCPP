#include <iostream>
#include <ctime>
#include <array>
#include <vector>
#include <string>
using namespace std;

template<class T, size_t size>
bool binarySearch(const array<T, size>& items, const T& val) {	// 二分查找
	int low = 0, high = items.size() - 1, mid;
	
	while (low <= high) {
		mid = (low + high + 1) / 2;
		if (val < items[mid])
			high = mid - 1;
		else if (val > items[mid])
			low = mid + 1;
		else
			return true;
	}
	return false;
}

template<typename T, size_t size>								// 递归二分查找
int recursiveBinarySearch(array<T, size> items, const T& value, int begin, int end) {
	if (begin > end)
		return -1;
	int middle = (begin + end) / 2;
	if (value == items[middle])
		return middle;
	else if (value < items[middle])
		return recursiveBinarySearch(items, value, begin, middle - 1);
	else
		return recursiveBinarySearch(items, value, middle + 1, end);
}

template<typename T, size_t size>
void insertSort(array<T, size>& items) {				// 插入排序
	T insertElem;
	for (int i = 1; i < size; ++i) {
		insertElem = items[i];
		int pos = i;
		while (pos > 0 && items[pos - 1] > insertElem) {
			items[pos] = items[pos - 1];
			--pos;
		}
		items[pos] = insertElem;
	}
}

template<typename T, size_t size>
void selectSort(array<T, size>& items) {			// 选择排序
	size_t minPos = 0;
	for (size_t currentPos = 0; currentPos < size - 1; ++currentPos) {
		minPos = currentPos;
		for (size_t i = currentPos + 1; i < size; ++i)
			if (items[minPos] > items[i])
				minPos = i;
		swap(items[minPos], items[currentPos]);
	}
}

template<typename T, size_t size>					// 归并
void merge(array<T, size>& items, size_t left1, size_t right1, size_t left2, size_t right2) {
	array<T, size> ans;
	size_t pos, leftPos, rightPos;
	pos = leftPos = left1;
	rightPos = left2;
	
	while (leftPos <= right1 && rightPos <= right2) {
		if (items[leftPos] <= items[rightPos])
			ans[pos++] = items[leftPos++];
		else
			ans[pos++] = items[rightPos++];
	}	
	while (leftPos <= right1)
		ans[pos++] = items[leftPos++];
	while (rightPos <= right2)
		ans[pos++] = items[rightPos++];
	for (size_t i = left1; i <= right2; ++i) {
		items[i] = ans[i];
		cout << ans[i] << " ";
	}
	cout << endl;
}

template<typename T, size_t size>					// 归并排序
void mergeSort(array<T, size>& items, size_t low, size_t high) {
	if (low < high) {
		int middle1 = (low + high) / 2;
		int middle2 = middle1 + 1;
		
		mergeSort(items, low, middle1);
		mergeSort(items, middle2, high);

		merge(items, low, middle1, middle2, high);
	}
}

template<typename T, size_t size>					// 冒泡排序
void bubbleSort(array<T, size>& items) {
	bool change = true;
	for (int i = size - 1; i > 0 && change; --i) {
		change = false;
		for (int j = 0; j < i; ++j) {
			if (items[j] > items[j + 1]) {
				swap(items[j], items[j + 1]);
				change = true;
			}
		}
	}
}

template<size_t size>								// 桶排序
void bucketSort(array<int, size>& items) {
	array<vector<int>, 10> bucket;
	int maxElem = items[0];
	for (size_t i = 0; i < items.size(); ++i)
		if (maxElem < items[i])
			maxElem = items[i];
	int numOfDigit = 0;
	while (maxElem) {			// 计算出最大元素的位数
		++numOfDigit;
		maxElem /= 10;
	}

	for (int i = 0; i < numOfDigit; ++i) {	// 循环最大元素位数次
		int insertPos;
		for (size_t j = 0; j < size; ++j) {	// 获取当前位的数字，并分散至相应的各个bucket中
			insertPos = items[j];
			for (int times = 0; times < i; ++times)
				insertPos /= 10;
			insertPos %= 10;
			bucket[insertPos].push_back(items[j]);
		}
		int pos = 0;
		for (size_t j = 0; j < 10; ++j) {
			for (size_t k = 0; k < bucket[j].size(); ++k)	// 收集bucket中的数
				items[pos++] = bucket[j][k];
			while (!bucket[j].empty())			// bucket清空
				bucket[j].pop_back();
		}
	}
}


template<typename T, size_t size>		// 确定一个位置
int partition(array<T, size>&items, int low, int high) {
	T pivot = items[low];
	while (low < high) {
		while (low < high && items[high] >= pivot)
			--high;
		items[low] = items[high];
		while (low < high && items[low] <= pivot)
			++low;
		items[high] = items[low];
	}
	items[low] = pivot;
	return low;
}

template<typename T, size_t size>		// 快速排序
void quickSort(array<T, size>& items, int low, int high) {
	if (low < high) {
		int mid = partition(items, low, high);
		quickSort(items, low, mid - 1);
		quickSort(items, mid + 1, high);
	}
}


int main() {
	const int SIZE = 20;
	array<int, SIZE> items;
	srand(time(0));
	for (auto& item : items) {
		item = rand() % 10;
	}

	for (size_t i = 0; i < items.size(); ++i) {
		cout << items[i] << " ";
	}
	cout << endl;
	quickSort(items, 0, SIZE - 1);

	for (size_t i = 0; i < items.size(); ++i) {
		cout << items[i] << " ";
	}
	

	return 0;
}