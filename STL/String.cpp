
#include <iostream>
#include <string>
#include "String.h"

size_t String::sid = { 0 };
bool 관찰 = { false };


// 디폴트 생성자   
String::String()
{
	print("디폴트 생성");
}

// 생성자 
String::String(const char* s) : len{ strlen(s) }
{
	p = new char[len]; // 동적할당은 여기서 len 이 먼저될지 p 가 먼저 될지 : 이후에 쓰면 모름 
	memcpy(p, s, len);
	print("생성(char*)");
}

// 소멸자  
String::~String()
{
	//if( p != nullptr) // 전혀 필요가 없는 코드이다. 
	print("소멸자");
	delete[] p;
}

// 복사생성자
String::String(const String& other) : len(other.len)
{
	p = new char[len];
	memcpy(p, other.p, len);
	print("복사생성");
}

// 복사할당 연산자
String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;
	delete[] p;

	len = other.len;
	p = new char[len];
	memcpy(p, other.p, len);

	print("복사할당연산자");

	return *this;

}

// 이동생성자  
String::String(String&& other)
{		// && - r_Value Reference  
	len = other.len;
	p = other.p;

	// 정리 ( Other 를 정리한다 ) 
	// Other 를 정리하지 않으면 프로그램 사망  
	other.len = 0;
	other.p = nullptr; // 이거 안해주면 Dangleing Pointer 가 생겨서 프로그램이 죽는다. 


	print("이동생성자");
}

// 이동 할당 연산자 
String& String::operator=(String&& other)
{
	if (this == &other)
		return *this;

	// 확보한 자원을 해제  
	delete[] p;


	// Other 의 자원을 가져온다. 
	len = other.len;
	p = other.p;


	// Other 를 초기화한다.
	other.len = 0;
	other.p = nullptr;

	print("이동할당연산자");

	return *this;
}

// 2023.04.04 추가 
size_t String::getSize() const
{
	return len;
}


String String::operator+(const String& rhs) const // right hand side 
{
	String temp;
	temp.len = len + rhs.len;
	temp.p = new char[temp.len];

	memcpy(temp.p, p, len);
	memcpy(temp.p + len, rhs.p, rhs.len);
	return temp;
}

// gettor / settor
std::string String::getString() const
{
	return std::string(p, len);
}

// 그 외 함수  
void String::print(const char* msg)
{

	if (관찰) {
		std::cout << "[" << id << "] - " << msg << ", 개수:" << len
			<< ", 주소:" << (void*)p << std::endl; // 형변환 해야한다. 
	}
}
