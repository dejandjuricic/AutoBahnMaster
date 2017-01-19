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
	public:
		NodeNetwork();
		//TODO: implement creation of adjacent matrix
		/*Each node should have its id, all ids should be
		sequential, after inputing all nodes, NodeNetwork
		should load the node network from a csv file,
		if the file does not exist create a new file
		in which ids of nodes represent columns and rows
		(they are not written isnide of the csv file)
		and they should contain distances between nodes
		which are inputted like:
		cout<<nodeID
		cout<<nodeName
		then start inputting like
		cout<<nodeID<<"->
		and input the other nodeID, check if the ID
		exists and if it exists allow input of a float
		that represents distance and update the adjacent
		matrix accordingly, if you input the same node
		ID it stops the input*/
	};
}