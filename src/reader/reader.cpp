#include "reader.hpp"

Reader::Reader(string filename)
{
    ifstream f(filename.c_str());
    if (!f.good())
    {
        cout << "File " << filename << " is not found." << endl;
        return;
    }
    this->lines = vector<string>();
    fstream file;
    file.open(filename, ios::in);
    if (file.is_open())
    {
        string tp;
        while (getline(file, tp))
        {
            this->lines.push_back(tp);
        }
    }
    file.close();
}

vector<string> Reader::getLines()
{
    return this->lines;
}