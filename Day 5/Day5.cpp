#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

template <typename T>
void readInput(vector<T> &input)
{
    ifstream file("input.txt");
    T line;
    while (getline(file, line))
    {
        input.push_back(line);
    }
}

template <typename T>
void part1(vector<T> &input)
{
    cout << "Part 1: " << endl;
    vector<stack<char>> stacks(9);
    int i = 0;
    for (i; i < input.size(); i++)
    {
        if (input[i][1] == '1')
        {
            break;
        }
        // cout << input[i] << endl;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        for (int k = 0; k < stacks.size(); k++)
        {
            if (input[j][k * 4 + 1] != ' ')
            {
                stacks[k].push(input[j][k * 4 + 1]);
            }
        }
        cout << endl;
    }
    i += 2;
    for (i; i < input.size(); i++)
    {
        int size, from, to;
        // read size, from and to from input
        sscanf(input[i].c_str(), "move %d from %d to %d", &size, &from, &to);
        // cout << size << " " << from << " " << to << endl;
        for (int j = 0; j < size; j++)
        {
            if (stacks[from - 1].top())
            {
                stacks[to - 1].push(stacks[from - 1].top());
                stacks[from - 1].pop();
            }
        }
    }
    // print top element of each stack
    for (int j = 0; j < stacks.size(); j++)
    {
        cout << stacks[j].top();
    }
    cout << endl;
}
template <typename T>
void part2(vector<T> &input)
{
    cout << "Part 2: " << endl;
    vector<stack<char>> stacks(9);
    int i = 0;
    for (i; i < input.size(); i++)
    {
        if (input[i][1] == '1')
        {
            break;
        }
        // cout << input[i] << endl;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        for (int k = 0; k < stacks.size(); k++)
        {
            if (input[j][k * 4 + 1] != ' ')
            {
                stacks[k].push(input[j][k * 4 + 1]);
            }
        }
        cout << endl;
    }
    i += 2;
    for (i; i < input.size(); i++)
    {
        int size, from, to;
        // read size, from and to from input
        sscanf(input[i].c_str(), "move %d from %d to %d", &size, &from, &to);
        // cout << size << " " << from << " " << to << endl;
        stack<char> temp;
        for (int j = 0; j < size; j++)
        {
            if (stacks[from - 1].top())
            {
                temp.push(stacks[from - 1].top());
                stacks[from - 1].pop();
            }
        }
        while (!temp.empty())
        {
            stacks[to - 1].push(temp.top());
            temp.pop();
        }
    }
    // print top element of each stack
    for (int j = 0; j < stacks.size(); j++)
    {
        cout << stacks[j].top();
    }
    cout << endl;
}

int main()
{

    auto input = vector<string>();
    readInput(input);
    part1(input);
    part2(input);
}