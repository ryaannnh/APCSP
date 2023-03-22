import os, random, time, datetime
os.system('clear')

def Menu():
    global lives, count, log, date # Declare global variables that can be used across functions
    count = 0
    log = 0 # Presetting values
    lives = 5
    os.system('clear') # Clear terminal
    animation()
    # Print menu
    print(" __________________________\n|                          |\n|     C A R D M A T C H    |\n|  ______________________  |\n| pick from the following: |\n|                          |\n|  1. BEGINNER             |\n|  2. INTERMMEDIATE        |\n|  3. ADVANCED             |\n|  4. SCOREBOARD           |\n|  5. INSTRUCTIONS         |\n|  6. EXIT                 |\n|                          |\n ——————————————————————————\n\n")
    selection = input("Input: ") # User input

    if '1' in selection: # If beginner mode selected
        os.system('clear')
        randomize(4) # Generate matrix containing cards
        display(4)


    elif '2' in selection:
        os.system('clear')
        randomize(6) # Generate matrix containing cards
        display(6)



    elif '3' in selection:
        os.system('clear')
        randomize(8) # Generate matrix containing cards
        display(8)

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

  #  for i in range(difficulty):
   #     for j in range(difficulty):
    #        print(cards[i][j], end = " ")
     #   print('')

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
    global cards, copy, lives
    turn = 1
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
    global column, row
    while alpha == False:
        column = input("Please select a column:")
        if isalpha(column):
            alpha = True
        # add check to check if within range
    while valid == False:
        row = input("Please select a row:")
        if # in range:
            valid = True

def update()
    # for updating copy array using coordinate


Menu()
