
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
#include <deque>		// �յڿ��� ����� �߰��ϴ� ������ ����  
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

extern bool ����;

//void print(int[]);
//void print(int a[])
//{
//	// a �� ����� �� �� ����. 
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
	MySaveFileCode::Save_File("8���� �ڷ�/8����_1.cpp", "8���� �ڷ�/SPAN.txt�б�.txt");
	MySaveFileCode::Save_File_Auto(8, 1);
}

#endif
