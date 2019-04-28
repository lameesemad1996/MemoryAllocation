#include "Segment.h"

Segment::Segment()
{
}

Segment::~Segment()
{
}

//set methods
void Segment::setState(enum segmentState state)
{
	this->state = state;
}
void Segment::setID(long id)
{
	this->id = id;
}
void Segment::setBase(long base)
{
	this->base = base;
}
void Segment::setLimit(long limit)
{
	this->limit = limit;
}
void Segment::setName(string name)
{
	this->name = name;
}

//get methods
long Segment::getID()
{
	return id;
}
long Segment::getLimit()
{
	return limit;
}
long Segment::getBase()
{
	return base;
}
string Segment::getName()
{
	return name;
}
Segment::segmentState Segment::getState()
{
	return state;
}

//other methods
void Segment::markAsOldProcess(long baseAddress, long size)
{
	setName("Old Process");
	setBase(baseAddress);
	setLimit(size);
}
void Segment::sortSegList_ascending(list<Segment> segmentList)
{
	segmentList.sort(Segment::ascendingSortBySize);
}
void Segment::sortSegList_descending(list<Segment> segmentList)
{
	segmentList.sort(Segment::descendingSortBySize);
}
bool Segment::ascendingSortBySize(const Segment &seg1, const Segment &seg2)
{
	return seg1.limit < seg2.limit;
}
bool Segment::descendingSortBySize(const Segment &seg1, const Segment &seg2)
{
	return seg1.limit < seg2.limit;
}
list<Segment> Segment::assignFree(list<Segment> segmentList)
{
	list<Segment> returnable;
	list<Segment>::iterator it;
	for (it = segmentList.begin(); it != segmentList.end(); ++it)
	{
		if (it->getState() == 0)
		{
			returnable.push_back(*it);
		}
		else continue;
	}
	return returnable;
}
