import os
abspath = os.path.abspath(__file__)
dname = os.path.dirname(abspath)
os.chdir(dname)

#File structure class
class FileStructure:
    def __init__(self, name, size, children, parent = None):
        self.name = name
        self.size = size
        self.children = children
        self.parent = parent

def construct_filestructure(input):
    #construct file structure
    root = FileStructure('/', 0, [], None)

    currentDir = root
    ls_mode = False

    for i in range(len(input)):
        if input[i][0] == '$':
            ls_mode = False
            commands = input[i][2:].split(' ')
            if(commands[0] == 'cd'):
                if(commands[1] == '..'):
                    currentDir = currentDir.parent
                elif(commands[1] == '/'):
                    currentDir = root
                else:
                    for child in currentDir.children:
                        if child.name == commands[1]:
                            currentDir = child
                            break
            if(commands[0] == 'ls'):
                ls_mode = True
        elif ls_mode:
            files = input[i].split(' ')
            if(files[0] == 'dir'):
                currentDir.children.append(FileStructure(files[1], 0, [], currentDir))
            else:
                currentDir.children.append(FileStructure(files[1], int(files[0]), [], currentDir))
    return root

def update_sizes(root):
    #update sizes of all nodes
    for child in root.children:
        child.size = update_sizes(child)
    root.size = root.size + sum([child.size for child in root.children])
    return root.size

def sum_dirs_with_max_size(root, max_size):
    #sum dirs with max size
    if root.size <= max_size and len(root.children) != 0:
        return root.size + sum([sum_dirs_with_max_size(child, max_size) for child in root.children])
    else:
        return sum([sum_dirs_with_max_size(child, max_size) for child in root.children])

#add all dirs of at least size to a list
def get_dirs_with_max_size(root, size, dirs):
    if root.size >= size and len(root.children) != 0:
        dirs.append(root)
        for child in root.children:
            get_dirs_with_max_size(child, size, dirs)
    else:
        for child in root.children:
            get_dirs_with_max_size(child, size, dirs)



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
    #create root node
    root = construct_filestructure(input)
    update_sizes(root)
    print(sum_dirs_with_max_size(root, 100000))
    return root




def part2(root):
    #part 2
    print('PART 2')
    dirs = []
    space_free = 70000000 - root.size
    space_needed = 30000000 - space_free
    print(space_needed)
    get_dirs_with_max_size(root, space_needed, dirs)
    min_dirs = min(dirs, key=lambda x: x.size)
    print(min_dirs.size)



#read the input file
input = readInputFile("input.txt")

root = part1(input)
part2(root)