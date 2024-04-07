s = input().upper()
c = []
for i in range(65, 91):
    c.append(s.count(chr(i)))
print('?' if c.count(max(c)) > 1 else chr(c.index(max(c)) + 65))