"""Implement a program that calculates the minimum number of coins required to give a user change.

$ python cash.py
Change owed: 0.41
4
"""

import cs50 as cs
import math

flag = True
while flag:
    balance = cs.get_float("Change owed: ") # Get user input in float (dollars)
    if balance > 0:
        flag = False
balance = balance * 100

quarters, dimes, nickel, pennies = 0, 0, 0, 0
quarters = math.floor(balance / 25) # Calculate how many 25 can divide by, whole number is the number of quarters to give as change
balance = balance - quarters * 25
dimes = math.floor(balance / 10)
balance = balance - dimes * 10
nickel = math.floor(balance / 5)
balance = balance - nickel * 5
pennies = balance

coins = quarters + dimes + nickel + pennies
print(int(coins))

