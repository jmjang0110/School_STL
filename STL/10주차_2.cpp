
//#define TENTH_SECOND
#ifdef	TENTH_SECOND
/*
	iterator - 포인터를 일반화 한것이 반복자이다.
	반복자 카테고리 - 입력/출력/전방향/양방향/랜덤
	template 세상에선 type_traits 를 이용하여 여분의 정보를 표현한다.
		-> 이것을 함수인자의 제약조건으로 표준화 한것이 C++ 20 의 Concepts
*/

#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include<forward_list>
#include <string>
#include <algorithm>

#include "String.h"
#include <span>


#include "save.h"
using namespace std;
extern bool 관찰;

/*
	========================================
	1. String을 STL Container로 만들어 간다.- begin(), end()

	String s{ "1234567890" };


	s[		]				   free store
	p[		]	----->	[ 1 2 3 4 5 6 7 8 9 0 ]
  int[		]			  ↑					  ↑
	 [		]		    begin				 end
	 [		]			rend				rbegin
	 [		]
	 [		]

	 span<>
	 sort() 는 RandomAccess 

	 // 심각도	코드	설명	프로젝트	파일	줄	비표시 오류(Suppression) 상태
	오류	C2676	이항 '-': 'const _RanIt'이(가) 이 연산자를 정의하지 않거나 미리 정의된 연산자에 허용되는 형식으로의 변환을 정의하지 않습니다.	
					-> _RanIt : Random Iterator 
	========================================

*/

template <class Input_Iterator, class Output_Iterator>
void my_copy(Input_Iterator b, Input_Iterator e, Output_Iterator d) {
	while (b != e) {
		*d = *b;
		++d;
		++b;

	}
}

template <class 반복자, class 값>
반복자 my_find(반복자 beg, 반복자 end, 값 val)
{
	while (beg != end) {
		if (*beg == val) {
			return beg;
		}
		++beg;
	}

	return end;


	//for (; beg != end; ++beg) {
	//	if (*beg == val)
	//		return beg;
	//}

	//return end;

}

template <class T, class Pr> 
T my_find_if(T b, T e,  Pr f ) {
	while (b != e) {
		if(f(*b) == true) /// 이거 니가 판단해줄래? 
			return b;

		++b;
	}
	return b;
		

}

int main()
{

	String s{ "여기 내용이 복사되나요?" };
	
	vector<char> v;
	v.reserve(s.size());
	//copy(s.begin(), s.end(), v.begin());
	copy(s.begin(), s.end(), back_inserter(v));

	for (char c : v) {
		cout << c;
	}
	cout << endl;



	MySaveFileCode::Save_File("10주차 자료/10주차_2.cpp", "10주차 자료/Sort 함수를 사용가능하게하는 iteartor구현 사용.txt");
	MySaveFileCode::Save_File_Auto(10, 2);
}

#endif
