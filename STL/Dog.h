#pragma once


#include <fstream>


class Dog {
	char c;
	int n;
	// 5 byte 인데 왜 8 byte 가 나오지 ?   - 자원을 더 써서 속도를 얻는다. 
public:
	Dog();
	~Dog();

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << "글자 - " << dog.c << ", 숫자 - " << dog.n;
	}
	friend std::istream& operator>>(std::istream& is, Dog& dog) {
		is.read((char*)&dog, sizeof(Dog));
		return is;
	}
};

