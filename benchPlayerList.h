#pragma once
#include <iostream>
#include <cassert>
#include "doublyLinkedList.h"
#include "benchPlayer.h"

class benchPlayerList:public doublyLinkedList<benchPlayer>
{
public:
	benchPlayerList();
	~benchPlayerList();
	nodeType<benchPlayer> pointToFront();

private:

};


nodeType<benchPlayer> benchPlayerList::pointToFront()
{
	assert(first != NULL);
	return *first;
}



benchPlayerList::benchPlayerList()
{
}

benchPlayerList::~benchPlayerList()
{
}