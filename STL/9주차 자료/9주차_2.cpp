
//#define NINE_SECOND
#ifdef	NINE_SECOND
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


#include "../save.h"

using namespace	std;

 /// _ 쓰면 안됨!!! 


//void printCategory(std::vector<int>::iterator iter_Begin, std::vector<int>::iterator iter_End) {
//
//}
template<class Iter>
void printCategory(Iter it)
{
	//cout << typeid(it).name() << endl; 

	// 자료형 iter 가 도대체 어떤 Category 인가?
	// 표준 iteartor 는 반드시 여분의 자료형을 제공해야 한다. 
	//cout <<  "Category - " << typeid(Iter::iterator_concept).name() << endl;;
	cout << "Category - " <<
		typeid(iterator_traits<Iter>::iterator_category).name() << endl;

	// 전통적인 분류는 다섯가지 -> vector  는 다른 방식으로 구분한다. 



}
int add(int a, int b) {
	cout << typeid(a).name() << endl;


	return a + b;
}

int main()
{
	// 문제 : 반복자를 전달받아 어떤 종류의 반복자인지 화면에 출력하라
	// 함수 printCategory()를 선언하고 정의하라.

	//volatile const const const int const const num = 100;
	// CV Qualifier
	// volatile , const 가 둘이 상충되는 건데 되네..?

	vector<int> v;

	//void printCategory(std::vector<int>::iterator, std::vector<int>::iterator);
	
	///printCategory(istream_iterator<char>{cin});
	///printCategory(ostream_iterator<char>{cout});
	///printCategory(forward_list<int>().begin());
	///printCategory(list<int>::const_iterator());
	///printCategory(vector<int>::iterator());
	///printCategory(deque<char>::iterator());

	// 전통적인 분류는 다섯가지 - vector 는 다른 방식으로 구분한다 

	int* p;
	printCategory(p);

	//printCategory(v.begin());
	add(1, 3);

	MySaveFileCode::Save_File("9주차 자료/9주차_2.cpp", "9주차 자료/[2]Iterator실습.txt");
	MySaveFileCode::Save_File_Auto(9, 2);
}

#endif
