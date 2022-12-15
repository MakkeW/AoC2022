import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;

class Day9 {

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
        Rope rope = new Rope(2, 0, 0);

        for (T t : input) {
            String s = (String) t;
            char dir = s.charAt(0);
            int length = Integer.parseInt(s.substring(2));
            rope.moveHead(dir, length);
        }

        System.out.println(rope.visited.size());
    }

    //part 2
    public static <T> void part2(List<T> input) {
        System.out.println("part 2");
        Rope rope = new Rope(10, 0, 0);

        for (T t : input) {
            String s = (String) t;
            char dir = s.charAt(0);
            int length = Integer.parseInt(s.substring(2));
            rope.moveHead(dir, length);
        }

        System.out.println(rope.visited.size());
    }

    public static void main(String[] args) {
        String currentDir = System.getProperty("user.dir")+"/Day 9";
        System.out.println(currentDir);
        //read input as ints
        List<String> input = readInput("Day 9", s -> s);
        //part 1
        //part1(input);
        //part 2
        part2(input);
    }
}

class Rope {
    ArrayList<Point> rope;
    Set<String> visited = new HashSet<>();

    public Rope(int size, int startX, int startY) {
        visited.clear();
        rope = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            rope.add(new Point(startX, startY));
        }
    }

    void moveHead(char dir, int length){
        for (int i = 0; i < length; i++) {
            Point head = rope.get(0);
            switch (dir){
                case 'U':
                head.y++;
                    break;
                case 'D':
                head.y--;
                    break;
                case 'L':
                head.x--;
                    break;
                case 'R':
                head.x++;
                    break;
            }
            updateBody();

        }
    }

    private void updateBody(){
        for (int i = 1; i < rope.size(); i++) {
            
            Point body = rope.get(i);
            if(i == rope.size()-1)  {
                visited.add(body.x + ", " + body.y);
            }
            Point prev = rope.get(i-1);
            int difX = (prev.x - body.x)/2;
            int difY = (prev.y - body.y)/2;

            if(difX != 0 && difY == 0){
                difY = prev.y - body.y;
            }
            else if(difY != 0 && difX == 0){
                difX = prev.x - body.x;
            }

            body.x += difX;
            body.y += difY;
            if(i == rope.size()-1)  {
                visited.add(body.x + ", " + body.y);
            }
            
        }
    }
}

class Point{
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    boolean equals(Point p){
        return p.x == x && p.y == y;
    }

    @Override
    public String toString() {
        return "x=" + x +", y=" + y;
    }

}