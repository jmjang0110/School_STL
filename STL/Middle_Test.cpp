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
//[Q] : ���� int 1000�� �� ���� ū ���� ã�� ȭ�鿡 ����϶�
//		���� ���� 1���� ������ �д� ���̴�.
//*/
//default_random_engine dre; // 5'000 byte �̴�.  
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
//* [Q] : ���� int 1000�� �� ���� ū ���� ã�� ȭ�鿡 ����϶�
//		���� ���� 1���� ������ �д� ���̴�.
//	[Q] : ���� int 1000 ���� �����Ͽ� ���� int õ���� �����϶�
//
//
//		Random ���� ���� int 1'000 ���� �����ϰ� ���� ȭ�鿡 ����Ѵ�.
//
//*/
//default_random_engine dre; // 5'000 byte �̴�.  
//
//
//// -------
//int main()
//// -------
//{
//	// uniform_int_distribution<int> uid{0, 9999} -> 0 ~ 9999 ������ ������ ���� ����� Ȯ���� �����ϰ� ����  
//	uniform_int_distribution<int> uid{ 0, 9999 }; // �ζ� ���� �� ���� �ڵ� 
//	//int MaxValue = INT_MIN;  // int �� ���� �� �ִ� �ּڰ� 
//	int MaxValue = numeric_limits<int>::min();
//
//	for (int i = 0; i < 1'000; ++i)
//	{
//		// int 0 ~ intMax ���� �� ������ ������ ���� ������. 
//		// ĭ ���缭 ��� �ʹٸ� ? -> format �Լ� 
//
//		int num = uid(dre);
//		// < �������� / ^ ���� 
//		//cout << format("{:8}", num);						// uniform �ϰ� �����Ѵ�. 
//		if (MaxValue < num)
//			MaxValue = num;
//
//		/*
//			���� ū ���� ã�� ���ؼ��� �������� �ʿ��ϴ�.
//			�������� ���� ���� ���� ������?
//
//		*/
//
//		// ���� �߿��� ���� : RAII : Resource Acquisition Is Initialization
//		// ����� ���ÿ� �ʱ�ȭ 
//		std::ofstream	OutFile{ "int õ��", std::ios::app };						// ������� ������ ���� ( app : ���ٿ� ���� ��� )
//		OutFile << format("{:8}", num);
//		if (i % 8 == 0)
//			OutFile << '\n';
//
//
//		// OutFIle.close() ���� �ڵ��� �ϸ� �ȵȴ�. 
//		// �ڵ����� �ڿ��� ������ ��ȯ�ȴ���. ( RAII�� ���ؼ�... ) 
//
//	}
//
//	cout << "�ִ� : " << MaxValue << endl;
//	save("STL.cpp");
//}
//
//#endif // STL
