import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Created by witalia on 12.12.14.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = in.nextInt();
            }

            int[] suff = new int[n];
            int[] pref = new int[n];
            suff[n - 1] = a[n - 1];
            pref[0] = a[0];

            for (int j = 1; j < n; j++) {
                pref[j] = gcd(pref[j - 1], a[j]);
                suff[n - j - 1] = gcd(suff[n - j], a[n - j - 1]);
            }
            // System.out.println(Arrays.toString(pref));
            // System.out.println(Arrays.toString(suff));

            for (int j = 0; j < q; j++) {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                int ans = 0;
                if (l > 0) {
                    ans = gcd(pref[l - 1], ans);
                }
                if (r + 1 < n) {
                    ans = gcd(suff[r + 1], ans);
                }
                out.println(ans);
            }
        }
        out.close();
    }

    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
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
