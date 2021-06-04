#include "Header1.h"

Publication::Publication(std::string Name, int page, std::string publishing_house)
{
	this->name = name;
	this->page = page;
	this->publishing_house = publishing_house;
}

int Publication::GetPage()
{
	return page;
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
	std::cout << name << std::endl;
}

bool Publication::operator()(Publication* p1, Publication* p2) const
{
	return p1->Compare(p2) < 0;
}

void Book::print()
{
	Publication::print();
	std::cout << author << ' ' << std::endl;
	std::cout << "\n---------------------------\n";
}

std::string Book::getAuthor()
{
	return author;
}

void Journal::print()
{
	Publication::print();
	std::cout << ' ' << number << ' ' << year;
	std::cout << "\n--------------------\n";
}