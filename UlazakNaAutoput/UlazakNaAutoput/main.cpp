#include "Identification.h"
#include "BinaryDataGen.h"
#include "Receipt.h"
#include "Menu.h"
#include "CSVData.h"
#include "DialogBox.h"

int main(int argc, char* argv[])
{
	/*try
	{
		//BinaryDataGen gen("mmm.bin");
		ABM::Identification userList("users.bin");
		userList.write();

		ABM::ABMReceipt issuer;

		issuer.issue();

		std::cout << issuer.getID() << " " << issuer.getTime()<<" "<<issuer.getATime();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}

	ABM::Menu a({ "Register new vehicle", "New receipt", "Change user", "Print out statistics" });
	std::cout << "You have choosen item: " << a.call() + 1 << std::endl;

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

		for (int j = 0; j < data.size(); j++)
		{
			for (auto i : data[j])
				std::cout << i << " ";
			std::cout << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}


	*/

	ABM::DialogBox("test asdadw adwdaw adwaw");

	system("pause");
}