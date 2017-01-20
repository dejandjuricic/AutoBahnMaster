#include "Node.h"

ABM::Node::Node(std::string nodeName, unsigned long nodeID) noexcept : nodeName(nodeName), nodeID(nodeID) {}

std::string ABM::Node::name() const noexcept
{
	return nodeName;
}

unsigned long ABM::Node::id() const noexcept
{
	return nodeID;
}

unsigned long ABM::Node::counter() const noexcept
{
	return vehicleCounter;
}

void ABM::Node::operator++() noexcept
{
	vehicleCounter++;
}

ABM::NodeNetwork::NodeNetwork()
{
	std::string temp, temp2; 
	std::fstream file("file.csv"); 
	
	if (!file.is_open()) throw std::ios::badbit;
	file.get(); file.get(); file.get();
	while (!file.eof())
	{
		std::getline(file, temp, ',');
		std::getline(file, temp2); 
		nodeList.push_back(Node(temp, atoi(temp2.c_str()))); 

		if (atoi(temp2.c_str()) == 0) break;
	}

	for (auto& i : nodeList)
		std::cout << i; 

}

ABM::Booth::Booth(std::string name, unsigned long id) noexcept : Node(name, id) {}
ABM::Intersection::Intersection(std::string name, unsigned long id) noexcept : Node(name, id) {}

std::ostream & ABM::operator<<(std::ostream& stream, const Node& data)
{
	return stream << data.nodeName << " " << data.nodeID << std::endl;
	
	//return stream<<"typeid(data).name()<<
}
