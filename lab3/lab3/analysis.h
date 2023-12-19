#pragma once
#include "sort.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

stats average_stats_for_random(int min, int max, size_t len, stats(*sort_func)(vector<int>& arr)) {
    stats average_results;

    for (size_t i = 0; i < 100; ++i) {
        vector<int> data = generate_random_array(min, max, len);
        stats a = sort_func(data);
        average_results.comparison_count += a.comparison_count;
        average_results.copy_count += a.copy_count;
    }
    average_results.comparison_count /= 100;
    average_results.copy_count /= 100;

    return average_results;
}

void get_stats_for_random(int min, int max, const vector<size_t>& len, stats(*sort_func)(vector<int>& arr)) {
    for (size_t i = 0; i < len.size(); ++i) {
        stats results = average_stats_for_random(min, max, len[i], sort_func);
        cout << "Length: " << len[i] << endl;
        cout << "Comparison count: " << results.comparison_count << endl;
        cout << "Copy count: " << results.copy_count << endl;
    }
    cout << endl;
}

void get_stats_for_sort(const vector<size_t>& len, vector<int>(*generate_func)(size_t length), stats(*sort_func)(vector<int>& arr)) {
    for (size_t i = 0; i < len.size(); ++i) {
        vector<int> a = generate_func(len[i]);
        stats results = sort_func(a);
        cout << "Length: " << len[i] << endl;
        cout << "Comparison count: " << results.comparison_count << endl;
        cout << "Copy count: " << results.copy_count << endl;
    }
    cout << endl;
}