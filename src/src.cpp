#include<stdexcept>
#include<iostream>
#include<vector>

using namespace std;

string ReadAsciiFile(string path)
{
	string result = "";
	vector<char> file_contents;

	if (FILE *file = fopen(path.c_str(), "r"))
	{

		char char_buffer[1024];

		while (size_t read_length = fread(char_buffer, 1, sizeof(char_buffer), file))
			file_contents.insert(file_contents.end(), char_buffer, char_buffer + read_length);

		fclose(file);

	} else {
		throw runtime_error("File provided was not able to be opened for reading.");
	}

	for(char character : file_contents)
	{
		result += character;
	}

	return result;
}

const char* sift(int* argc, const char** argv[])
{
	--*argc;
	const char* arg = **argv;
	++*argv;
	return arg;
}

string get_program(int* argc, const char** argv[])
{
	string program = sift(argc, argv);

	const size_t last_slash_idx = program.find_last_of("\\/");

	if (string::npos != last_slash_idx)
	{
		program.erase(0, last_slash_idx + 1);
	}

	const size_t period_idx = program.rfind('.');

	if (string::npos != period_idx)
	{
		program.erase(period_idx);
	}

	return program;
}

void show_usage(string program)
{
	cout << "\n" << "Program Usage:\n" << "\n" << program.c_str() << " <path_with_file_to_process>" << "\n" << endl;
}

void show_error(runtime_error exception_thrown)
{
	cerr << "\n" << "Program Error:\n" << "\n" << " - " << exception_thrown.what() << "\n" << endl;
}

int main(int argc, const char* argv[])
{
	try
	{
		string program = get_program(&argc, &argv);

		if(argc == 0)
		{
			show_usage(program);
			throw runtime_error("File must be provided as first argument.");
		}

		string cmd = sift(&argc, &argv);

		if(cmd == "-h")
		{
			show_usage(program);
			return 0;
		}
		else
		{
			string maybe_file_with_path = cmd;
			string result = ReadAsciiFile(maybe_file_with_path);
		}
	}
	catch (runtime_error& exception_thrown)
	{
		show_error(exception_thrown);
		return -1;
	}
}
