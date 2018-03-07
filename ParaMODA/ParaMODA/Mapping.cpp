#include "Mapping.h"


Mapping::Mapping()
{
	this->Id = -1;
}

Mapping::Mapping(const Mapping & mapping)
{
	this->Id = mapping.Id;
	this->SubGraphEdgeCount = mapping.SubGraphEdgeCount;
	this->Function = mapping.Function;
}


Mapping::Mapping(map<int, int> function, int subGraphEdgeCount)
{
	this->Id = -1;
	this->SubGraphEdgeCount = subGraphEdgeCount;
	this->Function = function;
}

Mapping::~Mapping()
{
}


//NEED FURTHER CHECK for correct quickgraph integration
Edge<int>* Mapping::GetImage(UndirectedGraph<int>* inputGraph, Edge<int>* newlyAddedEdge)
{
	//Edge<int> *image;// = Edge<int>();
	//int source = (int)(newlyAddedEdge->getSource());
	//int target = (int)(newlyAddedEdge->getTarget());
	//try
	//{
	//	if (inputGraph->TryGetEdge(this->Function.at(source), this->Function.at(target), image))
	//		return image;
	//}
	//catch (out_of_range) {}
	Edge<int> *a = new Edge<int>(DefaultEdgeNodeVal, DefaultEdgeNodeVal);
	return a;
}


bool Mapping::operator==(const Mapping & other) const
{
	if (this->Id >= 0 || other.Id >= 0)
		return this->Id == other.Id;

	if (this->Function.size() != other.Function.size())
		return false;

	for (auto const& itr : this->Function)
	{
		try
		{
			if (itr.second != other.getFunction().at(itr.first))
				return false;
		}
		catch (out_of_range)
		{
			return false;
		}
	}
	return true;
}



string Mapping::GetMappedNodes()
{
	string result = "";
	if (this->Function.size())
	{
		map<int, int>::iterator itr = this->Function.begin();
		result += to_string((itr++)->second);
		for (; itr != this->Function.end(); itr++)
		{
			result += '-' + to_string(itr->second);
		}
	}
	return result;
}


//Overload to standard output
ostream & operator<<(ostream & outStream, const Mapping & data)
{
	string h = "";
	string g = "";
	if (data.getFunction().size())
	{
		h += "[";
		g += " => [";
		//map<int, int>::const_iterator itr = data.getFunction().begin();
		//h += to_string((itr)->first);
		//g += to_string((itr++)->second);
		//for (; itr != data.getFunction().end(); itr++)
		//{
		//h += '-' + to_string(itr->first);
		//g += '-' + to_string(itr->second);
		//}

		for (auto const& itr : data.getFunction())
		{
			h += to_string(itr.first) + '-';
			g += to_string(itr.second) + '-';
		}
		h.pop_back();
		h += "]";
		g.pop_back();
		g += "]\n";
	}
	outStream << h << g;
	return outStream;
}
