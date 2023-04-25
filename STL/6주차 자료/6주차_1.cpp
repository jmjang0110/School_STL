//#define SIXTH_FIRST
#ifdef SIXTH_FIRST


// --------------------------------------------------
//	2023 1 �б� STL 4�� 10�� MON 23 Tue 56 ( 5�� 1)
// --------------------------------------------------
//	Sequence Container - vector - dynamic array ( ũ�Ⱑ ���Ѵ� ) - Release ���� �ؾ��Ѵ�.
// --------------------------------------------------

#include <iostream>
#include <array>
#include <vector>
#include <thread>

#include <fstream>
#include <algorithm>
#include <numeric>


#include "String.h"
#include "../save.h"
using namespace std;


int main(void)
{
	// [����] - Ű���忡�� int ��  �о�Ͷ� 
	// �Է��� ������  �հ�� ����� ���

	std::ifstream InFile{ "6����_1.cpp" };

	/* ������ �ڵ�*/
	char c;
	std::string str;
	int num{};
	int sum{ 0 };
	vector <int> vNum;

	while (cin >> num) {
		vNum.push_back(num); // Ctrl + Z ������ �Է��� �ڵ����� ����  
		sum += num;

	}
	cout << "sum : " << sum << " average : " << sum / vNum.size() << endl;
	int sum = accumulate(vNum.begin(), vNum.end(), 0);
	cout << "�հ� ��� : " << sum << ", ��� : " << static_cast<double>(sum) / vNum.size() << endl;




	/* �غ��� */
	vector<String> v;
	String s;
	while (cin >> s)
		v.push_back(s);

	sort(v.begin(), v.end(), [](const String& a, const String& b) {
		return a.getString() < b.getString();
		});

	for (String s : v)
		cout << s << " ";
	cout << endl;

		
	//MySaveFileCode::Save_File("6����_1.cpp", "6����_1.txt");
}
#endif


