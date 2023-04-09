//#define FIFTH_FIRST
#ifdef FIFTH_FIRST

// --------------------------------------------------
//	2023 1 학기 STL 4월 03일 TUE 23 Tue 56 ( 5주 1)
// --------------------------------------------------
// STL 소개 
// zxcv
/*
	1. 데이터 읽고 쓰기 가능해야 한다.
	2. 
*/

/*
	STL
		- 자료구조 ( Container ) + 알고리즘
		- STL 이 뭐야? >>	표준라이브러리인데 자료구조와 알고리즘을 제공한다.
							반복자를 이용한다. 
		- 용어 
			- Generic Programming, Containter, Iterator, Algorithm
			- Adaptor, Predicates, Function Object, Callable Types 
			- Concepts, Ranges, Span

		STL Components
			- STL 은 컴포넌트 ( 컨테이너, 반복자, 알고리즘 ) 

		Adaptor 
		Predicates			: 리턴값이 맞냐 틀리냐를 판단해준다. 
		Function Objects	: 

		STL 
		입력 컨에티너가 두개인데, 어떤 알고리즘이 컨테이너를 
		반복자를 이용해서 결과를 내놓는다. 

		STL Sequence Container ( Q(n )
			- array 
			- vector
			- deque : 덱 ( 디큐 아니다 )
			- forward_list
			- list 
		STL Associative Containers ( Q(logn)
			- set
			- map 
			- multiset
			- multimap
			-> 항상 정렬상태 유지 - 빠르게 응답(찾기) 가능 로그n 
		
		STL Unordered Associative Containers ( Q(1) )
			- Hash Function 
			 - 더 빨리 찾으려고 쓴다. 
			
*/


#include <iostream>
#include "String.h"
#include "save.h"

using namespace std;


// -------	
int main().
// -------
{

	MySaveFileCode::Save_File("5주차_1.cpp", "5주차_1.txt");
	//MySaveFileCode::Save_File("String.h", "String_Class.txt");
	//MySaveFileCode::Save_File("String.cpp", "String_Class.txt");

	// dangling pointer - static 포인터 가리킬때 댕글링 걸리면 프로그램 사망 

}
#endif // FIFTH_FIRST

