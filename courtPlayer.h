#pragma once
#include "Player.h"

class courtPlayer: public Player
{
public:
	char status = 'C';
	const courtPlayer& operator=(const Player &obj); //Operator overloading

};



const courtPlayer& courtPlayer::operator=(const Player &obj)
{
	this->number = obj.number;
	this->age = obj.age;
	this->min = obj.min;
	return *this;
}