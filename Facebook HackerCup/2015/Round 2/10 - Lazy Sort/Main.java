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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int _t = 0; _t < t; _t++) {
            out.print("Case #" + (_t + 1) + ": ");

            int n = in.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt() - 1;
            }
            boolean ans = tryIt(arr, 0) || tryIt(arr, 1);
            out.println(ans ? "yes" : "no");
        }
    }

    private boolean tryIt(int[] arr, int i) {
        int l = 0, r = arr.length - 1;
        int L, R;
        L = R = (i == 0 ? arr[l++] : arr[r--]);
        while (l <= r) {
            boolean curMove = false;
            while (l <= r && (arr[l] == L - 1 || arr[l] == R + 1)) {
                if (arr[l++] == L - 1) --L; else ++R;
                curMove = true;
            }
            while (l <= r && (arr[r] == L - 1 || arr[r] == R + 1)) {
                if (arr[r--] == L - 1) --L; else ++R;
                curMove = true;
            }
            if (!curMove) {
                return false;
            }
        }
        return true;
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
