

// -------------------------------------------------
// save.h : �� �б� ���� �����ϴ� �Լ� 
// -------------------------------------------------

#include <string>
#include <fstream>
#include <chrono>
#include <iostream>


#include "save.h"

void save(const std::string& fileName)
{
	std::ifstream InputFile{ fileName }; // uniform �ʱ�ȭ InputFile.close() �� �ʿ䰡 ����.  RAII ����� �����ִ�. �ڿ��� �ʱ�ȭ �԰� ���ÿ� 
	std::ofstream outputFile{ "2023 1�б� STL ��23ȭ56 ��������.txt", std::ios::app }; // Ȯ���� ��� ���µ� ���� ����.  ( append  - ios::app -> ��� ����� ������ ���� �߰��ȴ�. )
	outputFile << '\n' << '\n' << '\n'; // ���� ���� ���� 

	auto now = std::chrono::system_clock::now();	// ���� �ð�  ���� Time Point �� ��´�. 
	std::cout << now << '\n';						// C++ 17 ���� �����ϴ� ����̹Ƿ� ���ǥ���� �ֽ��� �ǹٲپ�� ����. - ETC

	auto utc = std::chrono::system_clock::to_time_t(now); // 06:24 // ���� Ÿ�ӽð��� utc �� �ٲ۴�. UTC �ð��� �Ǻ���
	auto lt = std::localtime(&utc); // �ѱ��ð��� ���� �� �ִ�. -�����ð��� �Ǻ��� 

	/*
	

		_s �� �Ἥ unsafe ��� �ȳ��� �ϴµ� �������� �̷��� ���� �����Ŵ�.

		�ٽ��ѹ� ���������� �̷� �ڵ� ������ �����Ű� imbue �ڵ� ������ ����.
		�ٵ� �˾ƴ� �־���
		�����ϰ� ���� �� ������ �����ؾ��Ѵ�.

		���� ������ �����س��� �ڵ����� �ϰ� ���� ���ϴ� �ڵ��� �� ���Ŀ� �ǵ������´�,
		�޸� Ȯ�� ������ �ϰ� ������.
		���󺹱� ��Ų��.

		imbue �� ���� ���� �� , �ѱ��� ���ڸ����� ��µ� �׷��� ��� ���� �� �ѱ���� �ٲٰ� ��´�.


	*/
	auto old = outputFile.imbue(std::locale("ko_KR")); // ���ѹα����� ��������
	outputFile << "===============================================" << '\n';
	outputFile << fileName << std::put_time(lt, "����ð� : %x %A %X") << '\n'; // �ѱ� �ð����� ���Ͽ� ��� 
	outputFile << "===============================================" << '\n';
	outputFile << '\n';



	outputFile.imbue(old);							// ���� �������� ���� 


	std::vector<char> v{ std::istreambuf_iterator<char> { InputFile }, {} /*����ִ� �߰�ȣ : EOF */ }; /* v �� �����͸� ������ */
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>{ outputFile /* ȭ�鿡 ����϶� ( std::cout*/}/* [ ������ ] - ���� �����϶� ,,, */); // concept range 


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