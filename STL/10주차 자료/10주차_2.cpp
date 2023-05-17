
#define TENTH_SECOND
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


#include "../save.h"
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

void ShowCategory(String_iterator iter) {

	cout << typeid(String_iterator::iterator_category).name() << endl;

}

int main()
{

	String s{ "The quick brown fox jumps over the lazy dog" };

	sort(s.begin(), s.end());

	cout << s << endl;



	MySaveFileCode::Save_File("10���� �ڷ�/10����_2.cpp", "10���� �ڷ�/Sort �Լ��� ��밡���ϰ��ϴ� iteartor����.txt");
	MySaveFileCode::Save_File_Auto(10, 2);
}

#endif
