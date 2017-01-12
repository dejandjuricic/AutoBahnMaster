#pragma once
#include "stdHeader.h"

namespace ABM
{
	/*Node Represents a point on a highway in which
	a vehicle can either exit or enter the highway 
	or proceed to an another node. Each node must 
	have an ID and ought to have a specific name
	for easier human interaction and ought to
	have a counter for easier tracking of traffic*/ 
	class Node
	{
		std::string nodeName;
		unsigned long nodeID;
		unsigned long vehicleCounter = 0;
		friend std::ostream& operator<<(std::ostream&, const Node&);
	public:
		Node(std::string, unsigned long) noexcept;
		Node() = delete;
		std::string name() const noexcept;
		unsigned long id() const noexcept;
		unsigned long counter() const noexcept;
		void operator++() noexcept;
	};

	//On booths entry and exit from the highway is possible
	class Booth : public Node
	{
	public:
		Booth(std::string, unsigned long) noexcept;
	};

	//Intersections can lead only to other nodes (booths or intersections)
	class Intersection : public Node
	{
	public:
		Intersection(std::string, unsigned long) noexcept;
	};

	class NodeNetwork
	{
		std::vector<Node> nodeList;
		std::vector<std::vector<Node>> distanceMatrix;
	public:
		NodeNetwork();
	};
}