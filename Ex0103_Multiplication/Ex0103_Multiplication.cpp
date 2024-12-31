﻿#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Multiply(string str1, string str2)
{
	if (!str1.size() || !str2.size())
		return "0";

	int N = max(str1.size(), str2.size());
	str1 = string(N - str1.size(), '0') + str1; 
	str2 = string(N - str2.size(), '0') + str2;

	string result(2 * N, '0');

	for (int i = N - 1; i >= 0; i--) // 역순
	{
		int carry = 0;
		int n1 = str1[i] - '0';
		int k = N + i; // 결과를 저장할 위치의 인덱스
		for (int j = N - 1; j >= 0; j--) // 역순
		{
			// TODO:
			k -= 1; // <- k가 하나씩 감소

			// Trace (변수에 저장된 값들의 변화를 추적)
			// cout << n1 << " " << n2 << " " << carry << " " << result << endl;
		}
		// 마지막에는 carry만
		// TODO:
	}

	// 불필요한 '0' 제거
	// TODO:

	return result;
}


int main()
{
	vector<vector<string>> tests = {
		{"12", "34", std::to_string(12 * 34)},
		{"123", "45", std::to_string(123 * 45)},
		{"5555", "55", std::to_string(5555 * 55)},
		{"5555", "5555", std::to_string(5555 * 5555)},
		{"98234712354214154", "171454654654655", "16842798681791158832220782986870"}
		// , {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "16842798681791114273590624445460185389471221520083884298838480662480"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];
		const string str2 = t[1];
		const string expected = t[2];

		cout << str1 << " * " << str2 << " = " << expected << endl;

		const string result = Multiply(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK";
		else {
			cout << "Not OK";
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
