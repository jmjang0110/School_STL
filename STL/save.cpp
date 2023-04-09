

// -------------------------------------------------
// save.h : 한 학기 강의 저장하는 함수 
// -------------------------------------------------

#include <string>
#include <fstream>
#include <chrono>
#include <iostream>


#include "save.h"

void save(const std::string& fileName)
{
	std::ifstream InputFile{ fileName }; // uniform 초기화 InputFile.close() 할 필요가 없다.  RAII 개념과 엮여있다. 자원을 초기화 함과 동시에 
	std::ofstream outputFile{ "2023 1학기 STL 월23화56 강의저장.txt", std::ios::app }; // 확장자 없어도 여는데 문제 없다.  ( append  - ios::app -> 모든 출력은 파일의 끝에 추가된다. )
	outputFile << '\n' << '\n' << '\n'; // 세줄 떼고 시작 

	auto now = std::chrono::system_clock::now();	// 현재 시간  현재 Time Point 를 얻는다. 
	std::cout << now << '\n';						// C++ 17 에서 제공하는 기능이므로 언어표준을 최신을 ㅗ바꾸어야 힌다. - ETC

	auto utc = std::chrono::system_clock::to_time_t(now); // 06:24 // 현재 타임시간을 utc 로 바꾼다. UTC 시간을 ㅗ변경
	auto lt = std::localtime(&utc); // 한국시간을 찍을 수 있다. -지역시간을 ㅗ변경 

	/*
	

		_s 를 써서 unsafe 경고 안나게 하는데 교슈님은 이렇게 하지 않으신다.

		다시한번 강조하지만 이런 코딩 할일은 없을거고 imbue 코딩 할일이 없다.
		근데 알아는 둬야해
		변경하고서 터질 수 있으니 복구해야한다.

		원래 세팅을 저장해놓는 코딩ㅇ을 하고 내가 원하는 코딩을 한 이후에 되돌려놓는다,
		메모리 확보 릴리즈 하고 끝낸다.
		원상복구 시킨다.

		imbue 를 숫자 찍을 때 , 한국은 네자리마다 찍는데 그렇게 찍고 싶을 때 한구긍로 바꾸고 찍는다.


	*/
	auto old = outputFile.imbue(std::locale("ko_KR")); // 대한민국으로 지역변경
	outputFile << "===============================================" << '\n';
	outputFile << fileName << std::put_time(lt, "저장시간 : %x %A %X") << '\n'; // 한국 시간으로 파일에 출력 
	outputFile << "===============================================" << '\n';
	outputFile << '\n';



	outputFile.imbue(old);							// 원래 지역으로 변경 


	std::vector<char> v{ std::istreambuf_iterator<char> { InputFile }, {} /*비어있는 중괄호 : EOF */ }; /* v 가 데이터를 다읽음 */
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{ outputFile /* 화면에 출력하라 ( std::cout*/}/* [ 목적지 ] - 어디로 복사하라 ,,, */); // concept range 


}



namespace MySaveFileCode {
	void Save_File(const std::string& InFileName, const std::string& OutFileName) {

		std::ifstream InFile{ InFileName };
		std::ofstream OutFile{ OutFileName, std::ios::app };

		std::vector<char> v{ std::istreambuf_iterator<char> {InFile} , {} };
		std::copy(v.begin(), v.end(), std::ostream_iterator<char> {OutFile});


	}
}






//  EOF