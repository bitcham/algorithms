#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 문제 1. 10진수 -> 2진수
	{
		int decimal = 105;
		string binary;

		//TODO:
		while (decimal > 0) {
			int temp = decimal % 2;
			binary = to_string(temp) + binary;
			decimal /= 2;
		}

		cout << binary << endl; // 1101001
	}

	// 문제 2. 문자열 뒤집기
	{
		string input = "Hello, World!";

		// TODO:
		int left = 0;
		int right = input.size() - 1;
		while (left < right) {
			swap(input[left], input[right]);
			left++;
			right--;
		}

		cout << input << endl; // !dlroW ,olleH
	}

	// 문제 3. 모든 자리 다 더하기
	{
		string n = "789789";

		// TODO:
		
		while (n.size() != 1) {
			int sum = 0;
			for (int i = 0; i < n.size(); i++) {
				sum += n[i] - '0';
			}
			n = to_string(sum);
		}
		

		

		cout << n << endl;
	}

	return 0;
}
