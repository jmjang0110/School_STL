#include "Tool.h"
#include <limits>
#include <numeric>
#include <fstream>
#include <array>
#include <format>


std::default_random_engine Tool::dre;



void Tool::ShowDrop()
{
	//for (int num : a |
	//	views::drop(a.size() - 100))
	//	cout << format("{:20}", num);



	/*
	cout << "int를 몇 개 만들까요? : ";
	int num;
	cin >> num;

	//array<int, num > a; // 상수로 넣어야 해! ( 컴파일러가 기계어로 바꿔나가는 동안 이 크기를 결정할 수 있어야해 ) - 컴파일 타임 콘스탄트
	
	//int* p = new int[num]; // default 생성자를 부르나 ? ㄴㄴ 초기화 안됨 쓰레기값 들어감 
	
	int* p = new int[num] {};

	for (int i = 0; i < num; ++i){
		cout << p[i] << " ";
	}



	//cout << "합계는 " << sum << " 입니다." << endl;
	*/



	/*

	[문제] "STL.cpp"를 읽어 소문자는 대문자로 변환하여 
	"STL대문자.cpp" 에 저장하라. 

	*
	* 문제 해결 - 교수님 
	* 



// -------	
	int main()
		// -------
	{
		std::ifstream in{ "STL.cpp" }; 	// 1. 파일을 읽기 모드로 연다 ( STL.cpp ) 
		std::ofstream out{ "소스대문자.cpp" };	// 2. 소스대문자.cpp를 쓰기모드로 연다.

		//transform(이걸, 저걸로, 이런방식으로);
		transform(
			std::istreambuf_iterator<char>{in}
		, {}
			, std::ostreambuf_iterator<char>{cout}/* lambda ( Collable 함수 ? )
		, [](char c) {
			if (isdigit(c)) c = '*';
			return c;
		}
		);

	*/
}

int Tool::GetNumForMemory_MB(int MB, int _sizeofMemory_One)
{

	// ~MB 메모리를 잡기 위해 몇개의 데이터가 필요한지
	int SizeOfMemory = _sizeofMemory_One;
	int MegaByte     = MB;
	 // 200'000'000 / sizeof(int) -> 200MB
	int Num = MegaByte * 1'000 * 1'000;
	return Num / SizeOfMemory;
}

Tool::Tool()
{

}

Tool::~Tool()
{

}


int Tool::GetRandomNum(int min, int max)
{
	std::uniform_int_distribution<int> uidNum{ min, max }; // 로또 뽑을 때 쓰는 코드 	
	return uidNum(dre);

}

char Tool::GetRandomChar(char start, char end)
{
	std::uniform_int_distribution<int> uidChar{ start, end };
	return uidChar(dre);

}

int Tool::GetMIN_INT()
{
	return std::numeric_limits<int>::min();;
}

int Tool::GetMAX_INT()
{
	return std::numeric_limits<int>::max();;
}

void Tool::StoreIncreasingValues_iota()
{

	// 1,2,3,4,5,...6..
	std::array<int, 1'000> a;
	std::iota(a.begin(), a.end(), 1);
}

void Tool::Save_to_File(const std::string& FileName, FILE_MODE _eMode)
{
	switch (_eMode)
	{
	case FILE_MODE::TEXT:

		break;
	case FILE_MODE::BINARY:

		break;
	}


}


void Tool::SaveFIle_1000_INT(const std::string& filename)
{
	std::ofstream outFile{ filename };
	

	std::array<int, 1'000> Arr{};
	std::iota(Arr.begin(), Arr.end(), 1);

	for(int i = 0 ; i < Arr.size(); ++i)
	{
		int Num = Arr[i];
		//outFile << std::format("{:8}", Num);
		outFile << Num;
		//if ((i + 1) % 8 == 0)
		{
			outFile << '\n';
		}
	}

	std::cout << "File Store Success" << std::endl;


}

void Tool::LoadFIle_1000_INT(const std::string& filename)
{
	std::ifstream inFile{ filename };

	std::vector<int> vecData{};

	int num;
	while (inFile >> num) {
		vecData.push_back(num);
	}

	for (int i = 0; i < vecData.size(); ++i) {
		std::cout << vecData[i] << '\n';
	}
	int  k = 0;

}
