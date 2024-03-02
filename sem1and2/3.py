import itertools
f = open("output.txt", "w")
a = []
a = itertools.product('ABCDEFGHIJKLMNOPQRSTUVWXYZ', repeat=7)
for i in a:
    a = str(i)
    a = a.replace("'", "")
    a = a.replace("(", "")
    a = a.replace(",", "")
    a = a.replace(")", "")
    a = a.replace(" ", "")
    f.write(a)
    f.write('\n')
f.close()
