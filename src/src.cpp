#include<iostream>

const char* sift(int* argc, char*** argv)
{
	--argc;
	const char* r = **argv;
	++*argv;
	return r;
}


std::string ReadAsciiFile(std::string path)
{
	std::string r = "";
	std::vector<char> v;
	if (FILE *fp = fopen(path.c_str(), "r"))
	{
		char buf[1024];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			v.insert(v.end(), buf, buf + len);
		fclose(fp);
	}
	for(char c : v)
	{
		r += c;
	}
	return r;
}

int main(int argc, char** argv)
{
	const char* program = sift(&argc, &argv);
	if(argc == 0)
	{
		printf("ERROR: File must be inputted");
		return 0;
	}
	std::string cmd = sift(&argc, &argv);
	if(cmd == "-h")
	{

	}
	else
	{
		std::string fpath = cmd;
		std::string src = ReadAsciiFile(fpath);
	}
}

