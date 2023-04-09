// --------------------------------------------------
//	2023 1 �б� STL 4�� 03�� TUE 23 Tue 56 ( 5�� 1)
// --------------------------------------------------
// STL �Ұ� - �߰����� 8���� 
// --------------------------------------------------
#include <iostream>
#include <array> // ���ø� �̱� ������ �ҽ��� ���µǾ� �ִ�. 
#include <string>
#include <fstream>
#include <algorithm>


#include "String.h"
#include "save.h"

using namespace std;

// -------	
int main()
// -------
{
	//array<std::string, 100> a;
	array<String, 100> a;

	// [����] a�� "�ҽ�.cpp" �ܾ� 100�����о�Ͷ�.
	std::ifstream In{ "5����_2.cpp" };
	for (int i = 0; i < 100; ++i) {
		In >> a[i];
	}

	// ���� ������������ ������ �� ����϶�. 
	sort(a.begin(), a.end(), [](const String& a, const String& b) {
		return a.getSize() < b.getSize();
		});
	
	for (int i = 0; i < 100; ++i) {
		cout << a[i] << endl;
	}



	//MySaveFileCode::Save_File("5����_2.cpp", "5����_2.txt");
	//MySaveFileCode::Save_File("String.h", "String_Class.txt");
	//MySaveFileCode::Save_File("String.cpp", "String_Class.txt");
}


