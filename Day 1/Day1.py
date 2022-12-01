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
    calories_per_elf = []
    sum = 0
    for line in input:
        if line == '':
            calories_per_elf.append(sum)
            sum = 0
        else:
            sum += int(line)

    print(max(calories_per_elf))
    return calories_per_elf


def part2(input):
    calories_per_elf = part1(input)
    #part 2
    print('PART 2')
    calories_per_elf = sorted(calories_per_elf)
    print(calories_per_elf[-3:])
    print(sum(calories_per_elf[-3:]))



#read the input file
input = readInputFile("input.txt")

part2(input)