#pragma once
#include "stdHeader.h"

namespace ABM
{
	class Node
	{
		std::string nodeName;
		unsigned long nodeID;
		std::vector<std::tuple<Node, long double>> connections;//Delete
		unsigned long vehicleCounter = 0;
	public:
		Node(std::string, unsigned long, std::vector<std::tuple<Node, long double>>) noexcept;
		Node() = delete;
	};

	class Booth : public Node
	{

	};

	class Intersection : public Node
	{

	};

	class NodeNetwork
	{
		std::vector<Node> nodeList;
		std::vector<std::vector<Node>> distanceMatrix;
	public:
		NodeNetwork();
	};
}