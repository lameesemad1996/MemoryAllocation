#pragma once
#include "Includess.h"
#include "Segmentt.h"

class Process
{
private:
	static long PROCESS_ID;
	list<Segment> segmentList;
	enum processState {waiting, running} state;
    long noOfSeg; //for gui usage
	long id;
	string name;
	bool allocated;
public:
	Process(string name);
	Process(string name, Segment segment);
	~Process();

	//set methods
	void setState(enum processState state);
	void setID(long id);
	void setName(string name);
    void setNoOfSeg(long noOfSeg);

	//get methods
	long getID();
	string getName();
	processState getState();
    long getNoOfSeg();

	//other functions

	/**Pushes a segments (adds a segment) to this process's segmentList.
	*/
	void addSegment(Segment segment);

	friend class Memory;
};

