import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Created by witalia on 12.12.14.
 */
public class Solution {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    int[] countChar;
    int countNotZero;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            String s = in.next();
            int ans = 0;
            for (int l = 1; l < s.length(); l++) {
                for (int i = 0; i + l < s.length(); ++i) {
                    init(s, i, l);
                    for (int j = i + 1; j + l <= s.length(); ++j) {
                        if (countNotZero == 0) {
                            ++ans;
                        }
//                        out.println(l + " " + ans + " " + i + " " + j);
                        update(s, j, l, -1);
                    }
                    update(s, i, l, 1);
                }
            }
            out.println(ans);
        }
    }

    private void update(String s, int i, int l, int x) {
        addChar(s.charAt(i), -x);
        if (i + l < s.length()) {
            addChar(s.charAt(i + l), x);
        }
    }

    private void init(String s, int i, int l) {
        countChar = new int[26];
        countNotZero = 0;
        addChar(s.charAt(i), 1);
        addChar(s.charAt(i + l), -1);
    }

    private void addChar(char q, int delta) {
        q -= 'a';
        if (countChar[q] == 0) {
            ++countNotZero;
        }
        countChar[q] += delta;
        if (countChar[q] == 0) {
            --countNotZero;
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
