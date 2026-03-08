#ifndef SYUAN_EX7_23_H
#define SYUAN_EX7_23_H

#include <string>

class Screen {
public:
typedef std::string::size_type pos;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

public:
    Screen()=default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}

    char get() const {
        return contents[cursor];
    }
    char get(pos r, pos c) const;

    Screen move(pos r, pos c);
};


inline Screen Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;

    return *this;
}

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

#endif // SYUAN_EX7_23_H