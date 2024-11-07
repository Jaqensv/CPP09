#pragma once

#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstring> // strlen

void parser(char *argv[]);
void checkError(char *argv[]);
void execution(char *argv[], size_t size);
float calculation(std::stack<float> &result, char op);
void cleanUp(char *argv[], size_t size);