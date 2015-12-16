#ifndef NUMBERS_H
#define NUMBERS_H

#include <utility>
#include <vector>
#include <string>

std::pair <int, std::vector<int> > * generate(int difficulty);

std::string* description(int id);

bool check(int warunek, std::vector<int> *liczby);

#endif // NUMBERS_H

