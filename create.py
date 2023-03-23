import os, random, time, datetime
os.system('clear')

def Menu():
    global turn, count, log, date, corrects # Declare global variables that can be used across functions
    count = 0
    log = 0 # Presetting values
    turn = 1
    corrects = 0
    os.system('clear') # Clear terminal
    animation()
    # Print menu
    print(" __________________________\n|                          |\n|     C A R D M A T C H    |\n|  ______________________  |\n| pick from the following: |\n|                          |\n|  1. BEGINNER             |\n|  2. INTERMMEDIATE        |\n|  3. ADVANCED             |\n|  4. SCOREBOARD           |\n|  5. INSTRUCTIONS         |\n|  6. EXIT                 |\n|                          |\n ——————————————————————————\n\n")
    selection = input("Input: ") # User input

    if '1' in selection: # If beginner mode selected
        os.system('clear')
        randomize(4) # Generate matrix containing cards
        display(4)
        prompt(4)
        print("CONGRATULATIONS, YOU WON!")
        time.sleep(2)
        input("Hit enter to return to the menu")
        Menu()


    elif '2' in selection:
        os.system('clear')
        randomize(6) # Generate matrix containing cards
        display(6)
        prompt(6)
        print("CONGRATULATIONS, YOU WON!")
        time.sleep(2)
        input("Hit enter to return to the menu")
        Menu()



    elif '3' in selection:
        os.system('clear')
        randomize(8) # Generate matrix containing cards
        display(8)
        prompt(8)
        print("CONGRATULATIONS, YOU WON!")
        time.sleep(2)
        input("Hit enter to return to the menu")
        Menu()

    elif '4' in selection:
        os.system('clear')
        try:
            with open("scoreBoard.txt", "r") as scorefile:
                lines = scorefile.readlines()
            lines.sort(reverse=True)
            for b in range(3):
                line = lines[b]
                print(line)
            input("Hit enter to return to the menu:")
        except FileNotFoundError:
            print("There is currently no valid score in the scoreboard.")
            time.sleep(3)
            input("Hit enter to return to the menu:")
        Menu()

    elif '5' in selection:
        instructions()

    elif '6' in selection: # If player wants to exit
        os.system('clear')
        print ("Thanks for playing!")
        exit()
    else:
        Menu() # If input was none of the above, reprompt menu

def animation():
    name = "CARDMATCH"
    for i in range(9):
        print(" " * i, name[i])
        time.sleep(0.1)
    time.sleep(1)
    return

def randomize(difficulty): # Make difficulty input a difficulty
    global cards, copy
    options4 = ["🂡","🂢","🂣","🂤","🂥","🂦","🂧","🂨"]
    options6 = ["🂡","🂢","🂣","🂤","🂥","🂦","🂧","🂨","🂩","🂪","🂫","🂭","🂮","🂱","🂲","🂳","🂴","🂵"]
    options8 = ["🂡","🂢","🂣","🂤","🂥","🂦","🂧","🂨","🂩","🂪","🂫","🂭","🂮","🂱","🂲","🂳","🂴","🂵","🂶","🂷","🂸","🂹","🂺","🂻","🂽","🂾","🃁","🃏"]
    cards = [['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','','']]
    copy = [['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','',''],['','','','','','','','','','','','','','','','']]
    used = ['','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','','']
    for i in range(difficulty):
        for j in range(difficulty):
            invalid = True
            while invalid == True: # Repeat until card picked that has not been used before
                if (difficulty == 4):
                    choice = random.choice(options4) # Pick random card
                if (difficulty == 6):
                    choice = random.choice(options6) # Pick random card
                if (difficulty == 8):
                    choice = random.choice(options8) # Pick random card
                x = used.count(choice) # Count how many times the choice was used in the used array
                if x < 2:
                    invalid = False # Flip boolean variable if not used twice to exit loop
            used.append(choice)
            cards[i][j] = choice
            copy[i][j] = "🂠"

    for i in range(difficulty):
        for j in range(difficulty):
            print(cards[i][j], end = " ")
        print('')

def instructions():
        os.system('clear')
        print("Welcome to CARDMATCH!\n\n") # Print instructions with break in between lines
        time.sleep (1)
        print("The objective of the game is for you to match all cards as quickly as possible.\n\n")
        time.sleep (1)
        print("In each turn, you can select two cards to flip.\n\n")
        time.sleep (1)
        print("To select a card, first enter the column and then the row when prompted.\n\n")
        time.sleep (1)
        print("If the cards don't match, you will lose a life and have to guess again.\n\n")
        time.sleep (1)
        print("If the cards match, you are one step cloesr to winning!\n\n")
        time.sleep (1)
        print("Cards that have been guessed will be replaced with a ✖ sign.\n\n")
        time.sleep (1)
        print("Your remaining lives are displayed on the top right corner.\n\n")
        time.sleep (1)
        print("The game will end when all cards are matched, or you run out of lives.\n\n")
        time.sleep(1)
        print("")
        time.sleep (2)
        try:
            input("Hit enter when you are ready to return to the menu: ")
            Menu() # Return to calling function when done with instructions
        except ValueError:
            Menu()

def display(length):
    global cards, copy, turn
    print(" " * int((int(length)*3)-8-int(len(str(turn)))), "⭐ Turn", str(turn))
    print(" ", end = '')
    axis = "abcdefghijklmnopqrstuvwxyz"
    for i in range(length):
        print(" ", axis[i], end = '')
    print()
    for i in range(length):
        print(i+1, " ", end = "")
        for j in range(length):
            print(copy[i][j], " ", end = '')
        print()

def prompt(difficulty):
    global column, row, card1, card2, corrects
    card1 = 0
    card2 = 0
    while (corrects < ((difficulty**2)/2)): # Calculate number of correct turns needed to win
        for i in range(2):
            alpha = False
            valid = False
            alpha4 = ["a","b","c","d"]
            alpha6 = ["a","b","c","d","e","f"]
            alpha6 = ["a","b","c","d","e","f","g","h"]
            while alpha == False:
                column = input("Please select a column: ")
                column = column.lower()
                if column.isalpha():
                    if difficulty == 4: # Check if input is valid
                        if column in alpha4:
                            alpha = True
                    if difficulty == 6:
                        if column in alpha6:
                            alpha = True
                    if difficulty == 8:
                        if column in alpha8:
                            alpha = True
            columnno = int(ord(column) - 96);

            while valid == False:
                try:
                    row = int(input("Please select a row: "))
                    if (row <= difficulty):
                        valid = True
                except ValueError:
                    print("Try again") # Make uniform

            update(i+1,row-1, columnno-1) #flipped because of glitched...

            if (i == 1): # If second turn
                if match():
                    os.system('clear')
                    display(difficulty)
                    update(3, 0, 0) # To turn copy into X, 0 as filler for arguments
                    print("You guessed correctly!")
                    time.sleep(2)
                else:
                    os.system('clear')
                    display(difficulty)
                    print("Wrong guess")
                    time.sleep(2)
                    update(4, 0, 0) # To reset copy

            os.system('clear')
            display(difficulty)


def update(turn, column, row):
    global card1, card2, c1, r1, c2, r2
    if turn == 1:
        copy[column][row] = cards[column][row]
        c1 = column
        r1 = row
        card1 = cards[column][row]
    elif turn == 2:
        copy[column][row] = cards[column][row]
        c2 = column
        r2 = row
        card2 = cards[column][row]
    elif turn == 3: # If correct
        copy[c1][r1] = "✖"
        copy[c2][r2] = "✖"
    elif turn == 4: # If wrong, reset back to card back
        copy[c1][r1] = "🂠"
        copy[c2][r2] = "🂠"

def match():
    global card1, card2, turn, corrects
    turn = turn + 1
    if (card1 == card2):
        corrects = corrects + 1
        return True
    elif (card1 != card2):
        return False





Menu()
