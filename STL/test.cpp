//#define STL_TEST
#ifdef STL_TEST

#include <iostream>	
#include <fstream>
#include <string>
#include <chrono>


void SaveFile(const std::string& ReadFileName, const std::string& WriteFileName)
{
	std::ifstream	InFile	{ ReadFileName };										// �б� ���� ������ ����.
	std::ofstream	OutFile	{ WriteFileName, std::ios::app};						// ������� ������ ���� ( app : ���ٿ� ���� ��� )

	std::vector<char> vWords{ std::istreambuf_iterator<char> { InFile}, {} };		// InFile �� ���� �ƽ�Ű �ڵ带 �д´�.
	std::copy(vWords.begin(), vWords.end(), std::ostream_iterator<char> {OutFile}); // vector �� ó������ ������ OutFile �� ���� 

	std::cout << ReadFileName << " -> " << WriteFileName << " Save Success " << std::endl;
}

void ShowTime()
{
	using namespace std::chrono;
	auto Present_Time = std::chrono::system_clock::now();
	std::cout << Present_Time << std::endl;

}
int main(void)
{
	
	ShowTime();
	SaveFile("test.cpp", "Test.txt");

}

#endif // STL_TEST

