#ifndef SYUAN_EX7_53_H
#define SYUAN_EX7_53_H


class Debug
{
private:
    bool hw;
    bool io;
    bool other;
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
    constexpr Debug(bool b, bool i, bool o): hw(b), io(i), other(o) {}
    constexpr bool any() { return hw || io || other; }
    
    void set_hw(bool b) {hw = b;}
    void set_io(bool b) {io = b;}
    void set_other(bool b) {other = b;}
};


#endif // SYUAN_EX7_53_H