
//#define TENTH_SECOND
#ifdef	TENTH_SECOND
/*
	iterator - �����͸� �Ϲ�ȭ �Ѱ��� �ݺ����̴�.
	�ݺ��� ī�װ� - �Է�/���/������/�����/����
	template ���󿡼� type_traits �� �̿��Ͽ� ������ ������ ǥ���Ѵ�.
		-> �̰��� �Լ������� ������������ ǥ��ȭ �Ѱ��� C++ 20 �� Concepts
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
extern bool ����;

/*
	========================================
	1. String�� STL Container�� ����� ����.- begin(), end()

	String s{ "1234567890" };


	s[		]				   free store
	p[		]	----->	[ 1 2 3 4 5 6 7 8 9 0 ]
  int[		]			  ��					  ��
	 [		]		    begin				 end
	 [		]			rend				rbegin
	 [		]
	 [		]

	 span<>
	 sort() �� RandomAccess 

	 // �ɰ���	�ڵ�	����	������Ʈ	����	��	��ǥ�� ����(Suppression) ����
	����	C2676	���� '-': 'const _RanIt'��(��) �� �����ڸ� �������� �ʰų� �̸� ���ǵ� �����ڿ� ���Ǵ� ���������� ��ȯ�� �������� �ʽ��ϴ�.	
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

template <class �ݺ���, class ��>
�ݺ��� my_find(�ݺ��� beg, �ݺ��� end, �� val)
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
		if(f(*b) == true) /// �̰� �ϰ� �Ǵ����ٷ�? 
			return b;

		++b;
	}
	return b;
		

}

int main()
{

	String s{ "���� ������ ����ǳ���?" };
	
	vector<char> v;
	v.reserve(s.size());
	//copy(s.begin(), s.end(), v.begin());
	copy(s.begin(), s.end(), back_inserter(v));

	for (char c : v) {
		cout << c;
	}
	cout << endl;



	MySaveFileCode::Save_File("10���� �ڷ�/10����_2.cpp", "10���� �ڷ�/Sort �Լ��� ��밡���ϰ��ϴ� iteartor���� ���.txt");
	MySaveFileCode::Save_File_Auto(10, 2);
}

#endif
