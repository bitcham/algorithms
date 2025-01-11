#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

template<typename T>
void Print(vector<T>& arr)
{
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
}

void CountingSort(vector<string>& arr, int k, int d)
{
	vector<string> temp = arr; // 복사
	std::fill(arr.begin(), arr.end(), "   "); // 디버깅 편의

	// TODO:
	vector<int> count(k + 1, 0);
	for (auto a : temp) count[a[d] - 'A']++;
	for (int i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		arr[count[temp[i][d] - 'A'] - 1] = temp[i];
		count[temp[i][d] - 'A']--;
	}
}

void RadixSort(vector<string>& arr)
{
	int k = 26;
	
	for (int i = 2; i >= 0; i--) {
		CountingSort(arr, k, i);
		Print(arr);
	}

}

int main()
{
	// CLRS 8.3-1
	vector<string> arr = { "COW", "DOG", "SEA", "RUG",
		"ROW", "MOB", "BOX", "TAB", "BAR", "EAR", "TAR",
		"DIG", "BIG", "TEA", "NOW", "FOX" };

	Print(arr);

	RadixSort(arr);

	Print(arr);

	return 0;
}