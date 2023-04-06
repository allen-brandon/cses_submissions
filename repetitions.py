dna = input()
n = len(dna)
l, msf = 0, 0
for r in range(n):
    if dna[r] != dna[l]: l = r
    msf = max(msf, r+1-l)
print(msf)