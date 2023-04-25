
#include <iostream>
#include "Dog.h"
#include "Tool.h"

using namespace std;

Dog::Dog()
{
	Tool t;
	n = t.GetRandomNum(1,1'000'00);
	c = t.GetRandomChar('a', 'z');

}

Dog::~Dog()
{

}
