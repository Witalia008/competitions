import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;

public class L {
    public static void main(String[] args) {
        HashMap<?,?>[] a = new HashMap[100];

        Scanner inf = new Scanner(System.in);
        int n = inf.nextInt();
        int t = inf.nextInt();
        int m = inf.nextInt();
        inf.nextLine();
        ArrayList<HashMap<String, Integer>> teamsSols = new ArrayList<HashMap<String, Integer>>();
        for (int i = 0; i < t; ++i) teamsSols.add(new HashMap<String, Integer>());
        HashMap<String, Integer> problemSols = new HashMap<String, Integer>();
        String maxPrb = "A";
        while (m-- > 0) {
            String[] curPrb = inf.nextLine().split(" ");
            Integer time = Integer.parseInt(curPrb[0]);
            Integer team = Integer.parseInt(curPrb[1]) - 1;
            if (curPrb[3].equals("Yes")) {
                if (teamsSols.get(team).containsKey(curPrb[2]) == false) {
                    teamsSols.get(team).put(curPrb[2], new Integer(time));
                    problemSols.put(curPrb[2], new Integer(team));
                }
            }
            if (maxPrb.compareTo(curPrb[2]) < 0)
                maxPrb = curPrb[2];
        }
        String[] problems = new String[]{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L"};
        for (String i : problems) {
            if (i.compareTo(maxPrb) > 0)
                break;
            System.out.print(i + " ");
            if (problemSols.containsKey(i))
                System.out.println(teamsSols.get(problemSols.get(i)).get(i) + " " + (problemSols.get(i) + 1));
            else
                System.out.println("- -");
        }
    }
}
