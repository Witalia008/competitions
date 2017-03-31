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
    class Nutrition {
        int[] facts;

        Nutrition() {
            facts = new int[3];
            Arrays.fill(facts, 0);
        }

        Nutrition(InputReader in) {
            this();
            for (int i = 0; i < facts.length; i++) {
                facts[i] = in.nextInt();
            }
        }

        public void add(Nutrition a) {
            for (int i = 0; i < facts.length; i++) {
                facts[i] += a.facts[i];
            }
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (obj == this) {
                return true;
            }
            if (obj instanceof Nutrition) {
                Nutrition other = ((Nutrition) obj);
                for (int i = 0; i < facts.length; i++) {
                    if (facts[i] != other.facts[i]) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            Nutrition desired = new Nutrition(in);
            int n = in.nextInt();
            Nutrition[] products = new Nutrition[n];
            for (int i = 0; i < products.length; i++) {
                products[i] = new Nutrition(in);
            }
            boolean isPossible = false;
            for (int mask = 0; mask < (1 << n); mask++) {
                Nutrition cur = new Nutrition();
                for (int i = 0; i < products.length; i++) {
                    if ((mask & (1 << i)) != 0) {
                        cur.add(products[i]);
                    }
                }
                if (cur.equals(desired)) {
                    isPossible = true;
                    break;
                }
            }
            out.println(isPossible ? "yes" : "no");
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
