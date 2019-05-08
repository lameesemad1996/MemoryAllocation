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

	cout << processCopySegList.size() << endl;
	cout << freeSegmentsListCopy.size() << endl;

	for (it0 = processCopySegList.begin(); it0 != processCopySegList.end(); ++it0)
	{
		if (it0->allocated == true)
			continue;

		for (it1 = freeSegmentsListCopy.begin(); it1 != freeSegmentsListCopy.end(); ++it1)
		{
			if ((it1->getLimit() >= it0->getLimit()) && (it1->getState() == Segment::free))
			{
				cout << "Hi" << endl;

				cout << it0->allocated << endl;

				//mark this segment as allocated
				it0->allocated = true;

				cout << it0->allocated << endl;

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
				list<Segment>::iterator nextPositionFreeSegments = ++it1;
				it1--;
				if (nextPositionFreeSegments == freeSegmentsListCopy.end())
				{
					freeSegmentsListCopy.push_back(newFreeSegment);
				}
				else
				{
					freeSegmentsListCopy.insert(nextPositionFreeSegments, newFreeSegment);
					//it1++;
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

	list<Segment>::iterator testIfDone;
	bool flagIsDone = true;

	for (testIfDone = processCopySegList.begin(); testIfDone != processCopySegList.end(); ++testIfDone)
	{
		if (testIfDone->allocated == false)
			flagIsDone = false;
	}
	if (flagIsDone)
		returnable = true;
	return returnable;
}
bool Memory::first_fit_allocate(Process &process)
{
	bool canBeAllocated = first_fit_allocate_check(process);
	if (canBeAllocated)
	{

		bool returnable = false;

		list<Segment> freeSegmentsList = Segment::filterFree(memorySegmentsList);
		//this->freeSegmentsList.assign(freeSegmentsList.begin(), freeSegmentsList.end());

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


		for (it0 = process.segmentList.begin(); it0 != process.segmentList.end(); ++it0)
		{
			if (it0->allocated == true)
				continue;

			for (it1 = freeSegmentsList.begin(); it1 != freeSegmentsList.end(); ++it1)
			{
				if ((it1->getLimit() >= it0->getLimit()) && (it1->getState() == Segment::free))
				{
					cout << "Hi" << endl;

					cout << it0->allocated << endl;

					//mark this segment as allocated
					it0->allocated = true;

					cout << it0->allocated << endl;

					//save this segment's id and name and base
					long segID = it1->getID();
					string segName = it1->getName();

					//set this segment as occupied
					it1->setState(Segment::occupied);
					//get size of free slot before occupation
					long sizeSegBeforeAlloc = it1->getLimit();
					//set size of occupied slot to be equal to the size of the segment being inserted
					long newSizeOfCurrentSegment = it0->getLimit();
					it1->setLimit(newSizeOfCurrentSegment);
					//calculate the base of the new free slot
					long newFreeSegmentBase = it1->getBase() + it1->getLimit();
					//create a new slot, set its base, set its limit and mark it as a free slot
					Segment newFreeSegment;
					long newFreeSegID = newFreeSegment.getID();
					newFreeSegment.setBase(newFreeSegmentBase);
					long newFreeSegSize = (sizeSegBeforeAlloc - it0->getLimit());
					newFreeSegment.setLimit(newFreeSegSize);
					newFreeSegment.setState(Segment::free);
					//insert the free slot right after the occupied slot
					//new iterator it pointing at the next position
					list<Segment>::iterator nextPositionFreeSegments = ++it1;
					it1--;
					if (nextPositionFreeSegments == freeSegmentsList.end())
					{
						freeSegmentsList.push_back(newFreeSegment);
					}
					else
					{
						freeSegmentsList.insert(nextPositionFreeSegments, newFreeSegment);
					}
					//updating real memorySegmentsList
					//00000000000000000000000000000000000
					list<Segment>::iterator it2;
					for (it2 = this->memorySegmentsList.begin(); it2 != this->memorySegmentsList.end(); ++it2)
					{
						if (it2->getID() == segID)
						{
							it2->setState(Segment::occupied);
							it2->setLimit(newSizeOfCurrentSegment);
							//insert the free slot right after the occupied slot
							it2++;
							if (it2 == memorySegmentsList.end())
							{
								this->memorySegmentsList.push_back(newFreeSegment);
								it2--;
								it2->setName("Free");
								it2->setBase(newFreeSegmentBase);
								it2->setLimit(newFreeSegSize);
							}
							else
							{
								this->memorySegmentsList.insert(it2, newFreeSegment);
								it2->setName("Free");
								it2->setBase(newFreeSegmentBase);
								it2->setLimit(newFreeSegSize);
							}
							break;
						}
					}
					
					//0000000000000000000000000000000000
					break;

				}
				else
				{
					list<Segment>::iterator lastElementTest;
					lastElementTest = ++it1;
					it1--;

					if (lastElementTest == freeSegmentsList.end())
					{
						return returnable;
					}
					else
						continue;
				}

			}
		}

		list<Segment>::iterator testIfDone;
		bool flagIsDone = true;

		for (testIfDone = process.segmentList.begin(); testIfDone != process.segmentList.end(); ++testIfDone)
		{
			if (testIfDone->allocated == false)
				flagIsDone = false;
		}
		if (flagIsDone)
			returnable = true;
		return returnable;
	}
	else return false;


	/*
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
					...........................................................................................
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
	*/
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


