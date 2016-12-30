#include "Identification.h"
#include "BinaryDataGen.h"
#include "Receipt.h"

int main(int argc, char* argv[])
{
	try
	{
		BinaryDataGen gen("mmm.bin");
		Identification user("mmm.bin");
		user.write();

		ABMReceipt issuer;
		
		issuer.issue();

		std::cout << issuer.getID() << " " << issuer.getTime()<<" "<<issuer.getATime();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	system("pause");
}