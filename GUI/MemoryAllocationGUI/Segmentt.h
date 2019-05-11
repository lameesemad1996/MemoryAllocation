#pragma once
#include "Includess.h"

class Segment
{
private:
	static long SEGMENT_ID;
	long id;
	string name;
	long base;
	long limit;
	long storedBase;
	long size;
	bool allocated;

public:
	//static const string enumToString[3] = { "free", "occupied", "oldProcess" };
	enum segmentState { free, occupied, oldProcess } state;

	Segment();
	Segment(string name);
	Segment(string name, long size);
	Segment(string name, long base, long limit, segmentState state);

	~Segment();

	///set methods
	void setState(enum segmentState state);
	void setID(long id);
	void setBase(long base);
	void setStoredBase(long base);
	void setLimit(long limit);
	void setSize(long size);
	void setName(string name);

	///get methods
	long getID();
	long getLimit();
	long getBase();
	long getSize();
	long getStoredBase();
	string getName();
	segmentState getState();
	void markAsOldProcess(long base, long size);

	///other methods

	/**Sorts input list of segments by base address ascendingly.
	*/
	void static sortSegListBySize_ascending(list<Segment> &segmentList);
	/**Sorts input list of segments by size address descendingly.
	*/
	void static sortSegListBySize_descending(list<Segment> &segmentList);
	/**Sorts input list of segments by base address ascendingly.
	*/
	void static sortSegListByBaseAdd_ascending(list<Segment> &segmentList);
	/**Defines sorting function for ascending sorting by size.
	*/
	bool static ascendingSortBySize(const Segment &seg1, const Segment &seg2);
	/**Defines sorting function for descending sorting by size.
	*/
	bool static descendingSortBySize(const Segment &seg1, const Segment &seg2);
	/**Defines sorting function for ascending sorting by base address.
	*/
	bool static ascendingSortByBaseAdd(const Segment &seg1, const Segment &seg2);
	/**Given a list of segments having base and limits assigned, sorts a list of segments and merges between consecutive segments.
	*/
	list<Segment> static collect(list<Segment> &memorySegmentsList);
	/**Given a list of segments with assigned states, filters free segments into an output list of segments.
	*/
	list<Segment> static filterFree(list<Segment> segmentList);

	void static printSegList(list<Segment> segmentList);
	friend class Process;
	friend class Memory;
};

