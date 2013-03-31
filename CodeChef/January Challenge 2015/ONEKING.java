import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            int n = in.nextInt();
            List<Integer>[] begin = new List[2005];
            for (int i = 0; i < begin.length; i++) {
                begin[i] = new ArrayList<>();
            }
            int[] end = new int[2005];
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                begin[a].add(b);
                ++end[b];
            }
            int ans = 0;
            List<Integer> queue = new ArrayList<>();
            for (int i = 0; i < begin.length; i++) {
                queue.addAll(begin[i]);
                if (end[i] > 0) {
                    ++ans;
                    for (Integer j : queue) {
                        --end[j];
                    }
                    queue.clear();
                }
            }
            out.println(ans);
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
