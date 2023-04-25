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
	cout << "int�� �� �� ������? : ";
	int num;
	cin >> num;

	//array<int, num > a; // ����� �־�� ��! ( �����Ϸ��� ����� �ٲ㳪���� ���� �� ũ�⸦ ������ �� �־���� ) - ������ Ÿ�� �ܽ�źƮ
	
	//int* p = new int[num]; // default �����ڸ� �θ��� ? ���� �ʱ�ȭ �ȵ� �����Ⱚ �� 
	
	int* p = new int[num] {};

	for (int i = 0; i < num; ++i){
		cout << p[i] << " ";
	}



	//cout << "�հ�� " << sum << " �Դϴ�." << endl;
	*/



	/*

	[����] "STL.cpp"�� �о� �ҹ��ڴ� �빮�ڷ� ��ȯ�Ͽ� 
	"STL�빮��.cpp" �� �����϶�. 

	*
	* ���� �ذ� - ������ 
	* 



// -------	
	int main()
		// -------
	{
		std::ifstream in{ "STL.cpp" }; 	// 1. ������ �б� ���� ���� ( STL.cpp ) 
		std::ofstream out{ "�ҽ��빮��.cpp" };	// 2. �ҽ��빮��.cpp�� ������� ����.

		//transform(�̰�, ���ɷ�, �̷��������);
		transform(
			std::istreambuf_iterator<char>{in}
		, {}
			, std::ostreambuf_iterator<char>{cout}/* lambda ( Collable �Լ� ? )
		, [](char c) {
			if (isdigit(c)) c = '*';
			return c;
		}
		);

	*/
}

int Tool::GetNumForMemory_MB(int MB, int _sizeofMemory_One)
{

	// ~MB �޸𸮸� ��� ���� ��� �����Ͱ� �ʿ�����
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
	std::uniform_int_distribution<int> uidNum{ min, max }; // �ζ� ���� �� ���� �ڵ� 	
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
