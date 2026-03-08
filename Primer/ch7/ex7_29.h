#ifndef SYUAN_EX7_29_H
#define SYUAN_EX7_29_H

#include <string>

class Screen {
public:
typedef std::string::size_type pos;

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

public:
    Screen()=default; //1
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') {} //2
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {} //3

    char get() const {
        return contents[cursor];
    }
    char get(pos r, pos c) const;
    Screen set(char c);
    Screen set(pos r, pos col, pos ch);
    Screen move(pos r, pos c);

    Screen display(std::ostream& os);
    const Screen& display(std::ostream& os) const;
};

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen Screen::set(char c) {
    contents[cursor] = c;

    return *this;
}

inline Screen Screen::set(pos r, pos col, pos ch) {
    contents[r*width + col] = ch;

    return *this;
}

inline Screen Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;

    return *this;
}

inline Screen Screen::display(std::ostream& os) {
    os << contents;

    return *this;
}


inline const Screen& Screen::display(std::ostream& os) const {
    os << contents;

    return *this;
}


#endif // SYUAN_EX7_29_H