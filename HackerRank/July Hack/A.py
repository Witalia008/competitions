# Enter your code here. Read input from STDIN. Print output to STDOUT
s = raw_input()
cnt_odd = 0
alph = "qwertyuioplkjhgfdsazxcvbnm"
for i in alph:
    cnt_odd += s.count(i) % 2
print "YES" if cnt_odd < 2 else "NO"
