
//#define ELEVENTH_SECOND
#ifdef	ELEVENTH_SECOND
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <map>
#include <list>



#include "../save.h"
#include "../String.h"


using namespace std;
extern bool ����;

int main()
{
	// ����ȸ��� ����۵� 
	// ���?
	// ������ �� ���� �� ������?

	map<String, list<String>> game{
		{"�� ���", {"�����縷", "���� �縷", "������"}},
		{"���ٵ�", {"������ ����", "���� ������", "������ ī��", "��Ÿ����"}}
	};

	for (const auto& [ȸ��, ���ӵ�] : game) {
		cout << ȸ�� << " - ";
		for (const String& ���� : ���ӵ�) {
			cout << ���� << " ";
		}
		cout << endl;
	}

	cout << "���� ���� �� - " << game.size() << endl;
	MySaveFileCode::Save_File("11���� �ڷ�/11����_2.cpp", "11���� �ڷ�/map ����.txt");
	MySaveFileCode::Save_File_Auto(11, 2);
}

#endif
