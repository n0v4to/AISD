#include "sort.h"
#include "analysis.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;



int main() {

	vector<size_t> lens_arr = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000 };
	int min = 1;
	int max = 50000;

	cout << "Statistics of the reverse array for comb_sort" << endl;
	get_stats_for_sort(lens_arr, generate_reverse_sort_array, comb_sort);    
	cout << "Statistics of the random array for comb_sort" << endl;
	get_stats_for_random(min, max, lens_arr, comb_sort);    
	cout << "Statistics of the sort array for comb_sort" << endl;
	get_stats_for_sort(lens_arr, generate_sort_array, comb_sort);    


	cout << "Statistics of the sort array for insertion_sort" << endl;
	get_stats_for_sort(lens_arr, generate_sort_array, insertion_sort);   
	cout << "Statistics of the reverse array for insertion_sort" << endl;
	get_stats_for_sort(lens_arr, generate_reverse_sort_array, insertion_sort);   
	cout << "Statistics of the random array for insertion_sort" << endl;
	get_stats_for_random(min, max, lens_arr, insertion_sort);


	cout << "Statistics of the sort array for quick_sort" << endl;
	get_stats_for_sort(lens_arr, generate_sort_array, quick_sort_wrapper);
	cout << "Statistics of the reverse array for quick_sort" << endl;
	get_stats_for_sort(lens_arr, generate_reverse_sort_array, quick_sort_wrapper);
	cout << "Statistics of the random array for quick_sort" << endl;
	get_stats_for_random(min, max, lens_arr, quick_sort_wrapper);

	return 0;
}