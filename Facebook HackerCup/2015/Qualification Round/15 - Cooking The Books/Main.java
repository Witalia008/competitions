import java.io.*;
import java.math.BigInteger;
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            String n = in.next();
            int minN = Integer.parseInt(n);
            int maxN = Integer.parseInt(n);
            if (Integer.parseInt(n) != 0) {
                for (int i = 0; i < n.length(); i++) {
                    for (int j = i + 1; j < n.length(); j++) {
                        char[] x = n.toCharArray();
                        char temp = x[i];
                        x[i] = x[j];
                        x[j] = temp;
                        if (x[0] == '0') {
                            continue;
                        }
                        minN = Math.min(minN, Integer.parseInt(new String(x)));
                        maxN = Math.max(maxN, Integer.parseInt(new String(x)));
                    }
                }
            }
            out.println(minN + " " + maxN);
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
