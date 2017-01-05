#include "Identification.h"
#include "BinaryDataGen.h"
#include "Receipt.h"
#include "Menu.h"

int main(int argc, char* argv[])
{
	/*try
	{
		BinaryDataGen gen("mmm.bin");
		ABM::Identification userList("mmm.bin");
		userList.write();

		ABM::ABMReceipt issuer;

		issuer.issue();

		std::cout << issuer.getID() << " " << issuer.getTime()<<" "<<issuer.getATime();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}*/

	ABM::Menu a({ "Register new vehicle", "New receipt", "Change user", "Print out statistics" });
	std::cout << "You have choosen item: " << a.call() + 1 << std::endl;
	system("pause");
}