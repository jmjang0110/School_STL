
//#define NINE_SECOND
#ifdef	NINE_SECOND
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


#include "../save.h"

using namespace	std;

 /// _ ���� �ȵ�!!! 


//void printCategory(std::vector<int>::iterator iter_Begin, std::vector<int>::iterator iter_End) {
//
//}
template<class Iter>
void printCategory(Iter it)
{
	//cout << typeid(it).name() << endl; 

	// �ڷ��� iter �� ����ü � Category �ΰ�?
	// ǥ�� iteartor �� �ݵ�� ������ �ڷ����� �����ؾ� �Ѵ�. 
	//cout <<  "Category - " << typeid(Iter::iterator_concept).name() << endl;;
	cout << "Category - " <<
		typeid(iterator_traits<Iter>::iterator_category).name() << endl;

	// �������� �з��� �ټ����� -> vector  �� �ٸ� ������� �����Ѵ�. 



}
int add(int a, int b) {
	cout << typeid(a).name() << endl;


	return a + b;
}

int main()
{
	// ���� : �ݺ��ڸ� ���޹޾� � ������ �ݺ������� ȭ�鿡 ����϶�
	// �Լ� printCategory()�� �����ϰ� �����϶�.

	//volatile const const const int const const num = 100;
	// CV Qualifier
	// volatile , const �� ���� ����Ǵ� �ǵ� �ǳ�..?

	vector<int> v;

	//void printCategory(std::vector<int>::iterator, std::vector<int>::iterator);
	
	///printCategory(istream_iterator<char>{cin});
	///printCategory(ostream_iterator<char>{cout});
	///printCategory(forward_list<int>().begin());
	///printCategory(list<int>::const_iterator());
	///printCategory(vector<int>::iterator());
	///printCategory(deque<char>::iterator());

	// �������� �з��� �ټ����� - vector �� �ٸ� ������� �����Ѵ� 

	int* p;
	printCategory(p);

	//printCategory(v.begin());
	add(1, 3);

	MySaveFileCode::Save_File("9���� �ڷ�/9����_2.cpp", "9���� �ڷ�/[2]Iterator�ǽ�.txt");
	MySaveFileCode::Save_File_Auto(9, 2);
}

#endif
