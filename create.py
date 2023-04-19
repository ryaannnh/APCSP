import os, random, time, datetime
os.system('clear')

def Menu():
    global turn, count, log, date, corrects # Declare global variables that can be used across functions
    count = 0
    log = 0 # Presetting values
    turn = 1 # Game starts on the first turn
    corrects = 0 # Game starts with 0 correct guesses
    os.system('clear') # Clear terminal
    animation() # Play starting animation
    os.system('clear') # Clear starting animation residual
    # Print menu
    print(" __________________________\n|                          |\n|     C A R D M A T C H    |\n|  ______________________  |\n| pick from the following: |\n|                          |\n|  1. EASY                 |\n|  2. INTERMMEDIATE        |\n|  3. ADVANCED             |\n|  4. EXPERT               |\n|  5. SCOREBOARD           |\n|  6. INSTRUCTIONS         |\n|  7. EXIT                 |\n|                          |\n ——————————————————————————\n\n")
    selection = input("Input: ") # User input from menu, assigned to 'selection' variable

    if '1' in selection: # If easy mode selected
        os.system('clear')
        randomize(2) # Generate matrix containing cards
        display(2) # Display card backs and game turn according to format outlined in 'display' function
        prompt(2) # Prompt for user input
        print("CONGRATULATIONS, YOU WON!")
        scoreinput(2) # Add score to scoreboard
        time.sleep(2)
        input("Hit enter to return to the menu") # User confirmation to reprompt menu
        Menu()


    if '2' in selection: # If beginner mode selected
        os.system('clear')
        randomize(4) # Generate matrix containing cards
        display(4) # Display card backs and game turn according to format outlined in 'display' function
        prompt(4) # Prompt for user input
        print("CONGRATULATIONS, YOU WON!")
        scoreinput(4) # Add score to scoreboard
        time.sleep(2)
        input("Hit enter to return to the menu") # User confirmation to reprompt menu
        Menu()

    elif '3' in selection:
        os.system('clear')
        randomize(6) # Generate matrix containing cards
        display(6) # Display card backs and game turn according to format outlined in 'display' function
        prompt(6) # Prompt for user input
        print("CONGRATULATIONS, YOU WON!")
        scoreinput(6) # Add score to scoreboard
        time.sleep(2)
        input("Hit enter to return to the menu") # User confirmation to reprompt menu
        Menu()

    elif '4' in selection:
        os.system('clear')
        randomize(8) # Generate matrix containing cards
        display(8) # Display card backs and game turn according to format outlined in 'display' function
        prompt(8) # Prompt for user input
        print("CONGRATULATIONS, YOU WON!")
        scoreinput(8) # Add score to scoreboard
        time.sleep(2)
        input("Hit enter to return to the menu") # User confirmation to reprompt menu
        Menu()

    elif '5' in selection:
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

    elif '6' in selection:
        instructions()

    elif '7' in selection: # If player wants to exit
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
    used = []
    copy = [["🂠" for j in range(difficulty)] for i in range(difficulty)]
    options = ["🃄", "🂡", "🂢", "🂣", "🂤", "🂥", "🂦", "🂧", "🂨", "🂩", "🂪", "🂫", "🂬", "🂭", "🂮", "🂱", "🂲", "🂳", "🂴", "🂵", "🂶", "🂷", "🂸", "🂹", "🂺", "🂻", "🂽", "🂾", "🃁", "🃂", "🃃", "🃅"]
    cards = [["" for j in range(difficulty)] for i in range(difficulty)]
    cardselect = random.sample(options, (difficulty**2)//2)
    for i in range(difficulty):
        for j in range(difficulty):
            invalid = True
            while invalid:
                choice = random.choice(cardselect)
                if used.count(choice) < 2:
                    invalid = False
            used.append(choice)
            cards[i][j] = choice

    for i in range(difficulty):
        for j in range(difficulty):
            print(cards[i][j], end = " ")
        print('')

def instructions():
        os.system('clear')
        print("Welcome to CARDMATCH!\n\n") # Print instructions with break in between lines
        time.sleep (1)
        print("The objective of the game is for you to match all cards in as few turns as possible.\n\n")
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
        print("Your rcurrent turn is displayed on the top right corner.\n\n")
        time.sleep (1)
        print("The game will end when all cards are matched.\n\n")
        time.sleep (1)
        print("You will receive a score based on the difficulty, and the number of turns you took.\n\n")
        time.sleep (1)
        print("This score will be stored in the scoreboard and be visible to other players.\n\n")
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
    difficulties = {
        2: ["a","b"],
        4: ["a","b","c","d"],
        6: ["a","b","c","d","e","f"],
        8: ["a","b","c","d","e","f","g","h"]
    }
    while (corrects < ((difficulty**2)/2)): # Calculate number of correct turns needed to win
        for i in range(2):
            repeat = True
            while repeat == True:
                alpha = False
                valid = False
                while alpha == False:
                    column = input("Please select a column: ")
                    column = column.lower()
                    if column.isalpha():
                        if column in difficulties[difficulty]:
                            alpha = True
                columnno = int(ord(column) - 96); # Turn column letter into a number

                while valid == False:
                    try:
                        row = int(input("Please select a row: "))
                        if (row <= difficulty):
                            valid = True
                    except ValueError:
                        print("Try again") # Make uniform
                if (str(copy[row-1][columnno-1]) == "✖"): # If equal to X in copy, means that its already been guessed correctly before. Str mode for compare
                    print("You already guessed this correctly, try again!")
                    time.sleep(2)
                elif (str(copy[row-1][columnno-1]) != "🂠"): # If equal to X in copy, means that its already been guessed correctly before. Str mode for compare
                    print("Please select another card")
                    time.sleep(2)
                else:
                    repeat = False

            update(i+1,row-1, columnno-1) 

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


def update(turn, row, column):
    global card1, card2, c1, r1, c2, r2
    if turn == 1:
        copy[row][column] = cards[row][column]
        c1 = column
        r1 = row
        card1 = cards[row][column]
    elif turn == 2:
        copy[row][column] = cards[row][column]
        c2 = column
        r2 = row
        card2 = cards[row][column]
    elif turn == 3: # If correct
        copy[r1][c1] = "✖"
        copy[r2][c2] = "✖"
    elif turn == 4: # If wrong, reset back to card back
        copy[r1][c1] = "🂠"
        copy[r2][c2] = "🂠"

def match():
    global card1, card2, turn, corrects
    turn = turn + 1
    if (card1 == card2):
        corrects = corrects + 1
        return True
    elif (card1 != card2):
        return False

def scoreinput(difficulty):
    global turn
    score = difficulty * difficulty - turn + 2
    if score < difficulty:
        score = difficulty

    print("\nYour score is " + str(score) + " with a bonus of " + str(difficulty) + ".\n") # Print user score
    score = score + difficulty
    date = datetime.datetime.now() # Store date in 'date' variable
    name = input("What is your name: ") # User input to get user's name
    scoreLine = str(score) + "\t" + name + "\t\t" + date.strftime('%m/%d/%Y' + '\n') # Convert score to a string and create the output sequence. Score first makes it easiest to sort
    with open("scoreBoard.txt", "a") as file:
        file.write(scoreLine)

Menu()

