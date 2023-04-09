//#define STL_TEST
#ifdef STL_TEST

#include <iostream>	
#include <fstream>
#include <string>
#include <chrono>


void SaveFile(const std::string& ReadFileName, const std::string& WriteFileName)
{
	std::ifstream	InFile	{ ReadFileName };										// 읽기 모드로 파일을 연다.
	std::ofstream	OutFile	{ WriteFileName, std::ios::app};						// 쓰기모드로 파일을 연다 ( app : 덧붙여 쓰기 모드 )

	std::vector<char> vWords{ std::istreambuf_iterator<char> { InFile}, {} };		// InFile 로 부터 아스키 코드를 읽는다.
	std::copy(vWords.begin(), vWords.end(), std::ostream_iterator<char> {OutFile}); // vector 의 처음부터 끝까지 OutFile 에 저장 

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

