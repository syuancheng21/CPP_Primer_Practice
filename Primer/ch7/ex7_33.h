#ifndef SYUAN_EX7_33_H
#define SYUAN_EX7_33_H

#include <string>
#include <iostream>

class Screen {
    using pos = std::string::size_type;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

public:
    Screen()=default;//1
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') {} //2
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) {} //3

    char get() const {
        return contents[cursor];
    }

    pos size() const;
};


Screen::pos Screen::size() const {
    return height * width;
}


#endif // SYUAN_EX7_33_H