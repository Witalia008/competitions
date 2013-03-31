import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Kozhukhivskyi on 06.10.2014.
 */

public class Main {
    private static final int MAX_D = 2000;
    private static final int MOD = 1_000_000_007;

    static class Node {
        private List<Node> sons = new ArrayList<>();
        private int a;
        boolean used;

        public Node(int a) {
            this.a = a;
        }

        public List<Node> getSons() {
            return sons;
        }

        void addSon(Node son) {
            sons.add(son);
        }

        private static long dfs(Node cur, Node par, int low, int high) {
            if (cur.used == true) {
                return 1;
            }
            long result = 1;
            if (cur.a >= low && cur.a <= high) {
                result += cur.getSons().stream().filter(son -> son != par)
                                .map(son -> dfs(son, cur, low, high))
                                .reduce(1L, (accumulator, item) -> (accumulator * item) % MOD);
            }
            return result;
        }
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);

        int d = sc.nextInt();
        int n = sc.nextInt();
        Node[] vertices = new Node[n];
        for (int i = 0; i < vertices.length; i++) {
            vertices[i] = new Node(sc.nextInt());
        }
        for (int i = 1; i < n; ++i) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            vertices[a].addSon(vertices[b]);
            vertices[b].addSon(vertices[a]);
        }

        long answer = 0;
        for (int low = 1; low <= MAX_D; ++low) {
            Arrays.asList(vertices).forEach(e -> e.used = false);
            final int finalLow = low;
            answer += Arrays.asList(vertices).stream().filter(e -> e.a == finalLow)
                            .map(e -> {
                                long res = Node.dfs(e, null, finalLow, finalLow + d) - 1;
                                e.used = true;
                                return res;
                            })
                            .reduce(0L, (acc, val) -> (acc + val) % MOD);
            answer %= MOD;
        }
        System.out.println(answer);
    }
}
