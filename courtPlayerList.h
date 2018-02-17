#pragma once
#include "circularLinkedList.h"
#include "courtPlayer.h"
#include <cassert>

class courtPlayerList : public circularLinkedList<courtPlayer>
{
public:
	courtPlayerList();
	~courtPlayerList();
	CirnodeType<courtPlayer> pointToFront();

private:

};

CirnodeType<courtPlayer> courtPlayerList::pointToFront()
{
	assert(first != NULL);
	return *first;
}

courtPlayerList::courtPlayerList()
{
}

courtPlayerList::~courtPlayerList()
{
}