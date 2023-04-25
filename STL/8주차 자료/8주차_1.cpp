
//#define EIGHT_FIRST
#ifdef	EIGHT_FIRST

// ============================================ // 
// SPAN
// ============================================ //

#include <iostream>
#include <span>
#include <string>

#include <algorithm>
#include <vector>
#include <deque>		// 앞뒤에서 멤버를 추가하는 동작이 쉽다  
#include <list>
#include <queue>

#include <fstream>


/*
	vector -  136216567
	deque -   268435452
	list -	   85375361

*/
#include "../save.h"
#include "../String.h"

using namespace std;

extern bool 관찰;

//void print(int[]);
//void print(int a[])
//{
//	// a 가 몇개인지 알 수 없다. 
//	for (int i = 0; i < 20; ++i)
//		cout << a[i] << endl;
//	cout << endl;
//
//}

void print(span<char> s)
{
	for (auto p = s.rbegin(); p != s.rend(); ++p) {
		cout << *p;
	}
	cout << endl;

	//for (int i = 0; i < s.size(); ++i) {
	//	cout << s[i] << endl;
	//}
	//cout << endl;


}
int main()
{
	std::string s{ "Hello World" };
	print(s);

	cout << endl;
	MySaveFileCode::Save_File("8주차 자료/8주차_1.cpp", "8주차 자료/SPAN.txt읽기.txt");
	MySaveFileCode::Save_File_Auto(8, 1);
}

#endif
