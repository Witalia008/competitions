import java.io.*;
import java.util.*;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

//        InputReader in = new InputReader(new FileInputStream(new File("input.txt")));
//        PrintWriter out = new PrintWriter(new FileOutputStream(new File("output.txt")));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    class Trie {
        int sum;
        Trie[] sons = new Trie[2];

        @Override
        protected Object clone() {
            Trie res = new Trie();
            res.sum = sum;
            res.sons = Arrays.copyOf(sons, 2);
            return res;
        }
    }

    private static final int MAX_QUERIES = 500_000;
    private static final int MAX_BITS = 20;

    int getBit(int number, int pos) {
        return (number >> pos) & 1;
    }

    int setBit(int number, int pos, int bit) {
        return number | (bit << pos);
    }

    Trie addToTrie(Trie v, int number, int depth) {
        Trie res = v == null ? new Trie() : (Trie) v.clone();
        ++res.sum;
        if (depth >= 0) {
            int bit = getBit(number, depth);
            res.sons[bit] = addToTrie(getSon(v, bit), number, depth - 1);
        }
        return res;
    }

    int count(Trie v, int bit) {
        return count(getSon(v, bit));
    }

    int count(Trie left, Trie right, int bit) {
        return count(right, bit) - count(left, bit);
    }

    int count(Trie v) {
        return v == null ? 0 : v.sum;
    }

    int count(Trie left, Trie right) {
        return count(right) - count(left);
    }

    Trie getSon(Trie v, int num) {
        if (v != null && num >= 0 && num < v.sons.length) {
            return v.sons[num];
        }
        return null;
    }

    int maxXor(Trie left, Trie right, int number, int cur, int depth) {
        if (depth < 0) {
            return cur;
        }
        int bit = getBit(number, depth);
        if (count(left, right, 1 - bit) != 0) {
            return maxXor(getSon(left, 1 - bit), getSon(right, 1 - bit),
                    number, setBit(cur, depth, 1 - bit), depth - 1);
        }
        return maxXor(getSon(left, bit), getSon(right, bit),
                number, setBit(cur, depth, bit), depth - 1);
    }

    int lessOrEqual(Trie left, Trie right, int number, int cur, int depth) {
        if (depth < 0) {
            return cur + count(left, right);
        }
        int bit = getBit(number, depth);
        if (bit == 1) {
            cur += count(left, right, 0);
        }
        return lessOrEqual(getSon(left, bit), getSon(right, bit),
                number, cur, depth - 1);
    }

    int nthElement(Trie left, Trie right, int n, int cur, int depth) {
        if (depth < 0) {
            return cur;
        }
        int cnt = count(left, right, 0);
        if (cnt >= n) {
            return nthElement(getSon(left, 0), getSon(right, 0),
                    n, cur, depth - 1);
        }
        return nthElement(getSon(left, 1), getSon(right, 1),
                n - cnt, setBit(cur, depth, 1), depth - 1);
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int m = in.nextInt();
        Trie[] array = new Trie[MAX_QUERIES + 1];
        int n = 0;
        for (int i = 0; i < m; i++) {
            int type = in.nextInt();
            int L = 0, R = 0, x = 0;
            if (type == 1 || type > 2) {
                L = in.nextInt();
                R = in.nextInt();
            }
            x = in.nextInt();
            switch (type) {
                case 0:
                    array[n + 1] = addToTrie(array[n], x, MAX_BITS - 1);
                    ++n;
                    break;
                case 1:
                    out.println(maxXor(array[L - 1], array[R], x, 0, MAX_BITS - 1));
                    break;
                case 2:
                    n -= x;
                    break;
                case 3:
                    out.println(lessOrEqual(array[L - 1], array[R], x, 0, MAX_BITS - 1));
                    break;
                case 4:
                    out.println(nthElement(array[L - 1], array[R], x, 0, MAX_BITS - 1));
                    break;
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
