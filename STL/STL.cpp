//#define STL
#ifdef STL
// --------------------------------------------------
//	2023 1 학기 STL 4월 03일 TUE 23 Tue 56 ( 5주 1)
// --------------------------------------------------
//	C++ 클래스 복습 - String 클래스를 만든다.
// 앞으로 String 클래스를 STL 컨테이너로 발전시킨다. 
// --------------------------------------------------

#include <iostream>
#include <array>
#include <algorithm>
#include <string>

#include "save.h"

using namespace std;


bool 관찰{ false };


class String {
private:
	size_t len{};
	char* p{}; // default nullptr 이다.  // unique_ptr<char> p 로 바꿔서 코딩하여 살려볼것 
	size_t id = ++sid;	// 객체 고유번호 

	static size_t sid;

public:
	friend ostream& operator<<(ostream& _os, const String& _str) {
		// return _os << _str.p  << endl; // str.p 하면 안찍힌다...
		for (int i = 0; i < _str.len; ++i) {
			_os << _str.p[i];
		}
		return _os;
	}
	//String() = default;
	String() {
		print("디폴트 생성");
	}
	~String() {
		//if( p != nullptr) // 전혀 필요가 없는 코드이다. 
		print("소멸자");
		delete[] p;
	}

	String(const String& other) : len(other.len) {
		p = new char[len];
		memcpy(p, other.p, len);
		print("복사생성");
	}

	// 복사생성자를 코딩했다면 복사할당 연산자도 반드시 코딩해야 한다.???
	String& operator=(const String& other) {
		if (this == &other)
			return *this;
		delete[] p;

		len = other.len;
		p = new char[len];
		memcpy(p, other.p, len);

		print("복사할당연산자");

		return *this;

	}


	String(const char* s) : len{ strlen(s) } {
		p = new char[len]; // 동적할당은 여기서 len 이 먼저될지 p 가 먼저 될지 : 이후에 쓰면 모름 
		memcpy(p, s, len);
		print("생성(char*)");

		// 꼭 delete 써야힘 
	}

	/*friend String& operator+(const String& _str1, const String& _str2) {
		int len = _str1.len + _str2.len;
		char* p = new char[len];
		for (int i = 0; i < _str1.len; ++i) {
			p[i] = _str1.p[i];
		}
		for (int i = _str1.len; i < len; ++i) {
			p[i] = _str2.p[i];
		}

		String str{p};
		delete[]p;
		return str;

	}*/


	String operator+(const String& rhs) const // right hand side 
	{
		String temp;
		temp.len = len + rhs.len;
		temp.p = new char[temp.len];

		memcpy(temp.p, p, len);
		memcpy(temp.p + len, rhs.p, rhs.len);
		return temp;
	}


	string getString() const {
		return string(p, len);
	}

	void print(const char* msg) {

		if (관찰) {
			cout << "[" << id << "] - " << msg << ", 개수:" << len
				<< ", 주소:" << (void*)p << endl; // 형변환 해야한다. 
		}
	}


};

size_t String::sid = { 0 };

// -------	
int main()
// -------
{
	/*
	
		** 그림 그리면서 복습해보기 ** 
		
		
	*/

	array<String, 5> news{
		"유재석이", "목숨", "걸어가지고", "만든", "걸그룹.."
	};

	관찰 = true;

	// 이렇게 자면 복사되니까 쓸데없는짓을 많이한다...
	for (String s : news) {
		cout << s << endl;

	}
	// & 를 써야한다. 
	for (String& s : news) {
		cout << s << endl;

	}

	// 꼭 레퍼런스를 넣자 .... 복사 소멸 엄청함 
	sort(news.begin(), news.end(), [](const String& a,const String& b) {
		return a.getString() < b.getString(); // 오름차순 
		});


	관찰 = false;


	save("STL.cpp");

}

#endif // STL
