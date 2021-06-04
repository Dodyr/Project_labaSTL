#include <iostream>
#include <Windows.h>
#include <vector>
#include "Header1.h"

//функция предполагает, что список публикаций отсортирован по количеству страниц по возрастанию
void destroy_books(Library& library)
{
    TList list = library.getList();
    TIterator i = list.begin();
    int min_pages = (*i)->GetPage();
    while ((*i)->GetPage() == min_pages && i != list.end())
    {
        Book* book = dynamic_cast<Book*>(*i);
        if (book&& book->getBinding() == "softcover")
        {
            i = list.erase(i);
        }
        else
            i++;
    }
    library.setList(list);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::ifstream fin("lbr.txt");
    if (fin.is_open())
    {
        Library library(fin);
        library.sort_();
        destroy_books(library);
        library.print();
    }
    fin.close();
	return 0;
}