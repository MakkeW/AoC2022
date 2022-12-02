#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

int scorePerLine(string line, string line2);

int scorePerLine2(string line, string line2);

template <typename T>
void readInput(vector<T> &input)
{
    ifstream file("input.txt");
    T line;
    while (file >> line)
    {
        input.push_back(line);
    }
}

template <typename T>
void part1(vector<T> &input)
{
    cout << "Part 1: " << endl;
    int score = 0;
    for (int i = 0; i < input.size(); i += 2)
    {
        score += scorePerLine(input[i], input[i + 1]);
    }
    cout << score << endl;
}
template <typename T>
void part2(vector<T> &input)
{
    cout << "Part 2: " << endl;
    int score = 0;
    for (int i = 0; i < input.size(); i += 2)
    {
        score += scorePerLine2(input[i], input[i + 1]);
    }
    cout << score << endl;
}

int main()
{

    auto input = vector<string>();
    readInput(input);
    part1(input);
    part2(input);
}

int scorePerLine(string line, string line2)
{
    int score = 0;
    if (line[0] == 'A' && line2[0] == 'Y')
    {
        score += 6;
    }

    if (line[0] == 'B' && line2[0] == 'Z')
    {
        score += 6;
    }

    if (line[0] == 'C' && line2[0] == 'X')
    {
        score += 6;
    }

    if (line2[0] == 'X')
    {
        score += 1;
    }
    else if (line2[0] == 'Y')
    {
        score += 2;
    }
    else
    {
        score += 3;
    }

    if (line[0] == 'A' && line2[0] == 'X' || line[0] == 'B' && line2[0] == 'Y' || line[0] == 'C' && line2[0] == 'Z')
    {
        score += 3;
    }

    return score;
}

int scorePerLine2(string line, string line2)
{
    int score = 0;
    switch (line[0])
    {
    case 'A':
        if (line2[0] == 'X')
        {
            score += 3;
        }
        else if (line2[0] == 'Y')
        {
            score += 4;
        }
        else if (line2[0] == 'Z')
        {
            score += 8;
        }
        break;
    case 'B':
        if (line2[0] == 'X')
        {
            score += 1;
        }
        else if (line2[0] == 'Y')
        {
            score += 5;
        }
        else if (line2[0] == 'Z')
        {
            score += 9;
        }
        break;
    case 'C':
        if (line2[0] == 'X')
        {
            score += 2;
        }
        else if (line2[0] == 'Y')
        {
            score += 6;
        }
        else if (line2[0] == 'Z')
        {
            score += 7;
        }
        break;
    }
    return score;
}