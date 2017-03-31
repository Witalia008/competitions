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

    class Trie {
        Trie[] next = new Trie[26];
    }

    private int add(Trie v, String s) {
        int res = s.length();
        for (int i = 0; i < s.length(); i++) {
            int cur = s.charAt(i) - 'a';
            if (v.next[cur] == null) {
                v.next[cur] = new Trie();
                if (res == s.length()) {
                    res = i + 1;
                }
            }
            v = v.next[cur];
        }
        return res;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            int n = in.nextInt();
            Trie root = new Trie();
            int ans = 0;
            for (int i = 0; i < n; i++) {
                String s = in.next();
                ans += add(root, s);
            }
            out.println(ans);
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
