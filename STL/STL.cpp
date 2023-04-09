//#define STL
#ifdef STL
// --------------------------------------------------
//	2023 1 �б� STL 4�� 03�� TUE 23 Tue 56 ( 5�� 1)
// --------------------------------------------------
//	C++ Ŭ���� ���� - String Ŭ������ �����.
// ������ String Ŭ������ STL �����̳ʷ� ������Ų��. 
// --------------------------------------------------

#include <iostream>
#include <array>
#include <algorithm>
#include <string>

#include "save.h"

using namespace std;


bool ����{ false };


class String {
private:
	size_t len{};
	char* p{}; // default nullptr �̴�.  // unique_ptr<char> p �� �ٲ㼭 �ڵ��Ͽ� ������� 
	size_t id = ++sid;	// ��ü ������ȣ 

	static size_t sid;

public:
	friend ostream& operator<<(ostream& _os, const String& _str) {
		// return _os << _str.p  << endl; // str.p �ϸ� ��������...
		for (int i = 0; i < _str.len; ++i) {
			_os << _str.p[i];
		}
		return _os;
	}
	//String() = default;
	String() {
		print("����Ʈ ����");
	}
	~String() {
		//if( p != nullptr) // ���� �ʿ䰡 ���� �ڵ��̴�. 
		print("�Ҹ���");
		delete[] p;
	}

	String(const String& other) : len(other.len) {
		p = new char[len];
		memcpy(p, other.p, len);
		print("�������");
	}

	// ��������ڸ� �ڵ��ߴٸ� �����Ҵ� �����ڵ� �ݵ�� �ڵ��ؾ� �Ѵ�.???
	String& operator=(const String& other) {
		if (this == &other)
			return *this;
		delete[] p;

		len = other.len;
		p = new char[len];
		memcpy(p, other.p, len);

		print("�����Ҵ翬����");

		return *this;

	}


	String(const char* s) : len{ strlen(s) } {
		p = new char[len]; // �����Ҵ��� ���⼭ len �� �������� p �� ���� ���� : ���Ŀ� ���� �� 
		memcpy(p, s, len);
		print("����(char*)");

		// �� delete ����� 
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

		if (����) {
			cout << "[" << id << "] - " << msg << ", ����:" << len
				<< ", �ּ�:" << (void*)p << endl; // ����ȯ �ؾ��Ѵ�. 
		}
	}


};

size_t String::sid = { 0 };

// -------	
int main()
// -------
{
	/*
	
		** �׸� �׸��鼭 �����غ��� ** 
		
		
	*/

	array<String, 5> news{
		"���缮��", "���", "�ɾ����", "����", "�ɱ׷�.."
	};

	���� = true;

	// �̷��� �ڸ� ����Ǵϱ� ������������ �����Ѵ�...
	for (String s : news) {
		cout << s << endl;

	}
	// & �� ����Ѵ�. 
	for (String& s : news) {
		cout << s << endl;

	}

	// �� ���۷����� ���� .... ���� �Ҹ� ��û�� 
	sort(news.begin(), news.end(), [](const String& a,const String& b) {
		return a.getString() < b.getString(); // �������� 
		});


	���� = false;


	save("STL.cpp");

}

#endif // STL
