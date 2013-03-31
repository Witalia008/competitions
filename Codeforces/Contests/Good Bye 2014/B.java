import javafx.util.Pair;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    private static int n;
    private static boolean[] used;
    private static String[] A;
    private static List<Integer> comp;
    private static List<Integer> idx;
    private static int[] perm;

    private static void dfs(int v) {
        if (used[v]) {
            return;
        }
        comp.add(perm[v]);
        idx.add(v);
        used[v] = true;
        for (int i = 0; i < n; i++) {
            if (A[v].charAt(i) == '1') {
                dfs(i);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        n = in.nextInt();
        perm = new int[n];
        used = new boolean[n];
        A = new String[n];
        for (int i = 0; i < n; i++) {
            perm[i] = in.nextInt() - 1;
        }
        for (int i = 0; i < n; i++) {
            A[i] = in.next();
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                comp = new ArrayList<>();
                idx = new ArrayList<>();
                dfs(i);
                Collections.sort(comp);
                Collections.sort(idx);
                for (int j = 0; j < comp.size(); j++) {
                    perm[idx.get(j)] = comp.get(j);
                }
            }
        }

        for (int i : perm) {
            out.print(i + 1 + " ");
        }

        out.close();
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
