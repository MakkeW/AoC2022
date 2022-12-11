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

def calcSignalStrength(cycles, X):
    allowedCycles = [20, 60, 100, 140, 180, 220]
    if cycles in allowedCycles:
        print(f'X: {X} cycles: {cycles} signalStrength: {cycles * X}')
        return cycles * X
    return 0

def part1(input):
    #part 1
    print('PART 1')
    X = 1
    cycles = 0
    signalStrength = 0
    for line in input:
        if line == "noop":
            cycles += 1
            signalStrength += calcSignalStrength(cycles, X)
        else:
            value = int(line.split(' ')[1])
            for i in range(2):
                cycles += 1
                signalStrength += calcSignalStrength(cycles, X)
            X += value
    print(f'Signal Strength: {signalStrength}')

def updateString(string, cycles, X):
    pos = (cycles - 1) % 40
    if pos in [X-1, X, X+1]:
        string[pos] = '#'


def part2(input):
    #part 2
    print('PART 2')
    rows = []
    rowString = [' ' for i in range(40)]
    X = 1
    cycles = 0
    for line in input:
        if line == "noop":
            cycles += 1
            updateString(rowString, cycles, X)
            if(cycles % 40 == 0):
                rows.append("".join(rowString))
                rowString = [' ' for i in range(40)]
        else:
            value = int(line.split(' ')[1])
            for i in range(2):
                cycles += 1
                updateString(rowString, cycles, X)
                if(cycles % 40 == 0):
                    rows.append("".join(rowString))
                    rowString = [' ' for i in range(40)]
            X += value
    for row in rows:
        print(row)
    




#read the input file
input = readInputFile("input.txt")

part1(input)
part2(input)