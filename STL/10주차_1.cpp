
//#define TENTH_FIRST
#ifdef	TENTH_FIRST
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

	========================================

*/

void ShowCategory(String_iterator iter) {

	cout << typeid(String_iterator::iterator_category).name() << endl;

}

int main()
{
	//String s{ "1234567890" };

	//// STL 컨테이너라면 begin(), end() 를 class 로 코딩해야한다.
	//for (auto p = s.rbegin(); p != s.rend(); p.operator++()) {
	//	cout << p.operator*() << ' ';
	//}
	//cout << endl;

	//// s 가 제공하는 반복자가 random_access_iterator_tag 가 되도록 하려면  
	//cout << ((s.begin())::iterator_categpry).name() << endl;

	//ShowCategory(s.begin());


	String s{ "The quick brown fox jumps over the lazy dog" };

	sort(s.begin(), s.end());

	cout << s << endl;



	MySaveFileCode::Save_File("10주차 자료/10주차_1.cpp", "10주차 자료/String::String_reverse_iteartor 사용.txt");
	MySaveFileCode::Save_File_Auto(10, 1);
}

#endif
