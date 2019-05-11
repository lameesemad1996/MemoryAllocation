#pragma once
#include "Includess.h"
#include "Processs.h"
#include "Segmentt.h"

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

	/**Given a segmented process, checks that first fit allocation can happen in this Memory object. Returns true
	*if first fit allocation can occur and false if first allocation cannot occur.
	*/
	bool first_fit_allocate_check(Process process);
	/**Given a segmented process, checks that first fit allocation can happen in this Memory object and allocates the object. Returns true
	*if first fit allocation successfuly occured and false if first fit allocation cannot occur.
	*Assigns the base what which a segment was allocated in the memory to the Segment attribute storedBase.
	*/
	bool first_fit_allocate(Process &process);
	/**Prints contents of this memory.
	*/
	void printMemory();
	/**Pushes a segments (adds a segment) to this memory's memorySegmentsList.
	*/
	void addSegment(Segment segment);
	/**Given a segmented process, checks that best fit allocation can happen in this Memory object. Returns true
	*if best fit allocation can occur and false if best fit allocation cannot occur.
	*/
	bool best_fit_allocate_check(Process process);
	/**Given a segmented process, checks that best fit allocation can happen in this Memory object and allocates the object. Returns true
	*if best fit allocation successfuly occured and false if best fit allocation cannot occur.
	*Assigns the base what which a segment was allocated in the memory to the Segment attribute storedBase.
	*/
	bool best_fit_allocate(Process &process);
	/**Given a segmented process, checks that worst fit allocation can happen in this Memory object. Returns true
	*if worst fit allocation can occur and false if worst fit allocation cannot occur.
	*/
	bool worst_fit_allocate_check(Process process);
	/**Given a segmented process, checks that worst fit allocation can happen in this Memory object and allocates the object. Returns true
	*if worst fit allocation successfuly occured and false if worst fit allocation cannot occur.
	*Assigns the base what which a segment was allocated in the memory to the Segment attribute storedBase.
	*/
	bool worst_fit_allocate(Process &process);
};