
#include<iostream>
#include<vector>

std::vector<std::string> getRows(std::string src)
{
	const char* src_chr = src.c_str();
	std::string temp = "";
	std::vector<std::string> rows;
	while(*src_chr)
	{
		char c = *src_chr;
		if(c == '\n')
		{
			rows.push_back(temp);
		}else
		{
			temp += c;
		}
		++src_chr;
	}
	rows.push_back(temp);
	return rows;
}