
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
extern bool 관찰;

default_random_engine dre;
//uniform_int_distribution uid{ 1, 10'0000 };
normal_distribution uid{/*평균값*/0.0f , /*분산값(퍼지는 정도)*/0.05f }; /// 정규분포 만들기 - 정규분포 공부하자

/// 정규분포 게임에 많이 쓰인다. 
/// 아이템 드랍 확률 같은거....
/// 다음시간에는 unordered_map 으로 나간다. 

int main()
{
	///	[문제] - uniform 분포가 진짜 unfirom 한지 개수를 세서 출력하라.
	/// 구간을 10 등분해서 개수를 세서 출력하라 

	map< int, int > iimap; 

	for (int i = 0; i < 1'000'000; ++i) {
		int num = uid(dre) * 50'000 + 50'000 ; // -1 ~ 1

		if( 0 < num && num < 100'000)
			iimap[num / 2'000]++;
	}

	for (auto [구간, 개수] : iimap) {
		cout << 개수 << endl;
	}


	MySaveFileCode::Save_File("12주차 자료/12주차_1.cpp", "12주차 자료/문제2 unfirom 분포가 진짜 uniform 한지 개수세기 - 교수님_ normal_distribution이용.txt");
	MySaveFileCode::Save_File_Auto(12, 1);
}

#endif
