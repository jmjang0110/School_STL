
// -------------------------------------------------
// save.h : �� �б� ���� �����ϴ� �Լ� 
// -------------------------------------------------
//#pragma once 


#ifndef SAVE_FILE
#define SAVE_FILE

void save(const std::string& fileName);

namespace MySaveFileCode {

	void Save_File(const std::string& InFileName, const std::string& OutFileName);
	void Save_File_Auto(const int& Week, const int& Day);


}



#endif // SAVE_FILE


