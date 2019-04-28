#pragma once
#include "Includes.h"

class Segment
{
private:
	enum segmentState {free, occupied, oldProcess} state;
	long id;
	string name;
	long base;
	long limit;

public:
	Segment();
	~Segment();

	//set methods
	void setState(enum segmentState state);
	void setID(long id);
	void setBase(long base);
	void setLimit(long limit);
	void setName(string name);

	//get methods
	long getID();
	long getLimit();
	long getBase();
	string getName();
	segmentState getState();
	void markAsOldProcess(long base, long size);

	//other methods
	void static sortSegList_ascending(list<Segment> segmentList);
	void static sortSegList_descending(list<Segment> segmentList);
	bool static ascendingSortBySize(const Segment &seg1, const Segment &seg2);
	bool static descendingSortBySize(const Segment &seg1, const Segment &seg2);
	list<Segment> static assignFree(list<Segment> segmentList);

	friend class Process;
	friend class Memory;
};

