//#define STL_STUDY
#ifdef	STL_STUDY


#include <iostream>
#include <array>


using namespace std;
int main(void)
{
	// Stack  은 1MB 를 넘어가면 다운 ( 실행은 되지만 경고는 뜨지 않는다. - 스택 오버플로우 ) 
	///array<int, 200'000'000 / sizeof(int)> a{}; // 200 MB
	array<int, (1 * 1000 * 1000) / sizeof(int) > a{};
	cout << sizeof(a)/1'000'000<< "MB " << endl << endl;;


	for (int i = 0; i < 10; ++i) {
		cout << a[i] << endl;

	}

	
	return 0;

}


// --------------------------------------------------
//	2023 1 학기 STL 3월 20일 Mon 23 Tue 56 ( 1주 1)
// --------------------------------------------------
// STACK 의 한계 : 1MB 가 default( 컴파일러가 코드 생성하지 않는 것 주의 ) - 아무런 경고가 없다.   
// 더 큰 데이터 사용 : DATA 와 Free Store ( HEAP )
// --------------------------------------------------

#include <iostream>
#include <array>
#include<ranges>
#include <numeric>


#include "save.h"
using namespace std;


// -------	
int main()
// -------
{

	/*
			Q :  사용자가 입력한 숫자만큼 int 를 저장할 메모리를 생성하라.
			값을 1 부터 시작하는 정수로 채워나가라.
			합계를 화면에 출력하라.

			이 과정을 반복하라.

				예) 10 을 입력하였다.
					-> int 10개가 들어갈 공간을 확보하고 -> 1 2 3 4 5 6 7 ... 10
					합계는 55 입니다 라고 화면에 출력
	*/

	/*
		** 내가 직접 짠 코드 **

		cout << "int를 몇 개 만들까요? : ";
		int num;
		cin >> num;

		int* p = new int[num];
		int sum = 0;

		for (int i = 1; i < num; ++i){
			p[i - 1] = i;
			cout << i << " ";
			sum += i;

		}
		cout << "합계는 " << sum << " 입니다." << endl;

	*/

	/*

			** 교수님 코드

	*/

	int cnt{};


	while (true) {

		cout << "int를 몇 개 만들까요? : ";
		//int num;


		//cin >> num;

		//array<int, num > a; // 상수로 넣어야 해! ( 컴파일러가 기계어로 바꿔나가는 동안 이 크기를 결정할 수 있어야해 ) - 컴파일 타임 콘스탄트

		//int* p = new int[num]; // default 생성자를 부르나 ? ㄴㄴ 초기화 안됨 쓰레기값 들어감 
		//int* p = new int[num] {};
		//for (int i = 0; i < num; ++i){
		//	cout << p[i] << " ";
		//}

		int num{ 200'000'000 }; // 800 MB
		int* p = new int[num]; // 상수를 넣을 수 없으니 동적할당은 이렇게 하는 수 밖에 없다. 

		iota(p, p + num, 1);

		long long sum{}; // 8 바이트인데 표준에는 4바이트 이상으로 되어있따. 
		for (int i = 0; i < num; ++i) {
			sum += p[i];
		}

		cout << p[199'999'999] << endl;


		//cout << " 1 부터 " << num << " 까지 합계 : " << sum << endl;
		cout << ++cnt << " 번 실행 " << endl;

		delete[] p;

		/*
		 delete 넣으면 훨씬 빨라진다.
			왜 그럴까?

			delete 안하면 heap 메모리가 찰거고
			heap 메모리를 하드디스크로 옮기고 더 채운다. 그래서 느려진다.

		*/

	}

	/*
		용량을 많이 치면 컴퓨터가 늦어지고 느려진다.
		왜그럴끼?

	*/



	//cout << "합계는 " << sum << " 입니다." << endl;



	save("STL.cpp");

}

// STL




/*
	array<int, 260'000> a; // stack 의 1MB의 크기를 넘는다. ( 배열은 직렬 메모리 )
	iota(a.begin(), a.end(), 1); // 배열공간에 쓰는 순간 스택오버플로우로 프로그램이 죽는다.

	for (int num : a |	# 자료구조에서 한번에 하나씩 데이터를 꺼내라 : 컴파일러가 for(auto p = a.begin(); p != a.end(); ++p) 로 번역한다.
						# 이렇게 번역하는 것을 syntatic sugar 이라고 한다.
						# for( int num : a )
			views::drop(a.size() - 100)) // 259900 개를 날려버려랴?
		cout << format("{:20}", num);




*/

#endif
	


