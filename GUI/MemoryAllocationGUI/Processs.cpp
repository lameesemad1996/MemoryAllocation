#include "Processs.h"
#include "Includess.h"

long Process::PROCESS_ID;

Process::Process(string name)
{
	setID(PROCESS_ID);
	PROCESS_ID++;
	setName(name);
}

Process::Process(string name, Segment segment)
{
	setID(PROCESS_ID);
	PROCESS_ID++;
	setName(name);
	addSegment(segment);
}

Process::~Process()
{
}

//set methods
void Process::setState(enum processState state)
{
	this->state = state;
}
void Process::setID(long id)
{
	this->id = id;
}
void Process::setName(string name)
{
	this->name = name;
}

//get methods
long Process::getID()
{
	return id;
}
string Process::getName()
{
	return name;
}
Process::processState Process::getState()
{
	return state;
}

//other functions
void Process::addSegment(Segment segment)
{
	segmentList.push_back(segment);
}
