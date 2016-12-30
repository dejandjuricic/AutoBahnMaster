#include "Identification.h"
#include "BinaryDataGen.h"

int main(int argc, char* argv[])
{
	try
	{
		BinaryDataGen gen("mmm.bin");
		Identification user("mmm.bin");
		user.write();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	system("pause");
}