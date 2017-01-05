#pragma once
#include "stdHeader.h"

namespace ABM
{
	class Node
	{
		std::string nodeName;
		unsigned long nodeID;
		std::vector<std::tuple<Node, long double>> connections;
		unsigned long vehicleCounter = 0;
	public:
		Node(std::string, unsigned long, std::vector<std::tuple<Node, long double>>) noexcept;
	};

	class NodeNetwork
	{
		std::vector<Node> nodeList;
	public:
		NodeNetwork();
	};
}