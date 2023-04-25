//#define SIXTH_SECOND
#ifdef SIXTH_SECOND


// --------------------------------------------------
//	2023 1 학기 STL 4월 10일 MON 23 Tue 56 ( 5주 1)
// --------------------------------------------------
//	Sequence Container - vector - dynamic array ( 크기가 변한다 ) - Release 에서 해야한다.
// 1. 공간을 예약하고 쓰지 ( 재할당이 안되도록 유의하라 )  
//		vector가 재할당 되는 게 장점이지만 최대한 안하게하자 .
// 2. emplace 가 훨씬 push_back 보다 훨씬 좋다 
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
	[ 문제 ] : "6주차_2.cpp" 를 읽어 알파벳만 vector에 저장하라.
	대소문자 구분하지 말고 다음과 같은 형식으로 문자의 빈도를 출력하라. 


	a - 10
	b - 20

	z - 0

*/


int main(void)
{
	vector<char> vChar;
	vector<int> AlphaCnt;

	std::ifstream InFile{ "6주차_2.cpp" };
	char c;
	array<int, 26> Alphabet{};

	while (InFile >> c) {
		if (isalpha(c)) {
			Alphabet[tolower(c) - 'a']++;
		}



		//if (isalpha(c)) {
		//	// 대문자
		//	if (isupper(c)) {
		//		Alphabet[c - 'A'] += 1;
		//	}
		//	// 소문자
		//	else {
		//		Alphabet[c - 'a'] += 1;

		//	}
		//}
	}


	for (int i = 0; i < 26; ++i) {
		cout << Alphabet[i] << endl;;
		cout << (char)('a' + i) << " - " << Alphabet[i] << endl;
	}


	MySaveFileCode::Save_File("6주차 자료/6주차_2.cpp", "6주차 자료/6주차_2.txt");

}
#endif


