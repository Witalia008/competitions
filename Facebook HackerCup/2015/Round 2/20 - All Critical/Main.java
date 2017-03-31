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
    private static final int MAX_C = 20;
    private static long[][] C = new long[MAX_C + 1][MAX_C + 1];
    static {
        for (int i = 0; i <= MAX_C; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            double p = in.nextDouble();
            double q = 1 - p;
            double[] F = new double[MAX_C + 1];
            for (int i = 1; i <= MAX_C; i++) {
                for (int j = 1; j <= i; j++) {
                    F[i] += (1 + F[i - j]) * Math.pow(p, j) * Math.pow(q, i - j) * C[i][j];
                }
                F[i] = (F[i] + Math.pow(q, i)) / (1 - Math.pow(q, i));
            }
            out.println(String.format("%.5f", round(F[MAX_C], 5)));
        }
    }

    private static double round(double value, int places) {
        long factor = (long) Math.pow(10, places);
        value *= factor;
        long temp = Math.round(value);
        return (double) temp / factor;
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

    public float nextFloat() { return Float.parseFloat(next()); }

    public double nextDouble() { return Double.parseDouble(next()); }
}
