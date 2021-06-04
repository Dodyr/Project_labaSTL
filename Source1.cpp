#include "Header1.h"

Library::Library(std::ifstream& fin)
{
	std::getline(fin, name);
	while (!fin.eof())
	{
		char ch = fin.get(); 
		fin.ignore();
		std::string name;
		int page;
		std::string publishing_house;
		getline(fin, name);
		fin >> page;
		fin.ignore();
		getline(fin, publishing_house);
		Publication* new_public;
		switch (ch)
		{
		case 'b':
		{
			std::string author;
			std::string genre;
			std::string binding;
			fin >> author >> genre >> binding;
			fin.ignore();
			new_public = new Book(name, page, publishing_house, author, genre, binding);
			break;
		}
		case 'j':
		{
			int number;
			int year;
			std::string web_site;
			fin >> number >> year >> web_site;
			fin.ignore();
			new_public = new Journal(name, page, publishing_house, number, year, web_site);
			break;
		}
		}
		fin.ignore();
		list_publications.push_back(new_public);
	}
}


Library::~Library()
{
	std::for_each(list_publications.begin(), list_publications.end(), Destroyer());
}

TList Library::getList()
{
	return list_publications;
}

void Library::setList(TList list)
{
	list_publications = list;
}

void Library::print()
{
	std::cout << name << '\n';
	std::cout << "==============================\n";
	for (TIterator it = list_publications.begin(); it != list_publications.end(); it++)
	{
		(*it)->print();
	}
}

void Library::sort_()
{
	auto cmp = [](Publication* a, Publication* b)->bool {return a->GetPage() < b->GetPage(); };
	list_publications.sort(cmp);
}
