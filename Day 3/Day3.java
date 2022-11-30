import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
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
    }

    //part 2
    public static <T> void part2(List<T> input) {
        System.out.println("part 2");
    }

    public static void main(String[] args) {
        String currentDir = System.getProperty("user.dir")+"/Day 3";
        //read input as ints
        List<Integer> input = readInput(currentDir, Integer::parseInt);
        //part 1
        part1(input);
        //part 2
        part2(input);
    }
}