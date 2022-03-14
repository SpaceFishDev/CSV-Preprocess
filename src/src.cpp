#include<iostream>
#include<vector>

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

std::string sift_rw(int* argc, const char** argv[])
{
	--*argc;
	const char* arg = **argv;
	std::string arg_str = arg;
	++*argv;
	return arg_str;
}

const char* sift_ro(int* argc, const char** argv[])
{
	--*argc;
	const char* arg = **argv;
	++*argv;
	return arg;
}

std::string get_program(int* argc, const char** argv[])
{
	std::string program = sift_rw(argc, argv);

	const size_t last_slash_idx = program.find_last_of("\\/");

	if (std::string::npos != last_slash_idx)
	{
		program.erase(0, last_slash_idx + 1);
	}

	const size_t period_idx = program.rfind('.');

	if (std::string::npos != period_idx)
	{
		program.erase(period_idx);
	}

	return program;
}

int main(int argc, const char* argv[])
{
	std::string program = get_program(&argc, &argv);

	if(argc == 0)
	{
		printf("\n");
		printf("Program Error:\n");
		printf("\n");
		printf(" - File must be provided as first argument.\n");
		printf("\n");
		printf("%s <path_with_file_to_process>\n", program.c_str());
		printf("\n");
		return 1;
	}
	else
	{
		std::string cmd = sift_ro(&argc, &argv);

		if(cmd == "-h")
		{
			printf("\n");
			printf("Program Usage:\n");
			printf("\n");
			printf("%s <path_with_file_to_process>\n", program.c_str());
			printf("\n");
			return 0;
		}
		else
		{
			std::string fpath = cmd;
			std::string src = ReadAsciiFile(fpath);
		}
	}
}
