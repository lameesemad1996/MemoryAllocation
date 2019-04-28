#pragma once
#include "Includes.h"
#include "Process.h"
#include "Segment.h"

class Memory
{
private:
	long size;
	long freeSize;
	long allocatedSize;
public:
	list<Process> allocatedProcessesList;
	list<Segment> freeSegmentsList;
	list<Segment> allocatedSegmentsList;
	list<Segment> memorySegmentsList;

	Memory(long size, list<Segment> allocatedSegmentsList, list<Segment> freeSegmentsList);
	~Memory();

	//set methods
	void setSize(long size);
	void setFreeSize(long size);
	void setAllocatedSize(long size);

	//get methods
	long getSize();
	long getFreeSize();
	long getAllocatedSize();


	//other methods
	void allocateProcess(Process process);
	bool first_fit_allocate_check(Process process);
	bool first_fit_allocate(Process process);
};
