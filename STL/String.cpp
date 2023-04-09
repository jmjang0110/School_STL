
#include <iostream>
#include <string>
#include "String.h"

size_t String::sid = { 0 };
bool ���� = { false };


// ����Ʈ ������   
String::String()
{
	print("����Ʈ ����");
}

// ������ 
String::String(const char* s) : len{ strlen(s) }
{
	p = new char[len]; // �����Ҵ��� ���⼭ len �� �������� p �� ���� ���� : ���Ŀ� ���� �� 
	memcpy(p, s, len);
	print("����(char*)");
}

// �Ҹ���  
String::~String()
{
	//if( p != nullptr) // ���� �ʿ䰡 ���� �ڵ��̴�. 
	print("�Ҹ���");
	delete[] p;
}

// ���������
String::String(const String& other) : len(other.len)
{
	p = new char[len];
	memcpy(p, other.p, len);
	print("�������");
}

// �����Ҵ� ������
String& String::operator=(const String& other)
{
	if (this == &other)
		return *this;
	delete[] p;

	len = other.len;
	p = new char[len];
	memcpy(p, other.p, len);

	print("�����Ҵ翬����");

	return *this;

}

// �̵�������  
String::String(String&& other)
{		// && - r_Value Reference  
	len = other.len;
	p = other.p;

	// ���� ( Other �� �����Ѵ� ) 
	// Other �� �������� ������ ���α׷� ���  
	other.len = 0;
	other.p = nullptr; // �̰� �����ָ� Dangleing Pointer �� ���ܼ� ���α׷��� �״´�. 


	print("�̵�������");
}

// �̵� �Ҵ� ������ 
String& String::operator=(String&& other)
{
	if (this == &other)
		return *this;

	// Ȯ���� �ڿ��� ����  
	delete[] p;


	// Other �� �ڿ��� �����´�. 
	len = other.len;
	p = other.p;


	// Other �� �ʱ�ȭ�Ѵ�.
	other.len = 0;
	other.p = nullptr;

	print("�̵��Ҵ翬����");

	return *this;
}

// 2023.04.04 �߰� 
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

// �� �� �Լ�  
void String::print(const char* msg)
{

	if (����) {
		std::cout << "[" << id << "] - " << msg << ", ����:" << len
			<< ", �ּ�:" << (void*)p << std::endl; // ����ȯ �ؾ��Ѵ�. 
	}
}
