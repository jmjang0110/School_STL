//#define FIFTH_FIRST
#ifdef FIFTH_FIRST

// --------------------------------------------------
//	2023 1 �б� STL 4�� 03�� TUE 23 Tue 56 ( 5�� 1)
// --------------------------------------------------
// STL �Ұ� 
// zxcv
/*
	1. ������ �а� ���� �����ؾ� �Ѵ�.
	2. 
*/

/*
	STL
		- �ڷᱸ�� ( Container ) + �˰���
		- STL �� ����? >>	ǥ�ض��̺귯���ε� �ڷᱸ���� �˰����� �����Ѵ�.
							�ݺ��ڸ� �̿��Ѵ�. 
		- ��� 
			- Generic Programming, Containter, Iterator, Algorithm
			- Adaptor, Predicates, Function Object, Callable Types 
			- Concepts, Ranges, Span

		STL Components
			- STL �� ������Ʈ ( �����̳�, �ݺ���, �˰��� ) 

		Adaptor 
		Predicates			: ���ϰ��� �³� Ʋ���ĸ� �Ǵ����ش�. 
		Function Objects	: 

		STL 
		�Է� ����Ƽ�ʰ� �ΰ��ε�, � �˰����� �����̳ʸ� 
		�ݺ��ڸ� �̿��ؼ� ����� �����´�. 

		STL Sequence Container ( Q(n )
			- array 
			- vector
			- deque : �� ( ��ť �ƴϴ� )
			- forward_list
			- list 
		STL Associative Containers ( Q(logn)
			- set
			- map 
			- multiset
			- multimap
			-> �׻� ���Ļ��� ���� - ������ ����(ã��) ���� �α�n 
		
		STL Unordered Associative Containers ( Q(1) )
			- Hash Function 
			 - �� ���� ã������ ����. 
			
*/


#include <iostream>
#include "String.h"
#include "save.h"

using namespace std;


// -------	
int main().
// -------
{

	MySaveFileCode::Save_File("5����_1.cpp", "5����_1.txt");
	//MySaveFileCode::Save_File("String.h", "String_Class.txt");
	//MySaveFileCode::Save_File("String.cpp", "String_Class.txt");

	// dangling pointer - static ������ ����ų�� ��۸� �ɸ��� ���α׷� ��� 

}
#endif // FIFTH_FIRST

