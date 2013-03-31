import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            long n = in.nextInt();
            int k = in.nextInt();
            long[] arr = new long[k];
            for (int i = 0; i < arr.length; i++) {
                arr[i] = in.nextInt();
            }
            Arrays.sort(arr);
            long sum = 0;
            long firstMissing = -1;
            for (int i = 0; i < arr.length; i++) {
                // Find next existing
                sum += arr[i];
                while (i + 1 < arr.length && arr[i] == arr[i + 1] - 1) {
                    sum += arr[++i];
                }
                long nextExisting = Long.MAX_VALUE;
                if (arr[i] != n) {
                    nextExisting = arr[i] + 1;
                }
                // Find sum of all existing up to current missing
                long curSum = arr[i] * (arr[i] + 1) / 2 - sum;
                // Check condition for first missing sum
                if (curSum + 1 < nextExisting) {
                    firstMissing = curSum + 1;
                    break;
                }
            }
            if (firstMissing == -1) {
                firstMissing = n * (n + 1) / 2 + 1 - sum;
            }
//            out.println(firstMissing);
            out.println(firstMissing % 2 == 1 ? "Chef" : "Mom");
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
