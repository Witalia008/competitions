import java.io.*;
import java.util.*;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
//        InputReader in = new InputReader(System.in);
//        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        InputReader in = new InputReader(new FileInputStream(new File("input.txt")));
        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    private static final int MAXN = 10_000_005;
    private static final int MAXK = 9;
    private static int[] lp = new int[MAXN];
    private static List<Integer> pr = new ArrayList<>();
    private static int[] count = new int[MAXN];
    private static int[][] sum = new int[MAXN][MAXK];
    static {
        for (int i = 2; i < MAXN; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.add(i);
            }
            for (int j = 0; j < pr.size() && pr.get(j) <= lp[i] && (long) i * pr.get(j) < MAXN; ++j) {
                lp[i * pr.get(j)] = pr.get(j);
            }
        }
        for (int i = 2; i < MAXN; ++i) {
            int cur = i;
            while (cur % lp[i] == 0) {
                cur /= lp[i];
            }
            count[i] = count[cur] + 1;
            sum[i][count[i]] = 1;
            for (int j = 0; j < MAXK; j++) {
                sum[i][j] += sum[i - 1][j];
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            int a = in.nextInt();
            int b = in.nextInt();
            int k = in.nextInt();
            if (k >= MAXK) {
                out.println(0);
            } else {
                out.println(sum[b][k] - sum[a - 1][k]);
            }
        }
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
