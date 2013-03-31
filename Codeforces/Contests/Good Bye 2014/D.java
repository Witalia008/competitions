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

        new Solver().solve(1, in, out);

        out.close();
    }
}

class Solver {
    class City {
        int number;
        List<Road> roads = new ArrayList<>();
        int subTreeSize;

        public City(int number) {
            this.number = number;
        }

        public void dfs(City parent) {
            subTreeSize = 1;
            for (Road r : roads) {
                if (r.to != parent) {
                    r.to.dfs(this);
                    subTreeSize += r.to.subTreeSize;
                }
            }
        }
    }

    class Road {
        City from;
        City to;
        int weight;
        long value;

        public Road(City from, City to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        City[] cities = new City[n];
        for (int i = 0; i < n; i++) {
            cities[i] = new City(i);
        }
        Road[] roads = new Road[n - 1];
        for (int i = 0; i < n - 1; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            int w = in.nextInt();

            City a = cities[u];
            City b = cities[v];
            Road ab = new Road(a, b, w);
            Road ba = new Road(b, a, w);

            a.roads.add(ab);
            b.roads.add(ba);
            roads[i] = ab;
        }

        cities[0].dfs(null);

        double ans = 0;
        for (int i = 0; i < n - 1; i++) {
            Road cur = roads[i];
            City lower = cur.from;
            if (cur.to.subTreeSize < lower.subTreeSize) {
                lower = cur.to;
            }
            cur.value = 6L * lower.subTreeSize * (n - lower.subTreeSize);
            ans += 1.0 * cur.value * cur.weight / n / (n - 1);
        }

        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int pos = in.nextInt() - 1;
            int newVal = in.nextInt();
            Road cur = roads[pos];
            ans += 1.0 * cur.value * (newVal - cur.weight) / n / (n - 1);
            cur.weight = newVal;

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
