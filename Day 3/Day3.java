import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;

class Day3 {

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
        int sum = 0;
        for (T t : input) {
            String temp = t.toString();
            Set<Character> set1 = temp.substring(0, temp.length()/2).chars().mapToObj(c -> (char) c).collect(Collectors.toSet());
            Set<Character> set2 = temp.substring(temp.length()/2).chars().mapToObj(c -> (char) c).collect(Collectors.toSet());
            
            set1.retainAll(set2);
            for(Character c : set1) {
                int value = (int)c-96;
                if(value > 0) {
                    sum += value;
                }
                else{
                    sum += value + 58;
                }
            }
        }
        System.out.println(sum);
    }

    //part 2
    public static <T> void part2(List<T> input) {
        System.out.println("part 2");
        int sum = 0;
        for(int i = 0; i < input.size(); i+=3) {
            Set<Character> temp1 = input.get(i).toString().chars().mapToObj(c -> (char) c).collect(Collectors.toSet());
            Set<Character> temp2 = input.get(i+1).toString().chars().mapToObj(c -> (char) c).collect(Collectors.toSet());
            Set<Character> temp3 = input.get(i+2).toString().chars().mapToObj(c -> (char) c).collect(Collectors.toSet());
            temp2.retainAll(temp3);
            temp1.retainAll(temp2);
            for(Character c : temp1) {
                int value = (int)c-96;
                if(value > 0) {
                    sum += value;
                }
                else{
                    sum += value + 58;
                }
            }
        }
            System.out.println(sum);
        }
    

    public static void main(String[] args) {
        String currentDir = System.getProperty("user.dir")+"/Day 3";
        //read input as ints
        List<String> input = readInput(currentDir, s -> s);
        //part 1
        part1(input);
        //part 2
        part2(input);
    }
}