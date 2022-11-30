import os
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
    return lines

def part1(input):
    #part 1
    print('PART 1')


def part2(input):
    #part 2
    print('PART 2')



#read the input file
input = readInputFile("input.txt")

part1(input)