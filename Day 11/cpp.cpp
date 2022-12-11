#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <deque>

using namespace std;

class Monkey{
    public:
        deque<unsigned long long > items{};
        function<bool(unsigned long long )> test = [](unsigned long long ){return true;};
        function<unsigned long long (unsigned long long )> operation = [](unsigned long long ){return 0;};

        int trueRecipient = 0;
        int falseRecipient = 0;
        int inspectCount = 0;
        int worryDivider = 3;
        int modDivider = 1;

        void turn(vector<Monkey> &monkeys){
            while(!items.empty()){
                unsigned long long  item = items.front();
                unsigned long long  newValue = operation(item)%modDivider;
                newValue /= worryDivider;
                if(test(newValue)){
                    monkeys[trueRecipient].items.push_back(newValue);
                }else{
                    monkeys[falseRecipient].items.push_back(newValue);
                }
                inspectCount++;
                items.pop_front();
            }
        }
        
};

vector<Monkey> create_monkeys(){
    vector<Monkey> monkeys;
    monkeys.resize(8);
    monkeys[0].test = [](unsigned long long  x){return x % 13 == 0;};
    monkeys[0].operation = [](unsigned long long  x){return x * 3;};
    monkeys[0].trueRecipient = 1;
    monkeys[0].falseRecipient = 7;
    monkeys[0].items.insert(monkeys[0].items.end(), {84, 72, 58, 51});
    monkeys[0].modDivider = 13 * 2* 7 * 17 * 5* 11 * 3* 19;

    monkeys[1].test = [](unsigned long long  x){return x % 2 == 0;};
    monkeys[1].operation = [](unsigned long long  x){return x + 8;};
    monkeys[1].trueRecipient = 7;
    monkeys[1].falseRecipient = 5;
    monkeys[1].items.insert(monkeys[1].items.end(), {88, 58, 58});
    monkeys[1].modDivider = 13 * 2* 7 * 17 * 5* 11 * 3* 19;

    monkeys[2].test = [](unsigned long long  x){return x % 7 == 0;};
    monkeys[2].operation = [](unsigned long long  x){return x * x;};
    monkeys[2].trueRecipient = 3;
    monkeys[2].falseRecipient = 4;
    monkeys[2].items.insert(monkeys[2].items.end(), {93, 82, 71, 77, 83, 53, 71, 89});
    monkeys[2].modDivider = 13 * 2* 7 * 17 * 5* 11 * 3* 19;

    monkeys[3].test = [](unsigned long long  x){return x % 17 == 0;};
    monkeys[3].operation = [](unsigned long long  x){return x + 2;};
    monkeys[3].trueRecipient = 4;
    monkeys[3].falseRecipient = 6;
    monkeys[3].items.insert(monkeys[3].items.end(), {81, 68, 65, 81, 73, 77, 96});
    monkeys[3].modDivider = 13 * 2* 7 * 17 * 5* 11 * 3* 19;

    monkeys[4].test = [](unsigned long long  x){return x % 5 == 0;};
    monkeys[4].operation = [](unsigned long long  x){return x  + 3;};
    monkeys[4].trueRecipient = 6;
    monkeys[4].falseRecipient = 0;
    monkeys[4].items.insert(monkeys[4].items.end(), {75, 80, 50, 73, 88});
    monkeys[4].modDivider = 13 * 2* 7 * 17 * 5* 11 * 3* 19;

    monkeys[5].test = [](unsigned long long  x){return x % 11 == 0;};
    monkeys[5].operation = [](unsigned long long  x){return x * 17;};
    monkeys[5].trueRecipient = 2;
    monkeys[5].falseRecipient = 3;
    monkeys[5].items.insert(monkeys[5].items.end(), {59, 72, 99, 87, 91, 81});
    monkeys[5].modDivider = 13 * 2* 7 * 17 * 5* 11 * 3* 19;

    monkeys[6].test = [](unsigned long long  x){return x % 3 == 0;};
    monkeys[6].operation = [](unsigned long long  x){return x + 6;};
    monkeys[6].trueRecipient = 1;
    monkeys[6].falseRecipient = 0;
    monkeys[6].items.insert(monkeys[6].items.end(), {86, 69});
    monkeys[6].modDivider = 13 * 2* 7 * 17 * 5* 11 * 3* 19;

    monkeys[7].test = [](unsigned long long  x){return x % 19 == 0;};
    monkeys[7].operation = [](unsigned long long  x){return x + 1;};
    monkeys[7].trueRecipient = 2;
    monkeys[7].falseRecipient = 5;
    monkeys[7].items.insert(monkeys[7].items.end(), {91});
    monkeys[7].modDivider = 13 * 2* 7 * 17 * 5* 11 * 3* 19;

    return monkeys;
}


vector<Monkey> create_test_monkeys(){
    vector<Monkey> monkeys;
    monkeys.resize(4);
    monkeys[0].test = [](unsigned long long  x){return x % 23 == 0;};
    monkeys[0].operation = [](unsigned long long  x){return x * 19;};
    monkeys[0].trueRecipient = 2;
    monkeys[0].falseRecipient = 3;
    monkeys[0].items.insert(monkeys[0].items.end(), {79, 98});
    monkeys[0].modDivider = 23 * 19 * 13 * 17;

    monkeys[1].test = [](unsigned long long  x){return x % 19 == 0;};
    monkeys[1].operation = [](unsigned long long  x){return x + 6;};
    monkeys[1].trueRecipient = 2;
    monkeys[1].falseRecipient = 0;
    monkeys[1].items.insert(monkeys[1].items.end(), {54, 65, 75, 74});
    monkeys[1].modDivider = 23 * 19 * 13 * 17;

    monkeys[2].test = [](unsigned long long  x){return x % 13 == 0;};
    monkeys[2].operation = [](unsigned long long  x){return x * x;};
    monkeys[2].trueRecipient = 1;
    monkeys[2].falseRecipient = 3;
    monkeys[2].items.insert(monkeys[2].items.end(), {79, 60, 97});
    monkeys[2].modDivider = 23 * 19 * 13 * 17;

    monkeys[3].test = [](unsigned long long  x){return x % 17 == 0;};
    monkeys[3].operation = [](unsigned long long  x){return x + 3;};
    monkeys[3].trueRecipient = 0;
    monkeys[3].falseRecipient = 1;
    monkeys[3].items.insert(monkeys[3].items.end(), {74});
    monkeys[3].modDivider = 23 * 19 * 13 * 17;

    return monkeys;
}


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

//print monkey inspect counts
void printMonkeys(vector<Monkey>& monkeys){
    for(int i = 0; i < monkeys.size(); i++){
        cout << "Monkey " << i << " inspected items " << monkeys[i].inspectCount << " times" << endl;
    }
}

template <typename T>
void part1(vector<T>& input)
{
    cout << "Part 1: " << endl;   
    auto monkeys = create_monkeys();

    for(int i = 0; i < 20; i++){
        for(auto& monkey : monkeys){
            monkey.turn(monkeys);
        }
    }

    int max = 0;
    int maxIndex = -1;
    int secondMax = 0;
    int secondMaxIndex = -1;

    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectCount > max){
            secondMax = max;
            secondMaxIndex = maxIndex;
            max = monkeys[i].inspectCount;
            maxIndex = i;
        }else if(monkeys[i].inspectCount > secondMax){
            secondMax = monkeys[i].inspectCount;
            secondMaxIndex = i;
        }
    }

    int monkeyBusiness = max * secondMax;

    cout << "Monkey business: " << monkeyBusiness << endl;



    

}
template <typename T>
void part2(vector<T>& input)
{
    cout << "Part 2: " << endl;   
    auto monkeys = create_monkeys();

    //change worryDivider to 1 for all monkeys
    for(auto& monkey : monkeys){
        monkey.worryDivider = 1;
    }


    for(int i = 1; i <= 10000; i++){
        for(auto& monkey : monkeys){
            monkey.turn(monkeys);
        }
        if(i % 1000 == 0 || i == 1 || i == 20){
            cout << "== After round " << i << " ==" << endl;
            printMonkeys(monkeys);
        }
    }

    unsigned long long  max = 0;
    int maxIndex = -1;
    unsigned long long  secondMax = 0;
    int secondMaxIndex = -1;

    for(int i = 0; i < monkeys.size(); i++){
        if(monkeys[i].inspectCount > max){
            secondMax = max;
            secondMaxIndex = maxIndex;
            max = monkeys[i].inspectCount;
            maxIndex = i;
        }else if(monkeys[i].inspectCount > secondMax){
            secondMax = monkeys[i].inspectCount;
            secondMaxIndex = i;
        }
    }

    unsigned long long  monkeyBusiness = max * secondMax;

    cout << "Monkey business: " << monkeyBusiness << endl;
}

int main(){


    auto input = vector<int>();
    readInput(input);
    part1(input);
    part2(input);
}