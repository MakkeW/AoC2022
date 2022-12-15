import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.AbstractMap;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;




class Day15 {

    static long ROW_Y = 2000000;



    static HashMap<Long, Set<Long>> visitedPerRow = new HashMap<>();

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

        Set<String> beacons = new HashSet<>();
        Set<String> visited = new HashSet<>();

        for (T t : input) {
            long sX;
            long sY;
            long bX;
            long bY;
            var subStrs = t.toString().split("=");



            sX = Long.parseLong(subStrs[1].substring(0, subStrs[1].length() - 3));
            sY = Long.parseLong(subStrs[2].substring(0, subStrs[2].length() - 24));
            bX = Long.parseLong(subStrs[3].substring(0, subStrs[3].length() - 3));
            bY = Long.parseLong(subStrs[4].substring(0, subStrs[4].length()));



            beacons.add(new AbstractMap.SimpleEntry<Long, Long>(bX, bY).toString());

            long distance = Math.abs(sX - bX) + Math.abs(sY - bY);

            
            long dist1 = Math.abs(sY - ROW_Y);
            long x = sX;
            while(dist1 <= distance){
                visited.add(new AbstractMap.SimpleEntry<Long, Long>(x, ROW_Y).toString());
                dist1++;
                x++;
            }

            long dist2 = Math.abs(sY - ROW_Y);
            x = sX;
            while(dist2 <= distance){
                visited.add(new AbstractMap.SimpleEntry<Long, Long>(x, ROW_Y).toString());
                dist2++;
                x--;
            }
            }
        System.out.println(visited.size());
        System.out.println(beacons.size());
        //visited.removeAll(beacons);

       
        System.out.println(visited.size());
        

    }



    //part 2
    public static <T> void part2(List<T> input) {
        System.out.println("part 2");

        Set<Long> upLines = new HashSet<>();
        Set<Long> downLines = new HashSet<>();
        HashMap<AbstractMap.SimpleEntry<Long, Long>, Long> scanners = new HashMap<>();

        

        for (T t : input) {
            long sX;
            long sY;
            long bX;
            long bY;
            var subStrs = t.toString().split("=");



            sX = Long.parseLong(subStrs[1].substring(0, subStrs[1].length() - 3));
            sY = Long.parseLong(subStrs[2].substring(0, subStrs[2].length() - 24));
            bX = Long.parseLong(subStrs[3].substring(0, subStrs[3].length() - 3));
            bY = Long.parseLong(subStrs[4].substring(0, subStrs[4].length()));

            

            long dist = Math.abs(sX - bX) + Math.abs(sY - bY);

            scanners.put(new AbstractMap.SimpleEntry<Long, Long>(sX, sY), dist);

            upLines.add(sY - sX + dist + 1);
            upLines.add(sY - sX - dist - 1);
            downLines.add(sY + sX + dist + 1);
            downLines.add(sY + sX - dist - 1); 
        }



        long max = 4000000;

        for( long i : upLines){
            for(long j : downLines){
                long intersectX  = (j-i)/2;
                long intersectY = (i+j)/2;
                if(intersectX > 0 && intersectX < max && intersectY > 0 && intersectY < max){
                    boolean valid = true;
                    for(Map.Entry<AbstractMap.SimpleEntry<Long, Long>, Long> entry : scanners.entrySet()){
                        long dist = Math.abs(entry.getKey().getKey() - intersectX) + Math.abs(entry.getKey().getValue() - intersectY);
                        if(dist < entry.getValue()){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        System.out.println(intersectX*max + intersectY);
                        break;
                    }
                }

            }
        }

    }

    public static void main(String[] args) {
        String currentDir = System.getProperty("user.dir")+"/Day 15";
        //read input as ints
        List<String> input = readInput(currentDir, s -> s);
        //part 1
        //part1(input);
        //part 2
        part2(input);
    }
}