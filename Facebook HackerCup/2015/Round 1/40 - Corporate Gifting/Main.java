import java.io.*;
import java.util.*;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
//        InputReader in = new InputReader(System.in);
//        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        InputReader in = new InputReader(new FileInputStream(new File("corporate_gifting.txt")));
        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    private static final int MAXN = 200_000;
    private static final int MAXG = 10;

    private List<Integer>[] sons;
    private int[][] F;
    private int[] used;
    private int[] value;

    private void dfs(int vertex) {
        for (int i = 0; i < MAXG; i++) {
            F[vertex][i] = i + 1;
        }
        for (int son : sons[vertex]) {
            dfs(son);
            calcDynamic(vertex, son);
        }
        calcGreed(vertex);
    }

    private void calcGreed(int vertex) {
        value[vertex] = 0;
        for (int son : sons[vertex]) {
            used[value[son]] = vertex;
        }
        while (used[value[vertex]] == vertex) {
            ++value[vertex];
        }
    }

    private void calcDynamic(int vertex, int son) {
        int[] mins = {Integer.MAX_VALUE, Integer.MAX_VALUE};
        for (int j = 0; j < MAXG; ++j) {
            int cur = F[son][j];
            if (cur <= mins[0]) {
                mins[1] = mins[0];
                mins[0] = cur;
            } else if (cur < mins[1]) {
                mins[1] = cur;
            }
        }
        for (int i = 0; i < MAXG; ++i) {
            int pos = (F[son][i] == mins[0]) ? 1 : 0;
            F[vertex][i] += mins[pos];
        }
    }

    private int getDynamicAns() {
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < MAXG; i++) {
            ans = Math.min(ans, F[0][i]);
        }
//        return Integer.MAX_VALUE;
        return ans;
    }

    private long getGreedAns() {
        long ans = 0;
        for (int i = 0; i < value.length; i++) {
            ans += value[i] + 1;
        }
//        return Long.MAX_VALUE;
        return ans;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            int n = in.nextInt();
            init(n);
            for (int i = 0; i < n; i++) {
                int parent = in.nextInt() - 1;
                if (parent != -1) {
                    sons[parent].add(i);
                }
            }
            dfs(0);
            out.println(Math.min(getDynamicAns(), getGreedAns()));
        }
    }

    private void init(int n) {
        sons = new List[n];
        for (int i = 0; i < n; i++) {
            sons[i] = new ArrayList<>();
        }
        value = new int[n];
        used = new int[n];
        Arrays.fill(used, -1);
        F = new int[n][MAXG];
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}
