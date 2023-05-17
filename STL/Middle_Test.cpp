//#define MIDDLE_TEST
//#ifdef MIDDLE_TEST
//
//#include <iostream>
//#include <random>
//#include <format>
//#include <array>
//#include <numeric>
//#include <fstream>
//
//using namespace std;
//
//#include "Tool.h"
//#include "Dog.h"
//
///*
//[Q] : 램던 int 1000개 중 가장 큰 값을 찾아 화면에 출력하라
//		시험 문제 1번은 파일을 읽는 것이다.
//*/
//default_random_engine dre; // 5'000 byte 이다.  
//
//
//int main(void)
//{
//	Tool t;
//	/*std::array<Dog, 1'000> dogs;
//	std::ofstream outFile{ "DOG1000_TEXT" };
//	outFile.write((char*)&dogs, dogs.size() * sizeof(Dog));*/
//
//	array<int, 200'000'000 / sizeof(int)> a;
//
//
//}
//
//
//#endif // MIDDLE_TEST
//
//
////#define STL
//#ifdef STL
//
//#include <iostream>
//#include "save.h"
//#include <random>
//#include <format>
//#include <limits>
//#include <fstream>
//
//
//using namespace std;
///*
//* [Q] : 램던 int 1000개 중 가장 큰 값을 찾아 화면에 출력하라
//		시험 문제 1번은 파일을 읽는 것이다.
//	[Q] : 램던 int 1000 개를 생성하여 파일 int 천개에 저장하라
//
//
//		Random 값을 갖는 int 1'000 개를 생성하고 값을 화면에 출력한다.
//
//*/
//default_random_engine dre; // 5'000 byte 이다.  
//
//
//// -------
//int main()
//// -------
//{
//	// uniform_int_distribution<int> uid{0, 9999} -> 0 ~ 9999 사이의 랜덤한 값을 만들고 확률은 일정하게 해줘  
//	uniform_int_distribution<int> uid{ 0, 9999 }; // 로또 뽑을 때 쓰는 코드 
//	//int MaxValue = INT_MIN;  // int 가 가질 수 있는 최솟값 
//	int MaxValue = numeric_limits<int>::min();
//
//	for (int i = 0; i < 1'000; ++i)
//	{
//		// int 0 ~ intMax 까지 의 숫자중 랜덤한 값이 찍힌다. 
//		// 칸 맞춰서 찍고 싶다면 ? -> format 함수 
//
//		int num = uid(dre);
//		// < 왼쪽으로 / ^ 위로 
//		//cout << format("{:8}", num);						// uniform 하게 가공한다. 
//		if (MaxValue < num)
//			MaxValue = num;
//
//		/*
//			가장 큰 값을 찾기 위해서는 기준점이 필요하다.
//			기준점을 뭘로 잡을 수가 있을까?
//
//		*/
//
//		// 가장 중요한 개념 : RAII : Resource Acquisition Is Initialization
//		// 만듦과 동시에 초기화 
//		std::ofstream	OutFile{ "int 천개", std::ios::app };						// 쓰기모드로 파일을 연다 ( app : 덧붙여 쓰기 모드 )
//		OutFile << format("{:8}", num);
//		if (i % 8 == 0)
//			OutFile << '\n';
//
//
//		// OutFIle.close() 같은 코딩은 하면 안된다. 
//		// 자동으로 자원이 닫히고 반환된더ㅏ. ( RAII에 의해서... ) 
//
//	}
//
//	cout << "최댓값 : " << MaxValue << endl;
//	save("STL.cpp");
//}
//
//#endif // STL
