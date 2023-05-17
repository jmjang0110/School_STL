#pragma once

/*
	2023_04_03 
*/

/*
	class String {

		public:
		 === SPECIAL FUNCTION ===
		 / ���α׷��Ӱ� �ۼ����� ������ �����Ϸ��� �˾Ƽ� ������ִ� Ư¡ /
			* ������		,	�Ҹ���
			* ���������	,	�����Ҵ翬����
			* �̵������� ,	�̵��Ҵ翬����
		 ========================
			* ������ �����ε�
			* gettor  /  settor
			* �� �� interface �Լ�

	}

*/
class ostream;
class string;
// String �� �����ϴ� �ݺ���
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

	// 2023 05 09 sort()�� �ʿ��� �����ڵ�
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


// ���迬����  ==   !=   <   >   <=   >=   Relational Operators
// C++ 20 ������ <=> �� �ѹ��� �ڵ� ( SpaceShip operator / Three Way Comparison Operator )

	//����	C7634	'bool'��(��) ��ȿ�� �� ������ �ƴմϴ�.��� 'std::strong_ordering' ����� ����ϼ���. -> auto
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


// String �� �����ϴ� ������ �ݺ���
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
	size_t len{};		// Ȯ���� �ڿ��� ����Ʈ ��  
	char* p{};			// Ȯ���� �ڿ��� �ּ�  
	size_t id = ++sid;	// ��ü ������ȣ 

	static size_t sid;	// Ŭ���� ����ƽ

public:


	// ����Ʈ ������   
	String();

	// ������ 
	String(const char* s);

	// �Ҹ���  
	~String();

	// ���������
	String(const String& other);

	// �����Ҵ� ������
	String& operator=(const String& other);

	// �̵�������  
	// 2023_4_11 nodexcept �߰� 
	String(String&& other) noexcept; // noexcept : ���� �̵��ϴ� ���߿� ������ �Ҿ���� ���� ������ ������ ( ���� ���� �̵��ص� ������.. ) 
	// �̵� �Ҵ� ������ 
	String& operator=(String&& other) noexcept; 


	bool operator==(const String& rhs) const;

	// 2023 05 15 �߰� - set �� �䱸�ϴ� default ���ı��� 
	bool operator<(const String& rhs) const;

	friend std::ostream& operator<<(std::ostream& _os, const String& _str) {
		// return _os << _str.p  << endl; // str.p �ϸ� ��������...
		for (int i = 0; i < _str.len; ++i) {
			_os << _str.p[i];
		}
		return _os;
	}


	String operator+(const String& rhs) const; // right hand side 


	// gettor / settor
	std::string getString() const;

	// �� �� �Լ�  
	void print(const char* msg);

	// 2023.04.04 �߰�
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

