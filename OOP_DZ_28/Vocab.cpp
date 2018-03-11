#include "Vocab.h"



Vocab::Vocab()
{
}


Vocab::~Vocab()
{
}

void Vocab::ReadFile()
{
	std::string buf;
	std::fstream f;
	f.open("text.txt", std::ios_base::in);

	while (!f.eof())
	{
		f >> buf;
		if (slov.find(buf) == slov.end())
		{
			slov.insert(std::pair<std::string, int>(buf, 1));
		}
		else
		{
			slov[buf]++;
		}
	}
	f.close();
}

void Vocab::Show() const
{
	for (auto it = slov.begin(); it != slov.end(); it++)
	{
		std::cout <<"Word -> "<< it->first << " (" << it->second <<") repetitions in the text." <<std::endl;
	}
}

void Vocab::SaveFile()
{
	std::fstream f;
	f.open("result.txt", std::ios_base::out);
	for (auto it = slov.begin(); it != slov.end(); it++)
	{
		f << "Word -> " << it->first << " (" << it->second << ") repetitions in the text." << std::endl;
	}
	f.close();
}

void Vocab::Run()
{
	ReadFile();
	Show();
	SaveFile();
}

