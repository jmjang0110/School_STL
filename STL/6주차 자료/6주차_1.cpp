//#define SIXTH_FIRST
#ifdef SIXTH_FIRST


// --------------------------------------------------
//	2023 1 학기 STL 4월 10일 MON 23 Tue 56 ( 5주 1)
// --------------------------------------------------
//	Sequence Container - vector - dynamic array ( 크기가 변한다 ) - Release 에서 해야한다.
// --------------------------------------------------

#include <iostream>
#include <array>
#include <vector>
#include <thread>

#include <fstream>
#include <algorithm>
#include <numeric>


#include "String.h"
#include "../save.h"
using namespace std;


int main(void)
{
	// [문제] - 키보드에서 int 를  읽어와라 
	// 입력이 끝나면  합계와 평균을 출력

	std::ifstream InFile{ "6주차_1.cpp" };

	/* 교수님 코드*/
	char c;
	std::string str;
	int num{};
	int sum{ 0 };
	vector <int> vNum;

	while (cin >> num) {
		vNum.push_back(num); // Ctrl + Z 누르면 입력이 자동으로 종료  
		sum += num;

	}
	cout << "sum : " << sum << " average : " << sum / vNum.size() << endl;
	int sum = accumulate(vNum.begin(), vNum.end(), 0);
	cout << "합계 평균 : " << sum << ", 평균 : " << static_cast<double>(sum) / vNum.size() << endl;




	/* 해보기 */
	vector<String> v;
	String s;
	while (cin >> s)
		v.push_back(s);

	sort(v.begin(), v.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
		});

	for (String s : v)
		cout << s << " ";
	cout << endl;

		
	//MySaveFileCode::Save_File("6주차_1.cpp", "6주차_1.txt");
}
#endif


