#include<iostream>

const char* sift(int* argc, char*** argv)
{
	--argc;
	const char* r = **argv;
	++*argv;
	return r;
}

int main()
{

}
