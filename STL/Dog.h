#pragma once


#include <fstream>


class Dog {
	char c;
	int n;
	// 5 byte �ε� �� 8 byte �� ������ ?   - �ڿ��� �� �Ἥ �ӵ��� ��´�. 
public:
	Dog();
	~Dog();

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << "���� - " << dog.c << ", ���� - " << dog.n;
	}
	friend std::istream& operator>>(std::istream& is, Dog& dog) {
		is.read((char*)&dog, sizeof(Dog));
		return is;
	}
};

