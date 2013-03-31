ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

ll lca(ll a, ll b)
{
    return a * b / gcd(a, b);
}

class PyramidSequences
{
public:
    static long long distinctPairs(int n, int m)
    {
        ll N = (ll)(n - 1), M = (ll)(m - 1);
        if (N < M)
            swap(N, M);
        ll X = lca(N, M);
        ll Y = X / M;
        ll ans = Y * M + 1;
        ll Z = (N + M - 1) / M;
        int pos = 0;
        for (int i = 0; Y > 0; i++)
        {
            bool fl = !((N - pos) / M >= Z - 1);
            ans -= i * min(Y, Z - (int)fl);
            Y -= Z - (int)fl;
            pos = (pos + (Z - (int)fl) * M) % N;
        }
        return ans;
    }
};
