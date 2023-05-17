
//#define ELEVENTH_FIRST
#ifdef	ELEVENTH_FIRST
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>


#include "../save.h"
#include "../String.h"

using namespace std;
extern bool ����;
/*
	1. String �� ,operator<�� ���� 
	2. less<String> �� ( Specialization )
	3. ȣ�Ⱑ��Ÿ���� ����
*/

template<>
// �����Ϸ��� Ȯ������ ���ϵ��� Specialization ���ش�. 
struct less <String> {
	// operator() : �Լ� ȣ�� ������ 
	bool operator()( const String& a, const String& b) const {
		// ���� �� ����
		return a.size() < b.size();
	}
};

// �����Ϸ��� Ȯ������ ���ϵ��� Specialization ���ش�. 
//template<>
//struct �ҹ��ڿ켱<String>{
//	// operator() : �Լ� ȣ�� ������ 
//	bool operator()(const String& a, const String& b) const {
//		// �ҹ��ڿ켱 - ù���� ����
//		// �Ҽ� �Ҵ� ��� ���
//		if (isupper(*(a.begin())))
//		{
//			if(islower( *(b.begin())) )
//				return true;
//		}
//		return false;
//
//	}
//
//};
int main()
{
	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };
	set<String> v{ std::istream_iterator<String>{in}, {} }; 
	cout << "���� ���� :" << v.size() << endl;

	���� = true;
	String temp = { "f" };
	���� = false;

	while (true) {
		cout << "���� �Է�:" ;
		char c;
		cin >> c;
		cout << c << "�� ���Ե� STr �Դϴ�.";
		for (const String& s : v) {
			std::string str = s.getString();
			if (str.contains(c))
				cout << s << ' ' << endl;

		}


	}

	MySaveFileCode::Save_File("11���� �ڷ�/11����_1.cpp", "11���� �ڷ�/�̻��ѳ����� �ٸ��������� �ǽ�.txt");
	MySaveFileCode::Save_File_Auto(11, 1);
}

#endif
