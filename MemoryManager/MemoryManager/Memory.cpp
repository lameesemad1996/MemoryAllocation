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
		if (it0->allocated == true)
			continue;

		for (it1 = freeSegmentsListCopy.begin(); it1 != freeSegmentsListCopy.end(); ++it1)
		{
			if ((it1->getLimit() >= it0->getSize()) && (it1->getState() == Segment::free))
			{
				//mark this segment as allocated
				it0->allocated = true;
				//set this segment as occupied
				it1->setState(Segment::occupied);
				//get size of free slot before occupation
				long sizeSegBeforeAlloc = it1->getLimit();
				//set size of occupied slot to be equal to the size of the segment being inserted
				it1->setLimit(it0->getSize());
				//calculate the base of the new free slot
				long newSegmentBase = it1->getBase() + it1->getLimit();
				//create a new slot, set its base, set its limit and mark it as a free slot
				Segment newFreeSegment;
				newFreeSegment.setBase(newSegmentBase);
				newFreeSegment.setLimit((sizeSegBeforeAlloc - it0->getSize()));
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
				freeSegmentsListCopy = Segment::filterFree(freeSegmentsListCopy);
				Segment::collect(freeSegmentsListCopy);
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

		list<Segment> freeSegments = Segment::filterFree(memorySegmentsList);

		//corner cases
		if (process.segmentList.empty())
		{
			cout << "Process is empty." << endl;
			return returnable;

		}

		if (freeSegments.empty())
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

			for (it1 = freeSegments.begin(); it1 != freeSegments.end(); ++it1)
			{
				if ((it1->getLimit() >= it0->getSize()) && (it1->getState() == Segment::free))
				{
					//mark this segment as allocated
					it0->allocated = true;
					//save this segment's id and name and base
					long segID = it1->getID();
					//set this segment as occupied
					it1->setState(Segment::occupied);
					//new segment name is name of process segment
					string newSegName = it0->getName();
					//get size of free slot before occupation
					long sizeSegBeforeAlloc = it1->getLimit();
					//set size of occupied slot to be equal to the size of the segment being inserted
					long newSizeOfCurrentSegment = it0->getSize();
					it1->setLimit(newSizeOfCurrentSegment);
					//calculate the base of the new free slot
					long newFreeSegmentBase = it1->getBase() + it1->getLimit();

					//create a new slot, set its base, set its limit and mark it as a free slot
					Segment newFreeSegment;
					long newFreeSegID = newFreeSegment.getID();
					newFreeSegment.setBase(newFreeSegmentBase);
					long newFreeSegSize = (sizeSegBeforeAlloc - it0->getSize());
					newFreeSegment.setLimit(newFreeSegSize);
					newFreeSegment.setState(Segment::free);
					//insert the free slot right after the occupied slot
					//new iterator it pointing at the next position
					list<Segment>::iterator nextPositionFreeSegments = ++it1;
					it1--;
					if (nextPositionFreeSegments == freeSegments.end())
					{
						freeSegments.push_back(newFreeSegment);
					}
					else
					{
						freeSegments.insert(nextPositionFreeSegments, newFreeSegment);
					}
					//updating real memorySegmentsList
					list<Segment>::iterator it2;
					for (it2 = this->memorySegmentsList.begin(); it2 != this->memorySegmentsList.end(); ++it2)
					{
						if (it2->getID() == segID)
						{
							it2->setName(newSegName);
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
								it2--; //test line: ma3rafsh leh sha8al fa bas hasibo lol
								it2->setName("Free");
								it2->setBase(newFreeSegmentBase);
								it2->setLimit(newFreeSegSize);
							}
							freeSegments = Segment::filterFree(memorySegmentsList);
							break;
						}
					}
					freeSegments = Segment::filterFree(memorySegmentsList);
					Segment::collect(freeSegments);
					break;
				}
				else
				{
					list<Segment>::iterator lastElementTest;
					lastElementTest = ++it1;
					it1--;

					if (lastElementTest == freeSegments.end())
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
}

bool Memory::best_fit_allocate_check(Process process)
{
	bool returnable = false;

	list<Segment> freeSegmentsList = Segment::filterFree(memorySegmentsList);
	list<Segment> freeSegmentsListCopy;
	freeSegmentsListCopy.assign(freeSegmentsList.begin(), freeSegmentsList.end());
	Segment::sortSegListBySize_ascending(freeSegmentsListCopy);

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
		if (it0->allocated == true)
			continue;

		Segment::sortSegListBySize_ascending(freeSegmentsListCopy);

		for (it1 = freeSegmentsListCopy.begin(); it1 != freeSegmentsListCopy.end(); ++it1)
		{
			if ((it1->getLimit() >= it0->getSize()) && (it1->getState() == Segment::free))
			{
				//mark this segment as allocated
				it0->allocated = true;
				//set this segment as occupied
				it1->setState(Segment::occupied);
				//get size of free slot before occupation
				long sizeSegBeforeAlloc = it1->getLimit();
				//set size of occupied slot to be equal to the size of the segment being inserted
				it1->setLimit(it0->getSize());
				//calculate the base of the new free slot
				long newSegmentBase = it1->getBase() + it1->getLimit();
				//create a new slot, set its base, set its limit and mark it as a free slot
				Segment newFreeSegment;
				newFreeSegment.setBase(newSegmentBase);
				newFreeSegment.setLimit((sizeSegBeforeAlloc - it0->getSize()));
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
				freeSegmentsListCopy = Segment::filterFree(freeSegmentsListCopy);
				Segment::sortSegListBySize_ascending(freeSegmentsListCopy);
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
bool Memory::best_fit_allocate(Process &process)
{
	bool canBeAllocated = best_fit_allocate_check(process);
	if (canBeAllocated)
	{

		bool returnable = false;

		list<Segment> freeSegments = Segment::filterFree(memorySegmentsList);
		Segment::sortSegListBySize_ascending(freeSegments);

		//corner cases
		if (process.segmentList.empty())
		{
			cout << "Process is empty." << endl;
			return returnable;

		}

		if (freeSegments.empty())
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

			for (it1 = freeSegments.begin(); it1 != freeSegments.end(); ++it1)
			{
				if ((it1->getLimit() >= it0->getSize()) && (it1->getState() == Segment::free))
				{
					//mark this segment as allocated
					it0->allocated = true;
					//save this segment's id and name and base
					long segID = it1->getID();
					//set this segment as occupied
					it1->setState(Segment::occupied);
					//new segment name is name of process segment
					string newSegName = it0->getName();
					//get size of free slot before occupation
					long sizeSegBeforeAlloc = it1->getLimit();
					//set size of occupied slot to be equal to the size of the segment being inserted
					long newSizeOfCurrentSegment = it0->getSize();
					it1->setLimit(newSizeOfCurrentSegment);
					//calculate the base of the new free slot
					long newFreeSegmentBase = it1->getBase() + it1->getLimit();

					//create a new slot, set its base, set its limit and mark it as a free slot
					Segment newFreeSegment;
					long newFreeSegID = newFreeSegment.getID();
					newFreeSegment.setBase(newFreeSegmentBase);
					long newFreeSegSize = (sizeSegBeforeAlloc - it0->getSize());
					newFreeSegment.setLimit(newFreeSegSize);
					newFreeSegment.setState(Segment::free);
					//insert the free slot right after the occupied slot
					//new iterator it pointing at the next position
					list<Segment>::iterator nextPositionFreeSegments = ++it1;
					it1--;
					if (nextPositionFreeSegments == freeSegments.end())
					{
						freeSegments.push_back(newFreeSegment);
						Segment::sortSegListBySize_ascending(freeSegments);
					}
					else
					{
						freeSegments.insert(nextPositionFreeSegments, newFreeSegment);
						Segment::sortSegListBySize_ascending(freeSegments);
					}
					//updating real memorySegmentsList
					list<Segment>::iterator it2;
					for (it2 = this->memorySegmentsList.begin(); it2 != this->memorySegmentsList.end(); ++it2)
					{
						if (it2->getID() == segID)
						{
							it2->setName(newSegName);
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
								it2->setState(Segment::free);
							}
							else if(newFreeSegSize != 0)
							{
								this->memorySegmentsList.insert(it2, newFreeSegment);
								it2--; //test line: ma3rafsh leh sha8al fa bas hasibo lol
								it2->setName("Free");
								it2->setBase(newFreeSegmentBase);
								it2->setLimit(newFreeSegSize);
								it2->setState(Segment::free);
							}
							freeSegments = Segment::filterFree(memorySegmentsList);
							Segment::sortSegListBySize_ascending(freeSegments);

							break;
						}
					}
					break;
				}
				else
				{
					list<Segment>::iterator lastElementTest;
					lastElementTest = ++it1;
					it1--;

					if (lastElementTest == freeSegments.end())
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
}

bool Memory::worst_fit_allocate_check(Process process)
{
	bool returnable = false;

	list<Segment> freeSegmentsList = Segment::filterFree(memorySegmentsList);
	list<Segment> freeSegmentsListCopy;
	freeSegmentsListCopy.assign(freeSegmentsList.begin(), freeSegmentsList.end());
	Segment::sortSegListBySize_descending(freeSegmentsListCopy);

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
		if (it0->allocated == true)
			continue;

		Segment::sortSegListBySize_descending(freeSegmentsListCopy);

		for (it1 = freeSegmentsListCopy.begin(); it1 != freeSegmentsListCopy.end(); ++it1)
		{
			if ((it1->getLimit() >= it0->getSize()) && (it1->getState() == Segment::free))
			{
				//mark this segment as allocated
				it0->allocated = true;
				//set this segment as occupied
				it1->setState(Segment::occupied);
				//get size of free slot before occupation
				long sizeSegBeforeAlloc = it1->getLimit();
				//set size of occupied slot to be equal to the size of the segment being inserted
				it1->setLimit(it0->getSize());
				//calculate the base of the new free slot
				long newSegmentBase = it1->getBase() + it1->getLimit();
				//create a new slot, set its base, set its limit and mark it as a free slot
				Segment newFreeSegment;
				newFreeSegment.setBase(newSegmentBase);
				newFreeSegment.setLimit((sizeSegBeforeAlloc - it0->getSize()));
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
				freeSegmentsListCopy = Segment::filterFree(freeSegmentsListCopy);
				Segment::sortSegListBySize_descending(freeSegmentsListCopy);
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
bool Memory::worst_fit_allocate(Process &process)
{
	bool canBeAllocated = best_fit_allocate_check(process);
	if (canBeAllocated)
	{

		bool returnable = false;

		list<Segment> freeSegments = Segment::filterFree(memorySegmentsList);
		Segment::sortSegListBySize_descending(freeSegments);

		//corner cases
		if (process.segmentList.empty())
		{
			cout << "Process is empty." << endl;
			return returnable;

		}

		if (freeSegments.empty())
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

			for (it1 = freeSegments.begin(); it1 != freeSegments.end(); ++it1)
			{
				if ((it1->getLimit() >= it0->getSize()) && (it1->getState() == Segment::free))
				{
					//mark this segment as allocated
					it0->allocated = true;
					//save this segment's id and name and base
					long segID = it1->getID();
					//set this segment as occupied
					it1->setState(Segment::occupied);
					//new segment name is name of process segment
					string newSegName = it0->getName();
					//get size of free slot before occupation
					long sizeSegBeforeAlloc = it1->getLimit();
					//set size of occupied slot to be equal to the size of the segment being inserted
					long newSizeOfCurrentSegment = it0->getSize();
					it1->setLimit(newSizeOfCurrentSegment);
					//calculate the base of the new free slot
					long newFreeSegmentBase = it1->getBase() + it1->getLimit();

					//create a new slot, set its base, set its limit and mark it as a free slot
					Segment newFreeSegment;
					long newFreeSegID = newFreeSegment.getID();
					newFreeSegment.setBase(newFreeSegmentBase);
					long newFreeSegSize = (sizeSegBeforeAlloc - it0->getSize());
					newFreeSegment.setLimit(newFreeSegSize);
					newFreeSegment.setState(Segment::free);
					//insert the free slot right after the occupied slot
					//new iterator it pointing at the next position
					list<Segment>::iterator nextPositionFreeSegments = ++it1;
					it1--;
					if (nextPositionFreeSegments == freeSegments.end())
					{
						freeSegments.push_back(newFreeSegment);
						Segment::sortSegListBySize_descending(freeSegments);
					}
					else
					{
						freeSegments.insert(nextPositionFreeSegments, newFreeSegment);
						Segment::sortSegListBySize_descending(freeSegments);
					}
					//updating real memorySegmentsList
					list<Segment>::iterator it2;
					for (it2 = this->memorySegmentsList.begin(); it2 != this->memorySegmentsList.end(); ++it2)
					{
						if (it2->getID() == segID)
						{
							it2->setName(newSegName);
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
								it2->setState(Segment::free);
							}
							else if (newFreeSegSize != 0)
							{
								this->memorySegmentsList.insert(it2, newFreeSegment);
								it2--; //test line: ma3rafsh leh sha8al fa bas hasibo lol
								it2->setName("Free");
								it2->setBase(newFreeSegmentBase);
								it2->setLimit(newFreeSegSize);
								it2->setState(Segment::free);
							}
							freeSegments = Segment::filterFree(memorySegmentsList);
							Segment::sortSegListBySize_descending(freeSegments);

							break;
						}
					}
					break;
				}
				else
				{
					list<Segment>::iterator lastElementTest;
					lastElementTest = ++it1;
					it1--;

					if (lastElementTest == freeSegments.end())
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


