#pragma once

#ifndef SEQUENCECONTAINERS_H
#define SEQUENCECONTAINERS_H

#include "stdafx.h"
#include<iostream>
#include<string>
#include<array>	
#include<vector>
#include<deque>
#include<list>
#include<forward_list>

class SequenceContainers {

public:


	int pickSCIterType();
	void populateArray();
	void processArray(array<char, 20>);
	void processVector(vector<char>);
	void processDeque(deque<char>);
	void processList(list<char>);
	void populateFList();
	void processForwardList(forward_list<char>);


};





#endif // !SEQUENCECONTAINERS_H
