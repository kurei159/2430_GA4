#pragma once
#include "Player.h"
#include "doublyLinkedList.h"
class benchPlayer: public Player
{
public:
	char status = 'B';
	const benchPlayer& operator=(const Player &); //Operator overloading
	
};



const benchPlayer& benchPlayer::operator=(const Player &obj)
{
	this->number = obj.number;
	this->age = obj.age;
	this->min = obj.min;
	return *this;
}