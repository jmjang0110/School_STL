
//#define SEVENTH_SECOND
#ifdef	SEVENTH_SECOND

// ============================================ //
// deque
// vector �ʹ� �ݴ�� contiguious �ϰ� �޸𸮿� ����Ǿ����� ������ 
// �ε����� �Ǿ��ִ�. 
// 
// ============================================ //

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>		// �յڿ��� ����� �߰��ϴ� ������ ����  
#include <list>
#include <queue>

#include <fstream>


/*
	vector -  136216567
	deque -   268435452
	list -	   85375361
	
*/
#include "../save.h"
#include "../String.h"

using namespace std;

extern bool ����;

int main()
{
	std::ifstream InFile{ "list.txt" };
	list<String> Contatiner{ /*���� ����*/ std::istream_iterator<String>{InFile}, { }}; // insert �ϸ� �����ϰ� �� ����ִ´� 
	
	// EOF �� ���´ٸ� false �� ���ϵȴ�. 

	// ������ �غ��� 
	// [ ���� ] - ���� ���� 5�� �ܾ "�ټ�����.txt" ���Ͽ� �����϶� 
	// Copy �˰��� ?  
	// ���ö��̽� ?  
	//std::ostream
	//std::copy_if(Contatiner.begin(), Contatiner.end(), std::ostream_iterator <String>("�ټ�����.txt",) , /*�ټ����ڶ��*/);

	//std::copy_if(to_vector.begin(), to_vector.end(),
	//	std::ostream_iterator<int>(std::cout, " "),
	//	[](int x) { return x % 2 != 0; });


	std::ofstream out{ "�ټ�����.txt" }; // ������ �ִ� ���� �ı��ȴ�.

	/*
	for (String& s : Contatiner) {
		if (s.getSize() == 5)
			out << s << endl;
	}

	*/

	std::copy_if(Contatiner.begin(), Contatiner.end(),
		std::ostream_iterator<String>{ out, "\n"},
		[](const String& s) { return s.getSize() == 5; });

	

	InFile.close();

	MySaveFileCode::Save_File("8���� �ڷ�/8����_1.cpp", "8���� �ڷ�/list.txt_2�б�.txt");
	MySaveFileCode::Save_File_Auto(8, 1);
}

#endif
