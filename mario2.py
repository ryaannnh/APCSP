import cs50

flag = True
while flag:
    height = int(input("Height: "))
    if height < 9 and height > 0:
        flag = False

    for i in range(height):
        print(" "* (height-i-1), end='')
        print("#"*(i+1), end="  ")
        print("#"*(i+1))
