#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "Invalid.h"
#include "Book.h"
#include "Chrono.h"

namespace Library {
	bool isNumeric(std::string str) {
		for (char x : str) if (!isdigit(x)) return false;
		return true;
	}

	bool vecContains(const std::vector<char>& v, const char& val) {
		if (std::find(v.begin(), v.end(), val) != v.end()) return true;
		return false;
	}

	bool Book::checkISBN(std::string ISBN) {
		// n-x-x-x where n is int and x is digit or letter
	
		if (ISBN.size() == 13) {
			// get first 4 digits
			std::string intID = ISBN.substr(0, 7);
			if (isNumeric(intID)) {
				if (ISBN[7] == '-' && ISBN[9] == '-' && ISBN[11] == '-') {
					std::vector<char> validTokens = {
						'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
						'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
						's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
						'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 
						'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
						'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
						'0', '1', '2', '3', '4', '5', '6', '7', '8',
						'9'
					};
					if (vecContains(validTokens, ISBN[8])
						&& vecContains(validTokens, ISBN[10])
						&& vecContains(validTokens, ISBN[12])) {
						return true;
					}
				}
			}
		}

		return false;
	}

	Book::Book(std::string ISBN_tmp, std::string title_tmp, std::string author_tmp, Chrono::Date copyrightDate_tmp,
			   Genre gnr, bool checkedOut_tmp)
		: ISBN{ ISBN_tmp }, title{ title_tmp }, author{ author_tmp },
		copyrightDate{ copyrightDate_tmp },
		genre{gnr},
		checkedOut{ checkedOut_tmp }
	{
		// Check ISBN
		if (!checkISBN(ISBN)) throw Invalid{ "Invalid ISBN no." };
		if (title.size() > 300) throw Invalid{ "Title Length Exceeds 300 characters" };
		if (author.size() > 500) throw Invalid{ "Author Name Exceeds 500 characters" };
	}

	Book::Book(std::string ISBN_tmp, std::string title_tmp, std::string author_tmp, Chrono::Date copyrightDate_tmp,
		Genre gnr)
		: ISBN{ ISBN_tmp }, title{ title_tmp }, author{ author_tmp },
		copyrightDate{ copyrightDate_tmp },
		genre{ gnr }
	{
		// Check ISBN
		if (!checkISBN(ISBN)) throw Invalid{ "Invalid ISBN no." };
		if (title.size() > 300) throw Invalid{ "Title Length Exceeds 300 characters" };
		if (author.size() > 500) throw Invalid{ "Author Name Exceeds 500 characters" };
	}

	std::string Book::getISBN() const {return ISBN;}
	std::string Book::getTitle() const { return title; }
	std::string Book::getAuthor() const { return author; }
	Genre Book::getGenre() const { return genre; }
	int Book::getBookId() const { return libraryId; }

	Chrono::Date Book::getCopyrightDate() const { return copyrightDate; }
	bool Book::isCheckedOut() const { return checkedOut; }

	void Book::checkout() {
		if (!checkedOut) checkedOut = true;
		else throw Invalid{"Book Already Checked Out"};
	}

	bool operator==(const Book& a, const Book& b) {
		return a.getISBN() == b.getISBN();
	}

	bool operator!=(const Book& a, const Book& b) {
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {
		return os << "Title: " << book.getTitle() << "\n" <<
			"Author: " << book.getAuthor() << "\n" <<
			"ISBN: " << book.getISBN() << "\n";
	}

	/**
	 * Patron Class
	 * 
	 */
	Patron::Patron(std::string name, std::string libCardNum) : name{ name }, libCardNum{ libCardNum } {
		if (name.length() > 300) throw Invalid{ "Name is too long" };
		if (libCardNum.length() != 10) throw Invalid{ "Invalid card number" };
	}

	/**
	 * Lib Class
	 * 
	 */
	Lib::Lib(std::string libName) : libName{ libName } {}

	void Lib::listBooks() {
		for (int i = 0; i < books.size(); i++) {
			const Book bk = books[i];
			std::cout << "[" << i << "]" << " " << bk.getTitle() << "\n";
		}
	}

	void Lib::addBook(std::string ISBN, std::string title, std::string author, Chrono::Date copyrightDate, Genre genre) {
		Book bk{ ISBN, title, author, copyrightDate, genre };
		bk.setLibId(books.size());
		books.push_back(bk);
	}

	bool Lib::patronExists(std::string cardNum) {
		Patron patron{ "name", cardNum };
		return std::any_of(patrons.cbegin(), patrons.cend(), [&patron](const Patron& o) {
			return o.getLibCardNum() == patron.getLibCardNum(); 
		});
	}

	void Lib::addPatron(std::string name, std::string libCardNum) {
		Patron patron{ name, libCardNum };
		
		if (patronExists(libCardNum)) throw Invalid{ "Patron already added." };
		patrons.push_back(patron);
	}

	void Lib::checkout(std::string cardNum, int bookId, Chrono::Date dt) {
		if (!patronExists(cardNum)) throw Invalid{ "Invalid card id." };
	
		std::string patronId = "";
		for (int i = 0; i < patrons.size(); i++) {
			const Patron patron_tmp = patrons[i];
			if (patron_tmp.getLibCardNum() == cardNum) patronId = patron_tmp.getLibCardNum();
		}

		// if book exists by id
		bool bookExists = false;
		int i = 0;
		for (Book book : books) {
			if (book.getBookId() == bookId) {
				bookExists = true;
				books.erase(books.begin() + i);
				break;
			}
			i++;
		}

		// If owes book
		for (Transaction t : transactions) {
			if (t.isReturned == false) throw Invalid{ "Pending returns" };
		}

		if (!bookExists) throw Invalid{ "Book not found" };
		
		Transaction transaction{ bookId, patronId, dt };
		transactions.push_back(transaction);
	}

	// set library id for each book
	void Book::setLibId(int n) {libraryId = n;}
};