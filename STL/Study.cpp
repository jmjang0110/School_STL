//#define STL_STUDY
#ifdef	STL_STUDY


#include <iostream>
#include <array>


using namespace std;
int main(void)
{
	// Stack  �� 1MB �� �Ѿ�� �ٿ� ( ������ ������ ���� ���� �ʴ´�. - ���� �����÷ο� ) 
	///array<int, 200'000'000 / sizeof(int)> a{}; // 200 MB
	array<int, (1 * 1000 * 1000) / sizeof(int) > a{};
	cout << sizeof(a)/1'000'000<< "MB " << endl << endl;;


	for (int i = 0; i < 10; ++i) {
		cout << a[i] << endl;

	}

	
	return 0;

}


// --------------------------------------------------
//	2023 1 �б� STL 3�� 20�� Mon 23 Tue 56 ( 1�� 1)
// --------------------------------------------------
// STACK �� �Ѱ� : 1MB �� default( �����Ϸ��� �ڵ� �������� �ʴ� �� ���� ) - �ƹ��� ��� ����.   
// �� ū ������ ��� : DATA �� Free Store ( HEAP )
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
			Q :  ����ڰ� �Է��� ���ڸ�ŭ int �� ������ �޸𸮸� �����϶�.
			���� 1 ���� �����ϴ� ������ ä��������.
			�հ踦 ȭ�鿡 ����϶�.

			�� ������ �ݺ��϶�.

				��) 10 �� �Է��Ͽ���.
					-> int 10���� �� ������ Ȯ���ϰ� -> 1 2 3 4 5 6 7 ... 10
					�հ�� 55 �Դϴ� ��� ȭ�鿡 ���
	*/

	/*
		** ���� ���� § �ڵ� **

		cout << "int�� �� �� ������? : ";
		int num;
		cin >> num;

		int* p = new int[num];
		int sum = 0;

		for (int i = 1; i < num; ++i){
			p[i - 1] = i;
			cout << i << " ";
			sum += i;

		}
		cout << "�հ�� " << sum << " �Դϴ�." << endl;

	*/

	/*

			** ������ �ڵ�

	*/

	int cnt{};


	while (true) {

		cout << "int�� �� �� ������? : ";
		//int num;


		//cin >> num;

		//array<int, num > a; // ����� �־�� ��! ( �����Ϸ��� ����� �ٲ㳪���� ���� �� ũ�⸦ ������ �� �־���� ) - ������ Ÿ�� �ܽ�źƮ

		//int* p = new int[num]; // default �����ڸ� �θ��� ? ���� �ʱ�ȭ �ȵ� �����Ⱚ �� 
		//int* p = new int[num] {};
		//for (int i = 0; i < num; ++i){
		//	cout << p[i] << " ";
		//}

		int num{ 200'000'000 }; // 800 MB
		int* p = new int[num]; // ����� ���� �� ������ �����Ҵ��� �̷��� �ϴ� �� �ۿ� ����. 

		iota(p, p + num, 1);

		long long sum{}; // 8 ����Ʈ�ε� ǥ�ؿ��� 4����Ʈ �̻����� �Ǿ��ֵ�. 
		for (int i = 0; i < num; ++i) {
			sum += p[i];
		}

		cout << p[199'999'999] << endl;


		//cout << " 1 ���� " << num << " ���� �հ� : " << sum << endl;
		cout << ++cnt << " �� ���� " << endl;

		delete[] p;

		/*
		 delete ������ �ξ� ��������.
			�� �׷���?

			delete ���ϸ� heap �޸𸮰� ���Ű�
			heap �޸𸮸� �ϵ��ũ�� �ű�� �� ä���. �׷��� ��������.

		*/

	}

	/*
		�뷮�� ���� ġ�� ��ǻ�Ͱ� �ʾ����� ��������.
		�ֱ׷���?

	*/



	//cout << "�հ�� " << sum << " �Դϴ�." << endl;



	save("STL.cpp");

}

// STL




/*
	array<int, 260'000> a; // stack �� 1MB�� ũ�⸦ �Ѵ´�. ( �迭�� ���� �޸� )
	iota(a.begin(), a.end(), 1); // �迭������ ���� ���� ���ÿ����÷ο�� ���α׷��� �״´�.

	for (int num : a |	# �ڷᱸ������ �ѹ��� �ϳ��� �����͸� ������ : �����Ϸ��� for(auto p = a.begin(); p != a.end(); ++p) �� �����Ѵ�.
						# �̷��� �����ϴ� ���� syntatic sugar �̶�� �Ѵ�.
						# for( int num : a )
			views::drop(a.size() - 100)) // 259900 ���� ����������?
		cout << format("{:20}", num);




*/

#endif
	


