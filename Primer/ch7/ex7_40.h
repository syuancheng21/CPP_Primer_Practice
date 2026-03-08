#ifndef SYUAN_EX7_40_H
#define SYUAN_EX7_40_H


#include <string>
#include <istream>

class Book {
private:
    unsigned isbn;
    std::string name;
    std::string author;
    std::string pub_date;
public:
    Book()=default;
    Book(unsigned isbn, const std::string& name, const std::string& author, const std::string& date)
        : isbn(isbn), name(name), author(author), pub_date(date) {}

    explicit Book(std::istream& is) { //TODO: why use explicit here?
        is >> isbn >> name >> author >> pub_date;
    }

}

#endif // SYUAN_EX7_40_H