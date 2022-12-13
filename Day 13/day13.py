from functools import cmp_to_key
import os
import ast


abspath = os.path.abspath(__file__)
dname = os.path.dirname(abspath)
os.chdir(dname)

def readInputFile(filename, toInt = False):
    #read input file
    currDir = os.getcwd()
    print(f'CURRENT DIR: {currDir}')
    with open(filename) as f:
        lines = f.read().splitlines()
    if toInt:
        lines = [int(x) for x in lines]
    #remove empty lines
    lines = [x for x in lines if x]
    lines = [ast.literal_eval(x) for x in lines]
    return lines

def part1(input):
    #part 1
    print('PART 1')
    counter = []
    j = 1
    
    #travers input two lines at a time
    for i in range(0, len(input), 2):
        #get the current line and the next line
        print()
        print(f'== Pair {j} ==')
        currLine = input[i]
        nextLine = input[i+1]
        ans = "Not yet"
        ans = checkLines(currLine, nextLine, ans)
        if(ans == "yes"):
            print(j)
            counter.append(j)
        
        j += 1
    print(sum(counter))

def checkLines(currLine, nextLine, ans):
    if(ans == "yes" or ans == "no"):
        return ans
    if(type(currLine) == int and type(nextLine) == int):
        #print(f'Compare {currLine} vs {nextLine}')
        if(currLine == nextLine):
            return "Not yet"
        if currLine < nextLine:
            ans = "yes"
            return ans
        elif currLine > nextLine:
            ans = "no"
            return ans
    
    if(type(currLine) == list and type(nextLine) == list):
        for i in range(0, min(len(currLine), len(nextLine))):
            ans = checkLines(currLine[i], nextLine[i], ans)
            if(ans != "Not yet"):
                return ans
        if(len(currLine) < len(nextLine)):
            ans = "yes"
            return ans
        elif(len(currLine) > len(nextLine)):
            ans = "no"
            return ans
    if(type(currLine) == list and type(nextLine) == int):
        nextLine = [nextLine]
        ans = checkLines(currLine, nextLine, ans)
        if(ans != "Not yet"):
            return ans
    if(type(currLine) == int and type(nextLine) == list):
        currLine = [currLine]
        ans = checkLines(currLine, nextLine, ans)
        if(ans != "Not yet"):
            return ans
    return ans
    

def compareLines(currLine, nextLine):
    ans = "Not yet"
    ans = checkLines(currLine, nextLine, ans)
    if(ans == "yes"):
        return 1
    return -1

def part2(input):
    #part 2
    print('PART 2')
    input.append([[2]])
    input.append([[6]])

    input = sorted(input, key=cmp_to_key(compareLines), reverse=True)
    startIndex = 0
    endIndex = 0
    for i, line in enumerate(input):
        if line == [[2]]:
            startIndex = i+1
        if line == [[6]]:
            endIndex = i+1
    print(startIndex)
    print(endIndex)
    print(startIndex*endIndex)



#read the input file
input = readInputFile("input.txt")

#part1(input)
part2(input)