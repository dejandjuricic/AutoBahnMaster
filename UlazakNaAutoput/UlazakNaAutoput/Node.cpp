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
	int n;
	std::cout << "Number of nodes";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{

	}
}

ABM::Booth::Booth(std::string name, unsigned long id) noexcept : Node(name, id) {}
ABM::Intersection::Intersection(std::string name, unsigned long id) noexcept : Node(name, id) {}

std::ostream & ABM::operator<<(std::ostream& stream, const Node& data)
{
	return stream;
	//return stream<<"typeid(data).name()<<
}
