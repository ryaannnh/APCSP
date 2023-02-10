# Objective: to recreate Mario in Python.
# Pseudocode in remark after each line
# Ryan Ho 2/7/23

import cs50

flag = True  # flag for determining if height qualifies
while flag:  # repeat until flag is switched to false
    height = input("Height: ")  # input is always a string, so need to do int() to typecast
    if height.isnumeric():  # to check if input is numeric before converting to int
        height = int(height)
        if height < 9 and height > 0:  # only compare for number range if confirmed it is a number. Or else there would be error when comparing str to int
            flag = False  # switch flag to false if requirements fulfilled
    x = 1


for i in range(height):  # for "height" number of rows
    for p in range(height-i-1):  # For loop to print spaces
        print(" ", end = '')  # Print two spaces without new line
    for j in range(i+1):  # Print hashtags
        print("#", end = '')
    print("  ", end='')  # Print space between hashtag
    for k in range(i+1):  # print remaining hashtag
        print("#", end = '')
    print() #print newline
