#ifndef __READER_H__
#define __READER_H__
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Reader
{
private:
    vector<string> lines;

public:
    Reader(string filename);

    vector<string> getLines();
};

#endif // __READER_H__