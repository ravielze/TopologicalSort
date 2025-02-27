#include "graph.hpp"

void replaceAll(string &str, const string &from, const string &to)
{
    if (from.empty())
        return;
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

Graph::Graph()
{
    this->tab = 8;
}

Graph::Graph(const vector<string> &lines)
{
    this->tab = 8;
    for (string each : lines)
    {
        istringstream ss(each);
        string token;
        size_t pos = 1;
        vector<string> splitted;
        while (ss >> token)
        {
            while ((pos = token.rfind(',')) != string::npos)
            {
                token.erase(pos, 1);
            }
            replaceAll(token, ".", "");
            splitted.push_back(token);
        }

        if (splitted.size() > 1)
        {
            for (size_t i = 1; i < splitted.size(); i++)
            {
                this->addEdge(splitted[i], splitted[0]);
            }
        }
        else if (splitted.size() == 1)
        {
            this->noDependencies.push_back(splitted[0]);
        }
    }
}

Graph::Graph(const Graph &other)
{
    this->tab = other.tab;
    this->adjList = map<string, vector<string>>(other.adjList);
    this->degrees = map<string, int>(other.degrees);
    this->noDependencies = vector<string>(other.noDependencies);
}

void Graph::addEdge(string target, string source)
{
    this->addNode(target);
    this->addNode(source);
    this->adjList[target].push_back(source);
    this->addDegree(source);
}

void Graph::addNode(string key)
{
    if (this->adjList.find(key) == this->adjList.end())
    {
        this->adjList.insert({key, vector<string>()});
        this->degrees.insert({key, 0});
    }
}

void Graph::addDegree(string key)
{
    if (this->adjList.find(key) == this->adjList.end())
    {
        this->adjList.insert({key, vector<string>()});
        this->degrees.insert({key, 0});
    }
    else
    {
        this->degrees[key]++;
    }
}

void Graph::printGraph()
{
    map<string, vector<string>>::iterator itr;
    cout << "Source\t\tTarget" << endl;
    for (itr = this->adjList.begin(); itr != this->adjList.end(); ++itr)
    {
        cout << itr->first << "\t\t";
        if (itr->second.size() > 0)
        {
            for (string t : itr->second)
            {
                cout << t << ' ';
            }
        }
        else
        {
            cout << "-";
        }

        cout << endl;
    }
}

void Graph::topologicalSort()
{
    Graph copy((*this));
    copy.topologicalSortHelper(1);
}

void Graph::setTab(int t)
{
    this->tab = t;
}

bool find(vector<string> &list, string &smth)
{

    for (string t : list)
    {
        if (t.compare(smth) == 0)
        {
            return true;
        }
    }

    return false;
}

void Graph::topologicalSortHelper(int depth)
{
    vector<string> remove;
    map<string, int>::iterator itr;
    for (itr = this->degrees.begin(); itr != this->degrees.end(); ++itr)
    {
        if (itr->second == 0)
        {
            remove.push_back(itr->first);
        }
    }

    if (remove.size() > 0)
    {
        cout << "Semester " << getRoman(depth) << "\t: ";
        int count = this->tab;
        if (count <= 1)
        {
            count = 1;
            this->tab = 1;
        }
        if (depth == 1 && this->noDependencies.size() > 0)
        {
            for (string key : this->noDependencies)
            {
                if (count == 0)
                {
                    cout << endl;
                    cout << "\t\t  ";
                    count = this->tab;
                }
                cout << key << " ";
                count--;
            }
        }
        for (string key : remove)
        {
            bool isNoDependencies = find(this->noDependencies, key);
            if (count == 0 && !isNoDependencies)
            {
                cout << endl;
                cout << "\t\t  ";
                count = this->tab;
            }
            if (!isNoDependencies)
            {
                cout << key << " ";
            }
            vector<string> tetangga = vector<string>(this->adjList[key]);
            this->degrees.erase(key);
            this->adjList.erase(key);
            for (string t : tetangga)
            {
                this->degrees[t]--;
            }
            count--;
        }
        cout << endl;
        depth++;
        this->topologicalSortHelper(depth);
    }
}
