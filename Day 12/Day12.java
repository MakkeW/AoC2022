import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;

class Day12 {

    // read input from file as collection of generic type
    public static List<List<Character>> readInput(String fileDir) {
        try {
            // return list of list of chars
            return Files.lines(Paths.get(fileDir + "/input.txt"))
                    .map(s -> s.chars().mapToObj(c -> (char) c).collect(Collectors.toList()))
                    .collect(Collectors.toList());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    static char getSafeListValue(List<List<Character>> input, int x, int y) {
        try {
            return input.get(x).get(y);
        } catch (Exception e) {
            return '-';
        }
    }

    // part 1
    public static void part1(List<List<Character>> input) {
        System.out.println("part 1");
        int startX = 0;
        int startY = 0;
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input.get(i).size(); j++) {
                if (input.get(i).get(j) == 'S') {
                    startX = i;
                    startY = j;
                }
            }
        }
        System.out.println(findExit(new Point(startX, startY), input));

    }

    static int findExit(Point p9, List<List<Character>> g) {
        Set<Point> visited = new HashSet<>();
        Set<Point> currentLevel = new HashSet<>();
        currentLevel.add(p9);
        visited.add(p9);
    
        int steps = 0;
        while(!currentLevel.isEmpty()){
          Set<Point> level = new HashSet<>(currentLevel);
          currentLevel.clear();
          for(Point p : level) {
            int current = g.get(p.x).get(p.y);
            if(current == 'S') current = 'a';
            List<Point> adjacent = new ArrayList<>();
            adjacent.add(new Point(p.x+1, p.y));
            adjacent.add(new Point(p.x-1, p.y));
            adjacent.add(new Point(p.x, p.y+1));
            adjacent.add(new Point(p.x, p.y-1));
            for(Point p2 : adjacent) {
                try{
              if((current == 'y' || current == 'z') && g.get(p2.x).get(p2.y) == 'E'){   
                return steps+1;
                }
              if(g.get(p2.x).get(p2.y) <= current+1 && visited.add(p2)) {
                currentLevel.add(p2);
              }
            } catch (Exception e) {
                continue;
            }}
          }
          steps++;
        }
        return Integer.MAX_VALUE;
      }

    // part 2
    public static <T> void part2(List<List<Character>> input) {
        System.out.println("part 2");
        //Find min distance from any a to end
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input.get(i).size(); j++) {
                if (input.get(i).get(j) == 'a') {
                    int dist = findExit(new Point(i, j), input);
                    if (dist < min) {
                        min = dist;
                    }
                }
            }
        }
        System.out.println(min);
    }

    public static void main(String[] args) {
        String currentDir = System.getProperty("user.dir") + "/Day 12";
        // read input as ints
        List<List<Character>> input = readInput(currentDir);
        // part 1
        part1(input);
        // part 2
        part2(input);
    }



}

class Point {
    int x;
    int y;

    public Point(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o)
        return true;
      if (o == null || getClass() != o.getClass())
        return false;
      Point point = (Point) o;
      return x == point.x && y == point.y;
    }

    @Override
    public int hashCode() {
      return 100000 * x + y;
    }
  }
