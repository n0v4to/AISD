#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

template<typename T>
stats insertion_sort(vector<T>& data) {
	stats sorting_state;
	for (size_t i = 1; i < data.size(); ++i) {
		int key = data[i];
		size_t j = i;
		if (data[j - 1] <= key)
			++sorting_state.comparison_count;
		while (j > 0 && data[j - 1] > key) {
			++sorting_state.comparison_count;
			data[j] = data[j - 1];
			data[j - 1] = key;
			++sorting_state.copy_count;
			--j;
			if (j > 0 && data[j - 1] <= key)
				++sorting_state.comparison_count;
		}
	}
	return sorting_state;
}

template<typename T>
int partition(vector<T>& data, int low, int high, stats& sorting_state) {
	int pivotIndex = low + rand() % (high - low + 1);
	T pivot = data[pivotIndex];
	swap(data[pivotIndex], data[high]);

	int ind = low;

	for (size_t i = low; i < high; ++i) {
		sorting_state.comparison_count++;
		if (data[i] < pivot) {
			sorting_state.copy_count++;
			swap(data[i], data[ind]);
			++ind;
		}
	}

	swap(data[ind], data[high]);
	sorting_state.copy_count++;

	return ind;
}


template<typename T>
void quick_sort(vector<T>& data, int low, int high, stats& sorting_state) {
	if (low < high) {
		int partition_index = partition(data, low, high, sorting_state);

		quick_sort(data, low, partition_index - 1, sorting_state);
		quick_sort(data, partition_index + 1, high, sorting_state);
	}
}

template<typename T>
stats quick_sort_wrapper(vector<T>& data) {
	stats sorting_state;
	quick_sort(data, 0, data.size() - 1, sorting_state);
	return sorting_state;
}

template<typename T>
stats comb_sort(vector<T>& data) {
	stats sorting_state;
	int n = data.size();
	int gap = n;
	bool swapped = true;

	while (gap > 1 || swapped) {
		gap = (gap * 10) / 13;
		if (gap < 1) {
			gap = 1;
		}
		int i = 0;
		swapped = false;
		while (i + gap < n) {
			++sorting_state.comparison_count;
			if (data[i] > data[i + gap]) {
				swap(data[i], data[i + gap]);
				++sorting_state.copy_count;
				swapped = true;
			}
			++i;
		}
	}

	return sorting_state;
}

int random(int x, int y) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(x, y);
	return dist(gen);
}

vector<int> generate_random_array(int min, int max, size_t size) {
	vector<int> data;
	for (size_t i = 0; i < size; i++)
		data.push_back(random(min, max));
	return data;
}


vector<int> generate_sort_array(size_t size) {
	vector<int> data;
	for (size_t i = 0; i < size; i++)
		data.push_back(i);
	return data;
}


vector<int> generate_reverse_sort_array(size_t size) {
	vector<int> data;
	for (size_t i = size; i > 0; --i)
		data.push_back(i);
	return data;
}

//int main() {
//	vector<int> data = { 5, 55, 2, 3, 60};
//	stats bbb = comb_sort(data);
//	cout << bbb.comparison_count << " - comparison count" << endl;
//	cout << bbb.copy_count<< " - copy count" << endl;
//	for (size_t i = 0; i < data.size(); ++i) {
//		cout << data[i] << " ";
//	}
//	cout << endl;
//}