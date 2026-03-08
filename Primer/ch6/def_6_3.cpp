#include <iostream>

const std::string& manip(std::string& ret) {
    if (!ret.empty())
    {
        return ret;
    } else {
        return "Empty";
    }
}

int main() {

    std::string a = "amber";
    manip(a);

    return 0;
}