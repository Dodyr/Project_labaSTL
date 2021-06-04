#pragma once

#include <iostream>
#include <string>

class Publication
{
private:
	std::string name;
	int page;
	std::string publishing_house;
public:
	Publication(std::string name, int page, std::string publishing_house);
	int GetPage();
	std::string getName();
	int Compare(Publication* p);
	virtual void print();
	bool operator()(Publication* p1, Publication* p2) const;
};

class Book : public Publication
{
private:
	std::string author;
	std::string genre;
	std::string binding;
public:
	Book(std::string name, int page, std::string publishing_house, std::string author, std::string genre, std::string binding) :
		Publication(name, page, publishing_house), author(author), genre(genre), binding(binding) {};
	virtual void print();
	std::string getBinding();
};

class Journal :public Publication
{
private:
	int number;
	int year;
	std::string web_site;
public:
	Journal(std::string name, int page, std::string publishing_house, int number, int year, std::string  web_site) :
		Publication(name, page, publishing_house), number(number), year(year), web_site(web_site) {};
	virtual void print();

};

class Destroyer
{
public:
	void operator()(Publication* object) const
	{
		delete object;
	}
};
