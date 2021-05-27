#include <iostream>

#include "Chrono.h"
#include "Book.h"
#include "Invalid.h"

int main()
{
    Library::Lib mainLib{ "Salil's Lib" };

    /*Library::Book 
        bk{ "3497253-2-B-7",
            "Chronicles of the Wild",
            "Salil Mittal",
            Chrono::Date{1970, Chrono::Month::Mar, 1},
            Library::Genre::Fiction,
            false };

    Library::Book
        bk2{ "3497253-2-B-1",
            "Chronicles of the Wild",
            "Salil Mittal",
            Chrono::Date{1970, Chrono::Month::Mar, 1},
            Library::Genre::Fiction,
            false };*/
    try {
        Chrono::Date dt{ 1970, Chrono::Month::Mar, 1 };
        Library::Patron pt{ "Salil", "1231231230" };
        mainLib.addPatron(pt.getName(), pt.getLibCardNum());
        mainLib.addBook("3497253-2-B-1",
                        "Chronicles of the Wild",
                        "Salil Mittal",
                        dt,
                        Library::Genre::Fiction);
        mainLib.addBook("3497253-2-B-2",
            "Chronicles of the Wild 2",
            "Salil Mittal",
            dt,
            Library::Genre::Fiction);
        mainLib.listBooks();
        mainLib.checkout(pt.getLibCardNum(), 0, dt);
        mainLib.checkout(pt.getLibCardNum(), 1, dt);
        mainLib.listBooks();
    } catch (Invalid e) {
        std::cerr << e.what();
    }
}