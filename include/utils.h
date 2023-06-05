/*
* Filename: utils.h
* Created on: May 12, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>

namespace utils {
    int Min(int i, int j);

    int Min(int i, int j, int k, int l);

    int Min(int i, int j, int k, int l, int m, int n);

    int Max(int i, int j);

    int Max(int i, int j, int k);

    int Max(int i, int j, int k, int l);

    void Usage();

    void SfmlUsage();

} // namespace utils

#endif // UTILS_H_
