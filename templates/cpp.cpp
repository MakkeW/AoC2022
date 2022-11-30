#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;


template <typename T>
void readInput(vector<T>& input)
{
    ifstream file("input.txt");
    T line;
    while (file >> line)
    {
        input.push_back(line);
    }
}

template <typename T>
void part1(vector<T>& input)
{
    cout << "Part 1: " << endl;    
}
template <typename T>
void part2(vector<T>& input)
{
    cout << "Part 2: " << endl;   
}

int main(){


    auto input = vector<int>();
    readInput(input);
    part1(input);
    part2(input);
}