#include "Node.h"

ABM::Node::Node(std::string nodeName, unsigned long nodeID, std::vector<std::tuple<Node, long double>> connections) noexcept : nodeName(nodeName), nodeID(nodeID), connections(connections) {}

ABM::NodeNetwork::NodeNetwork()
{
	int n;
	std::cout << "Number of nodes";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{

	}
}
