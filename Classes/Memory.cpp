#include "Memory.h"

Memory::Memory(long size, list<Segment> allocatedSegmentsList, list<Segment> freeSegmentsList)
{

}

Memory::~Memory()
{
}

//set methods
void Memory::setSize(long size)
{
	this->size = size;
}
void Memory::setFreeSize(long size)
{
	this->size = size;
}
void Memory::setAllocatedSize(long size)
{
	this->size = size;
}

//get methods
long Memory::getSize()
{
	return size;
}
long Memory::getFreeSize()
{
	return freeSize;
}
long Memory::getAllocatedSize()
{
	return allocatedSize;
}

//other methods
bool Memory::first_fit_allocate_check(Process process)
{
	bool returnable = false;

	list<Segment> freeSegments = Segment::assignFree(memorySegmentsList);
	this->freeSegmentsList.assign(freeSegments.begin(), freeSegments.end());

	list<Segment> processCopySegList;
	processCopySegList.assign(process.segmentList.begin(), process.segmentList.end());

	list<Segment>::iterator it0;
	list<Segment>::iterator it1;
	for (it0 = processCopySegList.begin(); it0 != processCopySegList.end(); ++it0)
	{
		list<Segment> returnedFree = Segment::assignFree(memorySegmentsList);
		list<Segment> freeSegments;
		freeSegments.assign(returnedFree.begin(), returnedFree.end());

		for (it1 = freeSegments.begin(); it1 != freeSegments.end(); ++it1)
		{
			if ((it1->getLimit() >= it0->getLimit()) && it1->getState() == Segment::free)
			{
				//set this segment as occupied
				it1->setState(Segment::occupied);
				//get size of free slot before occupation
				long sizePrevSegment = it1->getLimit();
				//set size of occupied slot to be equal to the size of the segment being inserted
				it1->setLimit(it0->getLimit());
				//calculate the base of the new free slot
				long newSegmentBase = it1->getBase() + it1->getLimit();
				//create a new slot, set its base, set its limit and mark it as a free slot
				Segment newFreeSegment;
				newFreeSegment.setBase(newSegmentBase);
				newFreeSegment.setLimit((sizePrevSegment - it0->getLimit()));
				newFreeSegment.setState(Segment::free);
				//insert the free slot right after the occupied slot
				//new iterator it pointing at the next position
				list<Segment>::iterator test = ++it1;
				it1--;
				if (test == freeSegments.end())
				{
					freeSegments.push_back(newFreeSegment);
				}
				else
				{
					freeSegments.insert(test, newFreeSegment);
				}
				processCopySegList.erase(it0);
				break;
			}
			else continue;
		}
	}
	//if all segments can be allocated the copied list would be empty so return true
	if (processCopySegList.empty())
	{
		returnable = true;
	}
	else return returnable;
}
bool Memory::first_fit_allocate(Process process)
{
	bool canBeAllocated = first_fit_allocate_check(process);
	if (canBeAllocated)
	{
		list<Segment> freeSegments = Segment::assignFree(memorySegmentsList);

		list<Segment>::iterator it0;
		list<Segment>::iterator it1;
		for (it0 = process.segmentList.begin(); it0 != process.segmentList.end(); ++it0)
		{
			for (it1 = freeSegments.begin(); it1 != freeSegments.end(); ++it1)
			{
				if ((it1->getLimit() >= it0->getLimit()) && it1->getState() == Segment::free)
				{
					//set this segment as occupied
					it1->setState(Segment::occupied);
					//get size of free slot before occupation
					long sizePrevSegment = it1->getLimit();
					//set size of occupied slot to be equal to the size of the segment being inserted
					long newSizeOfCurrentSegment = it0->getLimit();
					it1->setLimit(newSizeOfCurrentSegment);
					//calculate the base of the new free slot
					long newSegmentBase = it1->getBase() + it1->getLimit();
					//create a new slot, set its base, set its limit and mark it as a free slot
					Segment newFreeSegment;
					newFreeSegment.setBase(newSegmentBase);
					newFreeSegment.setLimit((sizePrevSegment - it0->getLimit()));
					newFreeSegment.setState(Segment::free);
					//insert the free slot right after the occupied slot
					//new iterator it pointing at the next position
					list<Segment>::iterator test = ++it1;
					it1--;
					if (test == freeSegments.end())
					{
						freeSegments.push_back(newFreeSegment);
					}
					else
					{
						freeSegments.insert(test, newFreeSegment);
					}
					//erase segment from list of free segments
					freeSegmentsList.erase(it1);
					//mark segment as occupied in original memory segment list
					long currentId = it1->getID();
					list<Segment>::iterator it2;
					for (it2 = this->memorySegmentsList.begin(); it2 != this->memorySegmentsList.end(); ++it2)
					{
						if (it2->getID() == currentId)
						{
							it2->setState(Segment::occupied);
							it2->setLimit(newSizeOfCurrentSegment);
							//insert the free slot right after the occupied slot
							it2++;
							if (it2 == freeSegments.end())
							{
								this->memorySegmentsList.push_back(newFreeSegment);
							}
							else
							{
								this->memorySegmentsList.insert(test, newFreeSegment);
							}
							break;
						}
					}
					break;
				}
				else continue;
			}
		}
	}
	else return false;
}

//to be edited
void Memory::allocateProcess(Process process)
{
	list<Segment>::iterator it;
	for (it = process.segmentList.begin(); it != process.segmentList.end(); ++it)
	{
		allocatedSegmentsList.push_back(*it);
	}
}


