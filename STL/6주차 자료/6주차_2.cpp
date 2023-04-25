//#define SIXTH_SECOND
#ifdef SIXTH_SECOND


// --------------------------------------------------
//	2023 1 �б� STL 4�� 10�� MON 23 Tue 56 ( 5�� 1)
// --------------------------------------------------
//	Sequence Container - vector - dynamic array ( ũ�Ⱑ ���Ѵ� ) - Release ���� �ؾ��Ѵ�.
// 1. ������ �����ϰ� ���� ( ���Ҵ��� �ȵǵ��� �����϶� )  
//		vector�� ���Ҵ� �Ǵ� �� ���������� �ִ��� ���ϰ����� .
// 2. emplace �� �ξ� push_back ���� �ξ� ���� 
// --------------------------------------------------

#include <iostream>
#include <array>
#include <vector>
#include <thread>

#include <fstream>
#include <algorithm>
#include <numeric>
#include <array>


#include "String.h"
#include "../save.h"
using namespace std;

/*
	[ ���� ] : "6����_2.cpp" �� �о� ���ĺ��� vector�� �����϶�.
	��ҹ��� �������� ���� ������ ���� �������� ������ �󵵸� ����϶�. 


	a - 10
	b - 20

	z - 0

*/


int main(void)
{
	vector<char> vChar;
	vector<int> AlphaCnt;

	std::ifstream InFile{ "6����_2.cpp" };
	char c;
	array<int, 26> Alphabet{};

	while (InFile >> c) {
		if (isalpha(c)) {
			Alphabet[tolower(c) - 'a']++;
		}



		//if (isalpha(c)) {
		//	// �빮��
		//	if (isupper(c)) {
		//		Alphabet[c - 'A'] += 1;
		//	}
		//	// �ҹ���
		//	else {
		//		Alphabet[c - 'a'] += 1;

		//	}
		//}
	}


	for (int i = 0; i < 26; ++i) {
		cout << Alphabet[i] << endl;;
		cout << (char)('a' + i) << " - " << Alphabet[i] << endl;
	}


	MySaveFileCode::Save_File("6���� �ڷ�/6����_2.cpp", "6���� �ڷ�/6����_2.txt");

}
#endif


