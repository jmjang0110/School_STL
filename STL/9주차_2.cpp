
#define NINE_SECOND
#ifdef	NINE_SECOND

#include <iostream>
#include "save.h"

int main()
{

	MySaveFileCode::Save_File("9주차 자료/9주차_2.cpp", "9주차 자료/SPAN.txt읽기.txt");
	MySaveFileCode::Save_File_Auto(8, 1);
}

#endif
