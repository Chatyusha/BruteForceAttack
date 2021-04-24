#include <iostream>
#include <string>

int main (int argc, char* argv[])
{
	std::string password = "face";
	if (argv[1] == password){
		std::cout<<"success"<<std::endl;
		std::exit(0);
	}
	std::exit(1);
}
