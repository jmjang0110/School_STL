
// -------------------------------------------------
// save.h : 한 학기 강의 저장하는 함수 
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


