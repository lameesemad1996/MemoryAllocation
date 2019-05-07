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

	Memory();
	Memory(long size);
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

	/**Given a segmented process, checks that allocation can happen in this Memory object. Returns true
	*if allocation can occur and false if allocation cannot occur.
	*/
	bool first_fit_allocate_check(Process process);
	/**Given a segmented process, checks that allocation can happen in this Memory object and allocates the object. Returns true
	*if allocation successfuly occured and false if allocation cannot occur.
	*Assigns the base what which a segment was allocated in the memory to the Segment attribute storedBase.
	*/
	bool first_fit_allocate(Process &process);
	/**Prints contents of this memory.
	*/
	void printMemory();
	/**Pushes a segments (adds a segment) to this memory's memorySegmentsList.
	*/
	void addSegment(Segment segment);
};