import cs50

height = int(input("Height: ")) #input is always a string, so need to do int() to typecast
x = 1
for i in range(height+1):
    for p in range(height-i):
        print(" ", end = '')
    for j in range(i):
        print("#", end = '')
    print(" ", end='')
    for k in range(i):
        print("#", end = '')
    print()
