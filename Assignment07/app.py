

year_total = 0

with open("people.txt", "r") as f:
    a = f.read()
    b = a.split("\n")
    c = b[1:-1]
    for i in c:
        d = i.split("\t")
        year_total += int(d[0])

print(year_total)

