#include "Includes.h"
#include "Process.h"
#include "Memory.h"
#include "Segment.h"

using namespace std;

/**Given the number of holes to be input, outputs a list of segmented holes.
*/
list<Segment> fillHoles(int inputHoleNo, long memSize, bool &invalidTotalHoleSizeFlag)
{
	list<Segment> returnable;
	long totalHoleSize = 0;
	if (inputHoleNo == 0)
	{
		return returnable;
	}
	for (int noOfHole = 0; noOfHole < inputHoleNo; noOfHole++)
	{
		std::cout << "Hole Base: ";
		long holebase;
		std::cin >> holebase;
		//test
		//cout << "/n==>"<< holebase << endl;
		std::cout << "Hole Limit: ";
		long holelimit;
		std::cin >> holelimit;
		totalHoleSize += holelimit;
		Segment newseg("Free", holebase, holelimit, Segment::free);
		returnable.push_back(newseg);
	}

	if (totalHoleSize > memSize)
	{
		cout << "This data is not valid." << endl;
		invalidTotalHoleSizeFlag = true;
	}

	return returnable;
}

/**Given a list of input segemented holes, outputs a memory with a filled up list of segments of Old Processes and Holes.
*/
Memory fillOldProcess(list<Segment> holesSegList, long memSize, bool &invalidTotalMemSizeFlag)
{
	Memory returnable;
	returnable.setSize(memSize);
	long ID = 0;

	//corner case: if no holes entered
	if (holesSegList.empty())
	{
		Segment newOldProSeg("Old Process", 0, memSize, Segment::oldProcess);
		returnable.memorySegmentsList.push_back(newOldProSeg);
		return returnable;
	}

	int lastAllocAdd = 0;
	list<Segment>::iterator it;

	Segment::sortSegListByBaseAdd_ascending(holesSegList);
	Segment::collect(holesSegList);

	long lastAddress = 0;

	for (it = holesSegList.begin(); it != holesSegList.end(); ++it)
	{
		Segment::sortSegListByBaseAdd_ascending(holesSegList);
		Segment::collect(holesSegList);

		//iterator to check if last element in list
		list<Segment>::iterator itLast = ++it;
		it--;

		//only the first iteration
		if (it == holesSegList.begin())
		{
			lastAllocAdd = 0;
			if (it->getBase() != 0)
			{
				Segment newOldProSeg("Old Process", 0, it->getBase(), Segment::oldProcess);
				lastAllocAdd = it->getBase() + it->getLimit();
				newOldProSeg.setID(ID);
				returnable.memorySegmentsList.push_back(newOldProSeg);
				it->setID(ID + 1);
				returnable.memorySegmentsList.push_back(*it);
				ID += 2;
			}
			else
			{
				it->setID(ID);
				returnable.memorySegmentsList.push_back(*it);
				ID++;
				lastAllocAdd = it->getLimit();
			}
		}
		//iterations other than the first one 
		else
		{
			//check if this is the last iteration to save the last address accessed
			list<Segment>::iterator newIt = ++it;
			it--;

			if (newIt == holesSegList.end())
			{
				lastAddress = it->getBase() + it->getLimit() - 1;
			}

			long currentBase = it->getBase();
			it--;
			long prevBase = it->getBase();
			long prevLimit = it->getLimit();
			it++;

			if (currentBase < (prevBase + prevLimit))
			{
				std::cout << "This is not a valid hole." << endl;
				continue;
			}

			if (currentBase != lastAllocAdd)
			{
				Segment newOldProSeg("Old Process", lastAllocAdd, currentBase - lastAllocAdd, Segment::oldProcess);
				newOldProSeg.setID(ID);
				returnable.memorySegmentsList.push_back(newOldProSeg);
				it->setID(ID + 1);
				returnable.memorySegmentsList.push_back(*it);
				ID += 2; 
				lastAllocAdd = it->getBase() + it->getLimit();
			}
			else
			{
				it->setID(ID);
				returnable.memorySegmentsList.push_back(*it);
				ID++;
				lastAllocAdd = it->getBase() + it->getLimit();
			}
		}
	}
	if (lastAddress >= memSize)
	{
		std::cout << "This memory is too small." << endl;
		invalidTotalMemSizeFlag = true;
	}
	else if (lastAllocAdd < memSize - 1)
	{
		Segment newOldProSeg("Old Process", lastAllocAdd, memSize - lastAllocAdd, Segment::oldProcess);
			//, memSize - lastAddress , Segment::oldProcess);
		newOldProSeg.setID(ID);
		returnable.memorySegmentsList.push_back(newOldProSeg);
	}
	return returnable;
}

int main()
{
	while (1)
	{
		bool invalidTotalHoleSizeFlag = false;
		bool invalidTotalMemSizeFlag = true;

		long memSize;
		cout << "Memory Size: ";
		cin >> memSize;
		int inputHoleNumber;
		cout << "The number of holes = ";
		cin >> inputHoleNumber;				//later dynamically allocated

		list<Segment> holesSegList = fillHoles(inputHoleNumber, memSize, invalidTotalHoleSizeFlag);
		Memory myMem = fillOldProcess(holesSegList, memSize, invalidTotalMemSizeFlag);
		
		myMem.printMemory();

		cout << "Processes to be allocated:" << endl;
		int inputProNumber;				//later dynamically allocated
		cout << "The number of processes = ";
		cin >> inputProNumber;

		for (int noOfPro = 0; noOfPro < inputProNumber; noOfPro++)
		{
			cout << "Process Name: ";
			string proname;
			cin >> proname;
			Process newProcess(proname);
			cout << "Number of Segments: ";
			int inputSegNumber;
			cin >> inputSegNumber;
			for (int noOfSeg = 0; noOfSeg < inputSegNumber; noOfSeg++)
			{
				cout << "Segment Name: ";
				string segname;
				cin >> segname;
				cout << "Segment Size: ";
				long segsize;
				cin >> segsize;

				Segment newseg(segname, segsize);
				newProcess.addSegment(newseg);
			}
			bool result = myMem.best_fit_allocate_check(newProcess);
			bool result2 = myMem.best_fit_allocate(newProcess);

			if (result == true)
				cout << "YAY" << endl;
			else
				cout << "NAY" << endl;

			if (result2 == true)
				cout << "YAY" << endl;
			else
				cout << "NAY" << endl;
		}

		myMem.printMemory();
	}

	return 0;
}