// --------------------------------------------------
//	2023 1 학기 STL 4월 03일 TUE 23 Tue 56 ( 5주 1)
// --------------------------------------------------
// STL 소개 - 중간시험 8주차 
// --------------------------------------------------
#include <iostream>
#include <array> // 템플릿 이기 때문에 소스가 오픈되어 있다. 
#include <string>
#include <fstream>
#include <algorithm>


#include "String.h"
#include "save.h"

using namespace std;

// -------	
int main()
// -------
{
	//array<std::string, 100> a;
	array<String, 100> a;

	// [문제] a에 "소스.cpp" 단어 100개를읽어와라.
	std::ifstream In{ "5주차_2.cpp" };
	for (int i = 0; i < 100; ++i) {
		In >> a[i];
	}

	// 길이 오름차순으로 정렬한 후 출력하라. 
	sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});
	
	for (int i = 0; i < 100; ++i) {
		cout << a[i] << endl;
	}



	//MySaveFileCode::Save_File("5주차_2.cpp", "5주차_2.txt");
	//MySaveFileCode::Save_File("String.h", "String_Class.txt");
	//MySaveFileCode::Save_File("String.cpp", "String_Class.txt");
}


