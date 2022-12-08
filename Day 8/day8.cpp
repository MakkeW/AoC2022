#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

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

bool isVisibleFromOutsideGrid(int x, int y, vector<vector<char>> grid)
{
    if (x <= 0 || y <= 0 || x >= grid[0].size() - 1 || y >= grid.size() - 1)
    {
        return true;
    }
    int value = grid[y][x];

    // check all positions from x, y to the edges of the grid
    // if any of them are higher than value, return false
    // if none of them are higher than value, return true

    bool east = true;
    bool west = true;
    bool north = true;
    bool south = true;
    for (int i = x - 1; i >= 0; i--)
    {
        if (grid[y][i] >= value)
        {
            west = false;
            break;
        }
    }
    for (int i = x + 1; i < grid[0].size(); i++)
    {
        if (grid[y][i] >= value)
        {
            east = false;
            break;
        }
    }
    for (int i = y - 1; i >= 0; i--)
    {
        if (grid[i][x] >= value)
        {
            north = false;
            break;
        }
    }
    for (int i = y + 1; i < grid.size(); i++)
    {
        if (grid[i][x] >= value)
        {
            south = false;
            break;
        }
    }
    return east || west || north || south;
}

int getViewingScore(int x, int y, vector<vector<char>> grid)
{
    int value = grid[y][x];

    // check all positions from x, y to the edges of the grid
    // if any of them are higher than value, return false
    // if none of them are higher than value, return true

    int east = 0;
    int west = 0;
    int north = 0;
    int south = 0;
    for (int i = x - 1; i >= 0; i--)
    {
        if (grid[y][i] >= value || i == 0)
        {
            west = x - i;
            break;
        }
    }
    for (int i = x + 1; i < grid[0].size(); i++)
    {
        if (grid[y][i] >= value || i == grid[0].size() - 1)
        {
            east = i - x;
            break;
        }
    }
    for (int i = y - 1; i >= 0; i--)
    {
        if (grid[i][x] >= value || i == 0)
        {
            north = y - i;
            break;
        }
    }
    for (int i = y + 1; i < grid.size(); i++)
    {
        if (grid[i][x] >= value || i == grid.size() - 1)
        {
            south = i - y;
            break;
        }
    }
    // multiply together
    return east * west * north * south;
}

template <typename T>
void part1(vector<T> &input)
{
    cout << "Part 1: " << endl;
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {

            if (isVisibleFromOutsideGrid(j, i, input))
            {
                count++;
            }
            else
            {
                // cout << ".";
            }
        }
        // cout << endl;
    }
    cout << count << endl;
}
template <typename T>
void part2(vector<T> &input)
{
    cout << "Part 2: " << endl;
    // FInd max viewing score
    int maxScore = 0;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            int score = getViewingScore(j, i, input);
            if (score > maxScore)
            {
                maxScore = score;
            }
        }
    }
    cout << maxScore << endl;
}

int main()
{

    auto input = vector<string>();

    readInput(input);

    vector<vector<char>> grid;

    for (auto line : input)
    {
        vector<char> row;
        for (auto c : line)
        {
            row.push_back(c);
        }
        grid.push_back(row);
    }

    // part1(grid);
    part2(grid);
}