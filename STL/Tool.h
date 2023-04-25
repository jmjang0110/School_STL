#pragma once
#include <iostream>
#include <random>
#include <format>

/*
RAII : Resource Acquisition Is Initialization 만듦과 동시에 초기화

*/

enum class FILE_MODE
{
	TEXT,
	BINARY,
	END,

};
class Tool
{
private:
	static std::default_random_engine dre;


public:
	int GetRandomNum(int min, int max);
	char GetRandomChar(char start, char end);


	int GetMIN_INT();
	int GetMAX_INT();

	void StoreIncreasingValues_iota();

	void Save_to_File(const std::string& FileName, FILE_MODE _eMode);


	//std::shuffle(v.begin(), v.end(), std::mt19937{ std::random_device{}() });

public:
	void SaveFIle_1000_INT(const std::string& filename);
	void LoadFIle_1000_INT(const std::string& filename);


public:
	void ShowDrop();
	int GetNumForMemory_MB(int MB, int _sizeofMemory_One);


public:
	Tool();
	~Tool();



};


