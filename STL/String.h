#pragma once

/*
	2023_04_03 
*/

/*
	class String {

		public:
		 === SPECIAL FUNCTION ===
		 / 프로그래머가 작성하지 않으면 컴파일러가 알아서 만들어주는 특징 /
			* 생성자		,	소멸자
			* 복사생성자	,	복사할당연산자
			* 이동생성자 ,	이동할당연산자
		 ========================
			* 연산자 오버로딩
			* gettor  /  settor
			* 그 외 interface 함수

	}

*/
class ostream;
class string;

class String {
private:
	size_t len{};		// 확보한 자원의 바이트 수  
	char* p{};			// 확보한 자원의 주소  
	size_t id = ++sid;	// 객체 고유번호 

	static size_t sid;	// 클래스 스태틱

public:


	// 디폴트 생성자   
	String();

	// 생성자 
	String(const char* s);

	// 소멸자  
	~String();

	// 복사생성자
	String(const String& other);

	// 복사할당 연산자
	String& operator=(const String& other);

	// 이동생성자  
	String(String&& other);
	// 이동 할당 연산자 
	String& operator=(String&& other);



	friend std::ostream& operator<<(std::ostream& _os, const String& _str) {
		// return _os << _str.p  << endl; // str.p 하면 안찍힌다...
		for (int i = 0; i < _str.len; ++i) {
			_os << _str.p[i];
		}
		return _os;
	}


	String operator+(const String& rhs) const; // right hand side 


	// gettor / settor
	std::string getString() const;

	// 그 외 함수  
	void print(const char* msg);

	// 2023.04.04 추가
	friend std::istream& operator>>(istream& is, String& s) {
		std::string str;
		is >> str;
		delete[] s.p;
		s.len = str.size();
		s.p = new char[s.len];
		memcpy(s.p, str.data(), s.len);
		return is;

	}

	size_t getSize() const;

	/*friend std::ifstream& operator>>(std::ifstream& os, const String& str) {
		return os >> str.getString();
	}*/



};

