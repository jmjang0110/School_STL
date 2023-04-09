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
	String(String&& other);
	// �̵� �Ҵ� ������ 
	String& operator=(String&& other);



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

