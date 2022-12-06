import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;

class day6 {

    //read input from file as collection of generic type
    public static <T> List<T> readInput(String fileDir, Function<String, T> mapper) {
        try {
            return Files.lines(Paths.get(fileDir + "/input.txt"))
                    .map(mapper)
                    .collect(Collectors.toList());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    //part 1
    public static <T> void part1(List<T> input) {
        System.out.println("part 1");
        String line = input.get(0).toString(); 
        //Find 4 unique characters in a row
        findNUnique(line, 4);
    }

    public static void findNUnique(String line, int n) {
        int index = 0;
        while(index < line.length()) {
            String temp = line.substring(index, index+n);
            if(temp.length() == n) {
                if(isUnique(temp)) {
                    System.out.println(temp);
                    System.out.println(index+n);
                    break;
                }
            }
            index++;
        }
    }

    public static boolean isUnique(String s) {
        //convert string to char set
        //if set size is 4, return true
        Set<Character> set = s.chars().mapToObj(c -> (char) c).collect(Collectors.toSet());
        return set.size() == s.length();

    }

    //part 2
    public static <T> void part2(List<T> input) {
        System.out.println("part 2");
        String line = input.get(0).toString();
        //Find 14 unique characters in a row
        findNUnique(line, 14);
    }

    public static void main(String[] args) {
        System.out.println("Day 6");
        String currentDir = System.getProperty("user.dir")+"/Day 6";
        //read input as ints
        List<String> input = readInput(currentDir, String::toString);
        //part 1
        part1(input);
        //part 2
        part2(input);
    }
}