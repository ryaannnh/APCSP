import cs50

def main():
    while True:
        cardno = int(input("Enter your credit card number: "))
        if cardno >= 0:
            break # Keep asking until valid number

    if check(cardno): # Compare with the stated rule that requires last digit of special sum to be 0
        result(cardno) # print result card type if fits the rules
    else:
        print("INVALID")

def check(number):
    return checkresult(number)

def checkresult(number):
    sum = 0
    for i in range(len(str(number))): # Convert into string to use len() function
        if (i % 2 == 0):
            sum += number % 10
        else:
            digit = 2*(number % 10)
            sum = sum + (digit // 10 + digit % 10) # // for integer division
        number = number // 10
    return sum % 10 == 0

def result(number):
    if (number >= 34e13 and number < 35e13) or (number >= 37e13 and number < 38e13): # Check beginning digits of cardno
        print("AMEX")
    elif number >= 51e14 and number < 56e14:
        print("MASTERCARD")
    elif (number >= 4e12 and number < 5e12) or (number >= 4e15 and number < 5e15):
        print("VISA")
    else:
        print("INVALID")

main()
