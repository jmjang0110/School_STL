
//#define ELEVENTH_FIRST
#ifdef	ELEVENTH_FIRST
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>


#include "../save.h"
#include "../String.h"

using namespace std;
extern bool 관찰;
/*
	1. String 에 ,operator<를 제공 
	2. less<String> 을 ( Specialization )
	3. 호출가능타입을 전달
*/

template<>
// 컴파일러가 확장하지 못하도록 Specialization 해준다. 
struct less <String> {
	// operator() : 함수 호출 연산자 
	bool operator()( const String& a, const String& b) const {
		// 길이 순 정렬
		return a.size() < b.size();
	}
};

// 컴파일러가 확장하지 못하도록 Specialization 해준다. 
//template<>
//struct 소문자우선<String>{
//	// operator() : 함수 호출 연산자 
//	bool operator()(const String& a, const String& b) const {
//		// 소문자우선 - 첫글자 기준
//		// 소소 소대 대소 대대
//		if (isupper(*(a.begin())))
//		{
//			if(islower( *(b.begin())) )
//				return true;
//		}
//		return false;
//
//	}
//
//};
int main()
{
	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	set<String> v{ std::istream_iterator<String>{in}, {} }; 
	cout << "읽은 개수 :" << v.size() << endl;

	관찰 = true;
	String temp = { "f" };
	관찰 = false;

	while (true) {
		cout << "문자 입력:" ;
		char c;
		cin >> c;
		cout << c << "가 포함된 STr 입니다.";
		for (const String& s : v) {
			std::string str = s.getString();
			if (str.contains(c))
				cout << s << ' ' << endl;

		}


	}

	MySaveFileCode::Save_File("11주차 자료/11주차_1.cpp", "11주차 자료/이상한나라의 앨리스교수님 실습.txt");
	MySaveFileCode::Save_File_Auto(11, 1);
}

#endif
