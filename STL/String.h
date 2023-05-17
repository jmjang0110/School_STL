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
// String 이 제공하는 반복자
// 2023 05 08
class String_iterator {
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type        = char;
	using difference_type   = long long;
	using pounter           = char*;
	using reference         = char&;

private:
	char* p;
public:
	String_iterator() = default;
	String_iterator(char* p) : p{ p } {}



	String_iterator& operator++()
	{
		++p;
		return *this;

	}

	char& operator*() const {
		return *p;
	}

	// 2023 05 09 sort()에 필요한 연산자들
	difference_type operator-(const String_iterator& rhs) const {
		return p - rhs.p;
	}
	
	String_iterator& operator--(){
		--p;
		return *this;
	}


	String_iterator operator+(difference_type n) const {
		return String_iterator(p + n);

	}

	String_iterator operator-(difference_type n) const {
		return String_iterator(p - n);
	}


// 관계연산자  ==   !=   <   >   <=   >=   Relational Operators
// C++ 20 에서는 <=> 로 한번만 코딩 ( SpaceShip operator / Three Way Comparison Operator )

	//오류	C7634	'bool'은(는) 유효한 비교 형식이 아닙니다.대신 'std::strong_ordering' 사용을 고려하세요. -> auto
	auto operator<=>(const String_iterator& rhs) const = default;
	/*
	
	bool operator!= (const String_iterator& rhs) const {
		return p != rhs.p;
	}

	bool operator==(const String_iterator& rhs) const {
		return p == rhs.p;
	}

	bool operator<(const String_iterator& rhs)const {
		return p < rhs.p;
	}
	
	*/
	




};


// String 이 제공하는 역방향 반복자
// 2023 05 08
class String_reverse_iterator {

private:
	char* p;

public:
	String_reverse_iterator() = default;
	String_reverse_iterator(char* p) : p{ p } {}

	char& operator*() const{
		return *(p - 1);
	}
	String_reverse_iterator& operator++() {
		--p;
		return *this;
	}
	bool operator!=(const String_reverse_iterator& rhs) const {
		return p != rhs.p;
	}

};

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
	// 2023_4_11 nodexcept 추가 
	String(String&& other) noexcept; // noexcept : 내가 이동하는 와중에 데이터 잃어버릴 일은 없어라는 보증서 ( 복사 말고 이동해도 괜찮아.. ) 
	// 이동 할당 연산자 
	String& operator=(String&& other) noexcept; 


	bool operator==(const String& rhs) const;

	// 2023 05 15 추가 - set 이 요구하는 default 정렬기준 
	bool operator<(const String& rhs) const;

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
	friend std::istream& operator>>(std::istream& is, String& s) {
		std::string str;
		is >> str;
		delete[] s.p;
		s.len = str.size();
		s.p = new char[s.len];
		memcpy(s.p, str.data(), s.len);
		return is;

	}

	size_t size() const;

	/*friend std::ifstream& operator>>(std::ifstream& os, const String& str) {
		return os >> str.getString();
	}*/

public:
	// 2023 05 08
	String_iterator begin();
	String_iterator end();


	String_reverse_iterator rbegin();
	String_reverse_iterator rend();
};

