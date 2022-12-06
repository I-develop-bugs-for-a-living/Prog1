

jahre_gesamt = 0

mit open("people.txt", "r") as f:
    a = f.read()
    b = a.split("\n")
    c = b[1:-1]
    lass i inwendig c:
        d = i.split("\t")
        jahre_gesamt += int(d[0])

print(jahre_gesamt)

