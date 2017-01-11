#include "Identification.h"
#include "BinaryDataGen.h"
#include "Receipt.h"
#include "Menu.h"
#include "CSVData.h"

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

	/*ABM::Menu a({ "Register new vehicle", "New receipt", "Change user", "Print out statistics" });
	std::cout << "You have choosen item: " << a.call() + 1 << std::endl;*/

	try
	{
		ABM::Identification userList("users.bin");

		ABM::ABMReceipt issuer;

		ABM::Menu meni({ "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "", "" });

		std::cout << "You have chosen item: " << meni.call() + 1 << std::endl;

		CSVData data("data.csv");

		std::vector<std::string> sr({ "srdjane", "izdajico", "izdao", "si", "srbiju" });

		std::cout << data.addEntry(sr) << std::endl;
		std::cout << data.addEntry(sr) << std::endl;
		std::cout << data.addEntry(sr) << std::endl;
		std::cout << data.addEntry(sr) << std::endl;
		std::cout << data.addEntry(sr) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}




	system("pause");
}