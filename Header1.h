#pragma once

#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <Windows.h>
#include <list>

#include "Header2.h"

using TList = std::list<Publication*>;
using TIterator = std::list<Publication*>::iterator;

class Library
{
private:
	std::string name;
	TList list_publications;
public:
	Library(std::ifstream& fin);
	~Library();
	TList getList();
	void setList(TList list);
	void print();
	void sort_();
};
