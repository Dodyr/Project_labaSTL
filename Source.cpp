#include <iostream>
#include <Windows.h>
#include <vector>
#include <list>
#include <fstream>

#include "Header1.h"
#include "Header2.h"

void destroy_books(Library& library)
{
    TList list = library.getList();
    for (TIterator i = list.begin(); i != list.end();)
    {

        Book* book = dynamic_cast<Book*>(*i);
        if (book)
        {
            if (book->getBinding() == "softcover")
                i = list.erase(i);
            else
                i++;
        }
        else
            i++;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::ifstream fin("lbr.txt");
    if (fin.is_open())
    {
        Library library(fin);
        library.sort_();
        //destroy_books(library);
        library.print();
    }
    fin.close();
	return 0;
}