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
    overlaps = 0
    for line in input:
        #get the list 
        result = '-'.join(line.split(',')).split('-')
        #get the list as numbers and separate variables
        start1, end1, start2, end2 = [int(x) for x in result]
        #check if range one contains range two or range two contains range one
        if (start1 <= start2 and end1 >= end2) or (start2 <= start1 and end2 >= end1):
            overlaps += 1

    print(f'Overlaps: {overlaps}')

def part2(input):
    #part 2
    print('PART 2')
    overlaps = 0
    for line in input:
        #get the list 
        result = '-'.join(line.split(',')).split('-')
        #get the list as numbers and separate variables
        start1, end1, start2, end2 = [int(x) for x in result]
        #check if range one or range two overlaps
        if (start1 <= start2 and end1 >= start2) or (start2 <= start1 and end2 >= start1):
            overlaps += 1
        
    print(f'Overlaps: {overlaps}')


#read the input file
input = readInputFile("input.txt")

part1(input)
part2(input)