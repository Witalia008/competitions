n = int(raw_input())
seq = raw_input().split(" ")
ans = 0
for i in range(0, n):
    for j in range(i, n):
        ans = max(ans, seq[0:i].count("1") + seq[i : j + 1].count("0") + seq[j + 1 : n].count("1"))
print ans
