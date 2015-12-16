#include "numbers.h"

//tutaj będzie kod od Marka
std::pair <int, std::vector<int> > * generate(int difficulty) {
    return new std::pair <int, std::vector<int> >(4, std::vector<int>{1, 2, 4, 5});
}

std::string* description(int id) {
    return new std::string("kupa po kolei");
}

bool check(int warunek, std::vector<int> *liczby)
{
    if ((*liczby).size() == 0) return false;
    if ((*liczby).size() == 1) return true;
    for (int i = 1; i < (*liczby).size(); i++) {
        if (!((*liczby)[i] == (*liczby)[i - 1] + 1)) return false;
    }
    return true;
}
