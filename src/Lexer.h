#include<iostream>
#include<vector>

using namespace std;

vector<string> getRows(string src)
{
  const char* src_chr = src.c_str();

  string temp = "";
  vector<string> rows;

  while(*src_chr)
  {
    char c = *src_chr;

    if(c == '\n')
    {
      rows.push_back(temp);
    }
    else
    {
      temp += c;
    }

    ++src_chr;
  }

  rows.push_back(temp);

  return rows;
}
