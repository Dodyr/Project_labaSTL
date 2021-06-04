#include "Header1.h"

Publication::Publication(std::string name, int page, std::string publishing_house)
{
	this->name = name;
	this->page = page;
	this->publishing_house = publishing_house;
}

int Publication::GetPage()
{
	return page;
}

std::string Publication::getName()
{
	return name;
}

int Publication::Compare(Publication* p)
{
	int res = -1;
	if (p->page == page)
		res = 0;
	else
		if (page > p->page)
			res = 1;
	return res;
}

void Publication::print()
{
	std::cout << name << ' ' <<  page << ' ' << publishing_house <<std::endl;
}

bool Publication::operator()(Publication* p1, Publication* p2) const
{
	return p1->Compare(p2) < 0;
}

void Book::print()
{
	Publication::print();
	std::cout << author << ' ' << genre << ' ' << binding << std::endl;
	std::cout << "\n---------------------------\n";
}

std::string Book::getBinding()
{
	return binding;
}

void Journal::print()
{
	Publication::print();
	std::cout << ' ' << number << ' ' << year << ' ' << web_site;
	std::cout << "\n--------------------\n";
}