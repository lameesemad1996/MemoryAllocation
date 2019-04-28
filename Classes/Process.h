#pragma once
#include "Includes.h"
#include "Segment.h"

class Process
{
private:
	static long PROCESS_ID;
	list<Segment> segmentList;
	enum processState {waiting, running} state;
	long id;
	string name;
public:
	Process(string name);
	Process(string name, Segment segment);
	~Process();

	//set methods
	void setState(enum processState state);
	void setID(long id);
	void setName(string name);

	//get methods
	long getID();
	string getName();
	processState getState();

	//other functions
	void addSegment(Segment segment);

	friend class Memory;
};

