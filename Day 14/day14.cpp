#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

const int OFFSET = 450;

int maxY = INT_MIN;

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
//1000 x 1000 grid
vector<vector<char>> grid = vector<vector<char>>(100000, vector<char>(100000, '.')); 

//print grid between two coords
void printGrid(pair<int, int> start, pair<int, int> end)
{
    for (int i = start.second; i <= end.second; i++)
    {
        for (int j = start.first; j <= end.first; j++)
        {
            cout << grid[j][i];
        }
        cout << endl;
    }
}

void makeLine(pair<int, int> start, pair<int, int> end, char c)
{
    if (start.first == end.first)
    {
        for (int i = min(start.second, end.second); i <= max(start.second, end.second); i++)
        {
            grid[start.first][i] = c;
        }
    }
    else if (start.second == end.second)
    {
        for (int i = min(start.first, end.first); i <= max(start.first, end.first); i++)
        {
            grid[i][start.second] = c;
        }
    }
}

void fillGrid(vector<string> input){
    vector<pair<int, int>> coords;
    int x, y;
    grid[500][0] = '+'; //start point
    for (int i = 0; i < input.size()-1; i++){
        string line = input[i];  

            if( line == "->"){
                sscanf(input[i-1].c_str(), "%d,%d", &x, &y);
                coords.push_back(make_pair(x, y));

                if(y > maxY){
                    maxY = y;
                }

                sscanf(input[i+1].c_str(), "%d,%d", &x, &y);
                coords.push_back(make_pair(x, y));

                if(y > maxY){
                    maxY = y;
                }
            }else if((line != "->" && input[i+1] != "->")){
                for(int j = 1; j < coords.size(); j++){
                    makeLine(coords[j-1], coords[j], '#');
                }
                coords.clear();
            }
        
    }
    for(int j = 1; j < coords.size(); j++){
                    makeLine(coords[j-1], coords[j], '#');
                }
}

template <typename T>
void part1(vector<T>& input)
{
    cout << "Part 1: " << endl;
    fillGrid(input); 
    
    printGrid({492, 0}, {503, 10});
    cout << "maxY: " << maxY << endl;
    int x = 500;
    int y = 0;
    int count = 0;
    while(true){
        while(grid[x][y+1] != '#' && grid[x][y+1] != 'o'){
            y++;
        }

        if(y > maxY){
            break;
        }


        if(grid[x-1][y+1] != '#' && grid[x-1][y+1] != 'o'){
            x--;
            y++;
        }
        else if (grid[x+1][y+1] != '#' && grid[x+1][y+1] != 'o'){
            x++;
            y++;
        }
        else{
            grid[x][y] = 'o';
            x = 500;
            y = 0;
            count++;
            continue;;
        }
    }
    printGrid({492, 0}, {503, 10});
    cout << "count: " << count << endl;

   
}
template <typename T>
void part2(vector<T>& input)
{
    fillGrid(input); 
    cout << "Part 2: " << endl;   
    makeLine({0, maxY+2}, {100000-1, maxY+2}, '#');

    cout << "maxY: " << maxY << endl;
    int x = 500;
    int y = 0;
    int count = 0;
    while(true){
        while(grid[x][y+1] != '#' && grid[x][y+1] != 'o'){
            y++;
        }

        if(grid[x-1][y+1] != '#' && grid[x-1][y+1] != 'o'){
            x--;
            y++;
        }
        else if (grid[x+1][y+1] != '#' && grid[x+1][y+1] != 'o'){
            x++;
            y++;
        }
        else{
            grid[x][y] = 'o';
            count++;

            if(x == 500 && y == 0){
                break;
            }

            x = 500;
            y = 0;
            continue;;
        }


    }
    printGrid({492, 0}, {503, 10});
    cout << "count: " << count << endl;
}

int main(){


    auto input = vector<string>();
    readInput(input);
    //part1(input);
    part2(input);
}