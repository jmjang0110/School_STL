
#define TWELVE
#ifdef	TWELVE
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <map>
#include <list>
#include <fstream>

#include <ranges>
#include <utility>
#include <random>

#include "../save.h"
#include "../String.h"
using namespace std;
extern bool ����;

default_random_engine dre;
//uniform_int_distribution uid{ 1, 10'0000 };
normal_distribution uid{/*��հ�*/0.0f , /*�л갪(������ ����)*/0.05f }; /// ���Ժ��� ����� - ���Ժ��� ��������

/// ���Ժ��� ���ӿ� ���� ���δ�. 
/// ������ ��� Ȯ�� ������....
/// �����ð����� unordered_map ���� ������. 

int main()
{
	///	[����] - uniform ������ ��¥ unfirom ���� ������ ���� ����϶�.
	/// ������ 10 ����ؼ� ������ ���� ����϶� 

	map< int, int > iimap; 

	for (int i = 0; i < 1'000'000; ++i) {
		int num = uid(dre) * 50'000 + 50'000 ; // -1 ~ 1

		if( 0 < num && num < 100'000)
			iimap[num / 2'000]++;
	}

	for (auto [����, ����] : iimap) {
		cout << ���� << endl;
	}


	MySaveFileCode::Save_File("12���� �ڷ�/12����_1.cpp", "12���� �ڷ�/����2 unfirom ������ ��¥ uniform ���� �������� - ������_ normal_distribution�̿�.txt");
	MySaveFileCode::Save_File_Auto(12, 1);
}

#endif
