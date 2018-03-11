#pragma once
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
class Vocab
{
private:
	std::map<std::string, int> slov;
public:
	Vocab();
	~Vocab();
	void ReadFile();
	void Show()const;
	void SaveFile();
	void Run();
};

