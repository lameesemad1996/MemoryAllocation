#include "Segmentt.h"

long Segment::SEGMENT_ID;

Segment::Segment()
{
	setID(SEGMENT_ID);
	SEGMENT_ID++;
	allocated = false;
}
Segment::Segment(string name)
{
	setID(SEGMENT_ID);
	SEGMENT_ID++;
	setName(name);
	allocated = false;
    parentProcessId = -1;
}

Segment::Segment(string name, long size)
{
	setID(SEGMENT_ID);
	SEGMENT_ID++;
	setName(name);
	setSize(size);
	allocated = false;
    parentProcessId = -1;
}
Segment::Segment(string name, long base, long limit, Segment::segmentState state)
{
	setID(SEGMENT_ID);
	SEGMENT_ID++;
	setName(name);
	setBase(base);
	setLimit(limit);
	setState(state);
	allocated = false;
    parentProcessId = -1;
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
void Segment::setStoredBase(long storedBase)
{
	this->storedBase = storedBase;
}
void Segment::setSize(long size)
{
	this->size = size;
}
void Segment::setLimit(long limit)
{
	this->limit = limit;
}
void Segment::setName(string name)
{
	this->name = name;
}
void Segment::setParentProcessId(long id)
{
    this->parentProcessId = id;
}
void Segment::setAllocated(bool allocated)
{
    this->allocated = allocated;
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
long Segment::getStoredBase()
{
	return storedBase;
}
long Segment::getSize()
{
	return size;
}
string Segment::getName()
{
	return name;
}
long Segment::getParentProcessId()
{
    return parentProcessId;
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
	allocated = true;
}
void Segment::sortSegListBySize_ascending(list<Segment> &segmentList)
{
	segmentList.sort(Segment::ascendingSortBySize);
}
void Segment::sortSegListBySize_descending(list<Segment> &segmentList)
{
	segmentList.sort(Segment::descendingSortBySize);
}
void Segment::sortSegListByBaseAdd_ascending(list<Segment> &segmentList)
{
	segmentList.sort(Segment::ascendingSortByBaseAdd);
}
bool Segment::ascendingSortBySize(const Segment &seg1, const Segment &seg2)
{
	return seg1.limit < seg2.limit;
}
bool Segment::descendingSortBySize(const Segment &seg1, const Segment &seg2)
{
	return seg1.limit > seg2.limit;
}
bool Segment::ascendingSortByBaseAdd(const Segment &seg1, const Segment &seg2)
{
	return seg1.base < seg2.base;
}
list<Segment> Segment::filterFree(list<Segment> segmentList)
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
list<Segment> Segment::filterOldProcess(list<Segment> segmentList)
{
    list<Segment> returnable;
    list<Segment>::iterator it;
    for (it = segmentList.begin(); it != segmentList.end(); ++it)
    {
        if (it->getState() == 2)
        {
            returnable.push_back(*it);
        }
        else continue;
    }
    return returnable;
}
list<Segment> Segment::collect(list<Segment> &memorySegmentsList)
{
	sortSegListByBaseAdd_ascending(memorySegmentsList);
	list<Segment>::iterator it;
	list<Segment>::iterator it2;
	list<Segment> returnable;
	for (it = memorySegmentsList.begin(); it != memorySegmentsList.end(); ++it)
	{
		it2 = ++it;
		it--;
		if(it2== memorySegmentsList.end())
		{
			continue;
		}
		else
		{
			if (((it->base) + (it->limit)) == (it2->base))
			{
				long toBeAdded = it->limit + it2->limit;
				it->limit = toBeAdded;
				memorySegmentsList.erase(it2);
				returnable.push_back(*it);
			}
			else
			{
				returnable.push_back(*it);
			}
		}
	}
	return returnable;
}
void Segment::collectFree(list<Segment> &memorySegmentsList)
{
    sortSegListByBaseAdd_ascending(memorySegmentsList);
    list<Segment>::iterator it;
    list<Segment>::iterator it2;

    for (it = memorySegmentsList.begin(); it != memorySegmentsList.end(); ++it)
    {
        if(it->getState() != Segment::segmentState::free)
            continue;
        else if (it->getState() == Segment::segmentState::free)
        {
            it2 = ++it;
            it--;

            if(it == memorySegmentsList.end())
            {
                continue;
            }
            else
            {
                if(it2->getState() == Segment::segmentState::free)
                {
                    if (((it->base) + (it->limit)) == (it2->base))
                    {
                        long toBeAdded = it->limit + it2->limit;
                        it->setLimit(toBeAdded);
                        if(it2 == memorySegmentsList.end())
                        {
                            memorySegmentsList.pop_back();
                        }
                        else
                        {
                            memorySegmentsList.erase(it2);
                        }
                    }
                    else continue;
                }

            }
        }
    }
}

void Segment::printSegList(list<Segment> segmentList)
{
	list<Segment>::iterator it;
	for (it = segmentList.begin(); it != segmentList.end(); ++it)
	{
		cout << "Segment ID = " << it->getID() << " Name: " << it->getName() << " State: " << it->getState() << " Base = " << it->getBase() << " Limit = " << it->getLimit() << endl;
	}
}

