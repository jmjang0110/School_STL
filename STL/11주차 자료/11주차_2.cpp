
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
extern bool 관찰;

int main()
{
	// 게임회사와 출시작들 
	// 출력?
	// 게임을 더 넣을 수 있을까?

	map<String, list<String>> game{
		{"펄 어비스", {"검은사막", "붉은 사막", "도깨비"}},
		{"닌텐도", {"젤다의 전설", "슈퍼 마리오", "마리오 카드", "스타폭스"}}
	};

	for (const auto& [회사, 게임들] : game) {
		cout << 회사 << " - ";
		for (const String& 게임 : 게임들) {
			cout << 게임 << " ";
		}
		cout << endl;
	}

	cout << "맵의 원소 수 - " << game.size() << endl;
	MySaveFileCode::Save_File("11주차 자료/11주차_2.cpp", "11주차 자료/map 시작.txt");
	MySaveFileCode::Save_File_Auto(11, 2);
}

#endif
