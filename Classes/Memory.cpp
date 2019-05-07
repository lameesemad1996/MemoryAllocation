#include "Memory.h"

Memory::Memory()
{

}
Memory::Memory(long size)
{

}
Memory::Memory(long size, list<Segment> allocatedSegmentsList, list<Segment> freeSegmentsList)
{

}

Memory::~Memory()
{
}

///set methods
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

///get methods
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

///other methods

bool Memory::first_fit_allocate_check(Process process)
{
	bool returnable = false;

	list<Segment> freeSegmentsList = Segment::filterFree(memorySegmentsList);
	//this->freeSegmentsList.assign(freeSegmentsList.begin(), freeSegmentsList.end());
	list<Segment> freeSegmentsListCopy;
	freeSegmentsListCopy.assign(freeSegmentsList.begin(), freeSegmentsList.end());

	list<Segment> processCopySegList;
	processCopySegList.assign(process.segmentList.begin(), process.segmentList.end());


	//corner cases
	if (process.segmentList.empty())
	{
		cout << "Process is empty." << endl;
		return returnable;

	}

	if (freeSegmentsList.empty())
	{
		cout << "No free segments in memory." << endl;
		return returnable;
	}

	list<Segment>::iterator it0;
	list<Segment>::iterator it1;

	for (it0 = processCopySegList.begin(); it0 != processCopySegList.end(); ++it0)
	{
		for (it1 = freeSegmentsListCopy.begin(); it1 != freeSegmentsListCopy.end(); ++it1)
		{
			if ((it1->getLimit() >= it0->getLimit()) && (it1->getState() == Segment::free))
			{
				//set this segment as occupied
				it1->setState(Segment::occupied);
				//get size of free slot before occupation
				long sizeSegBeforeAlloc = it1->getLimit();
				//set size of occupied slot to be equal to the size of the segment being inserted
				it1->setLimit(it0->getLimit());
				//calculate the base of the new free slot
				long newSegmentBase = it1->getBase() + it1->getLimit();
				//create a new slot, set its base, set its limit and mark it as a free slot
				Segment newFreeSegment;
				newFreeSegment.setBase(newSegmentBase);
				newFreeSegment.setLimit((sizeSegBeforeAlloc - it0->getLimit()));
				newFreeSegment.setState(Segment::free);
				//insert the free slot right after the occupied slot
				//new iterator it pointing at the next position
				list<Segment>::iterator test = ++it1;
				it1--;
				if (test == freeSegmentsListCopy.end())
				{
					freeSegmentsListCopy.push_back(newFreeSegment);
				}
				else
				{
					freeSegmentsListCopy.insert(test, newFreeSegment);
				}

				list<Segment>::iterator test2 = ++it0;
				it0--;
				if (test2 == processCopySegList.end())
				{
					processCopySegList.pop_back();
					break;
				}
				else
				{
					processCopySegList.erase(it0);
				}
				break;
			}
			else
			{
				list<Segment>::iterator lastElementTest;
				lastElementTest = ++it1;
				it1--;

				if (lastElementTest == freeSegmentsListCopy.end())
				{
					return returnable;
				}
				else
					continue;
			}

		}
	}
	//if all segments can be allocated the copied list would be empty so return true
	if (processCopySegList.empty())
	{
		returnable = true;
		return returnable;
	}
	else return returnable;
}
bool Memory::first_fit_allocate(Process &process)
{
	bool canBeAllocated = first_fit_allocate_check(process);
	if (canBeAllocated)
	{
		list<Segment> freeSegments = Segment::filterFree(memorySegmentsList);

		list<Segment>::iterator it0;
		list<Segment>::iterator it1;
		for (it0 = process.segmentList.begin(); it0 != process.segmentList.end(); ++it0)
		{
			for (it1 = freeSegments.begin(); it1 != freeSegments.end(); ++it1)
			{
				if ((it1->getLimit() >= it0->getLimit()) && it1->getState() == Segment::free)
				{
					//base address to be stored
					it0->setStoredBase(it1->getBase());
					this->allocatedProcessesList.push_back(process);
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
void Memory::printMemory()
{
	list<Segment>::iterator it;
	for (it = this->memorySegmentsList.begin(); it != this->memorySegmentsList.end(); ++it)
	{
		cout << "Segment ID = " << it->getID() << " Name: " << it->getName() << " State: " << it->getState() << " Base = " << it->getBase() << " Limit = " << it->getLimit() << endl;
	}
}
void Memory::addSegment(Segment segment)
{
	memorySegmentsList.push_back(segment);
}


