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
    print(" __________________________")
    print("|                          |")
    print("|     C A R D M A T C H    |")
    print("|  ______________________  |")
    print("| pick from the following: |")
    print("|                          |")
    print("|  1. EASY                 |")
    print("|  2. INTERMMEDIATE        |")
    print("|  3. ADVANCED             |")
    print("|  4. EXPERT               |")
    print("|  5. SCOREBOARD           |")
    print("|  6. INSTRUCTIONS         |")
    print("|  7. EXIT                 |")
    print("|                          |")
    print(" ——————————————————————————")
    selection = input("Input: ") # User input from menu, assigned to 'selection' variable
    difficulties = {
        '1': 2,
        '2': 4,
        '3': 6,
        '4': 8} # Dictionary with difficulties declared to simplify program

    if selection in difficulties: # If selection between 1-4, part of difficulties dictionary
        os.system('clear')
        difficulty = difficulties[selection] # Assign corresponding difficulty value to the variable
        randomize(difficulty) # Generate matrix containing cards
        display(difficulty) # Display card backs and game turn according to format outlined in 'display' function
        prompt(difficulty) # Prompt for user input
        print("CONGRATULATIONS, YOU WON!")
        scoreinput(difficulty) # Add score to scoreboard
        input("\nHit enter to return to the menu") # User confirmation to reprompt menu
        Menu()

    elif '5' in selection: # Scoreboard
        os.system('clear')
        try:
            print("\n")
            with open("scoreBoard.txt", "r") as scorefile: # Open file
                lines = scorefile.readlines() # Read file contents into lines
            lines.sort(reverse=True) # Sort the elements in lines
            for b in range(3): # Print top three lines
                line = lines[b]
                print(line)
            input("\nHit enter to return to the menu:")
        except FileNotFoundError: # If file does not exist
            print("There is currently no valid score in the scoreboard.")
            time.sleep(3)
            input("Hit enter to return to the menu:")
        Menu()

    elif '6' in selection:
        instructions() # Call instructions procedure to print instructions

    elif '7' in selection: # If player wants to exit
        os.system('clear')
        print ("Thanks for playing!") # Print message
        exit() # Exit program
    else:
        Menu() # If input was none of the above, reprompt menu

def animation():
    name = "CARDMATCH"
    print("\n")
    for i in range(9): # Print welcome animation
        print(" " * (5 + i), name[i]) # Increase number of spaces along the way, print letters one by one
        time.sleep(0.1)
    time.sleep(1)
    return

def randomize(difficulty): # Make difficulty input a difficulty
    global cards, copy
    used = []
    copy = [["🂠" for j in range(difficulty)] for i in range(difficulty)] # "copy" array with cardback symbol for every element in grid
    # Array containing all card symbols available for selection
    options = ["🃄", "🂡", "🂢", "🂣", "🂤", "🂥", "🂦", "🂧", "🂨", "🂩", "🂪", "🂫", "🂬", "🂭", "🂮", "🂱", "🂲", "🂳", "🂴", "🂵", "🂶", "🂷", "🂸", "🂹", "🂺", "🂻", "🂽", "🂾", "🃁", "🃂", "🃃", "🃅"]
    cards = [["" for j in range(difficulty)] for i in range(difficulty)] # Declaring "cards" array to store randomized cards
    cardselect = random.sample(options, (difficulty**2)//2) # Pick the required number of cards (number of unique cards needed) out of the "options" array
    for i in range(difficulty): # Iterating through matrix
        for j in range(difficulty):
            invalid = True
            while invalid:
                choice = random.choice(cardselect) # Randomly select a card out of the list of cards created based on the grid size
                if used.count(choice) < 2: # Checking if the selected card has been used less than twice (to pair up each card only once)
                    invalid = False # Acceptable card found: Exit loop of reselecting cards
            used.append(choice) # Add selection to the "used" array to keep track of how many times each card has been added to "cards"
            cards[i][j] = choice # Assign the randomly selected card to the next element on the "cards" array

def instructions():
        os.system('clear')
        print("Welcome to CARDMATCH!\n\n") # Print instructions with break in between lines
        time.sleep (0.6)
        print("The objective of the game is for you to match all cards in as few turns as possible.\n\n")
        time.sleep (0.6)
        print("In each turn, you can select two cards to flip.\n\n")
        time.sleep (0.6)
        print("To select a card, first enter the column and then the row when prompted.\n\n")
        time.sleep (0.6)
        print("If the cards don't match, you will lose a life and have to guess again.\n\n")
        time.sleep (0.6)
        print("If the cards match, you are one step cloesr to winning!\n\n")
        time.sleep (0.6)
        print("Cards that have been guessed will be replaced with a ✖ sign.\n\n")
        time.sleep (0.6)
        print("Your current turn is displayed on the top right corner.\n\n")
        time.sleep (0.6)
        print("The game will end when all cards are matched.\n\n")
        time.sleep (0.6)
        print("You will receive a score based on the difficulty, and the number of turns you took.\n\n")
        time.sleep (0.6)
        print("This score will be stored in the scoreboard and be visible to other players.\n\n")
        print("")
        time.sleep (1.5)
        try:
            input("Hit enter when you are ready to return to the menu: ")
            Menu() # Return to calling function when done with instructions
        except ValueError:
            Menu()

def display(length): # Prompt for displaying user interface
    global cards, copy, turn
    print(" " * int((int(length)*3)-8-int(len(str(turn)))), "⭐ Turn", str(turn)) # Print turn value with required spaces before it
    print(" ", end = '')
    axis = "abcdefghijklmnopqrstuvwxyz"
    for i in range(length):
        print(" ", axis[i], end = '') # Print column labels
    print()
    for i in range(length):
        print(i+1, " ", end = "") # Print row labels
        for j in range(length):
            print(copy[i][j], " ", end = '') # Print copy matrix containing cards users should view
        print()

def prompt(difficulty):
    global column, row, card1, card2, corrects, turn
    card1 = 0
    card2 = 0
    difficulties = {
        2: ["a","b"],
        4: ["a","b","c","d"],
        6: ["a","b","c","d","e","f"],
        8: ["a","b","c","d","e","f","g","h"]
    } # Difficulties dictionary containing valid column inputs based on diffulties
    while (corrects < ((difficulty**2)/2)): # Repeat while the number of matched cards is less than the number needed to win
        for i in range(2): # Repeat twice for the two cards in each turn
            repeat = True
            while repeat == True:
                alpha = False
                valid = False
                while alpha == False:
                    column = input("Please select a column: ") # Input for column
                    column = column.lower() # Standardized for easy processing
                    if column.isalpha():
                        if column in difficulties[difficulty]: # Checked for in-range
                            alpha = True
                        else:
                            print("Out of range")
                columnno = int(ord(column) - 96); # Turn column letter into a number

                while valid == False:
                    try:
                        row = int(input("Please select a row: ")) # Input for row
                        if (row <= difficulty) and (row > 0): # Checked for validity
                            valid = True
                        else:
                            print("Out of range")
                    except ValueError:
                        print("Out of range") # Make uniform
                if (str(copy[row-1][columnno-1]) == "✖"): # If equal to X in copy, means that its already been guessed correctly before. Str mode for compare
                    print("You already guessed this correctly, try again!")
                    time.sleep(2)
                    os.system('clear')
                    display(difficulty)
                elif (str(copy[row-1][columnno-1]) != "🂠"): # If not equal to card-back, means card has already been selected, reprompt
                    print("Please select another card")
                    time.sleep(2)
                    os.system('clear')
                    display(difficulty)
                else:
                    repeat = False

            update(i+1,row-1, columnno-1) # Calls the "update" function to update "copy" matrix with user selection

            if (i == 1): # After second valid card selected
                if match(): # If cards are matching
                    os.system('clear') # Clear terminal
                    display(difficulty) # Display updated interface
                    update(3, 0, 0) # Calls "update" to update matched cards into "✖", "0" do not affect result
                    print("You guessed correctly!")
                    time.sleep(2)
                else: # If cards do not match
                    os.system('clear')
                    display(difficulty)
                    print("Wrong guess") # User notified
                    time.sleep(2) # Keep message for two seconds
                    update(4, 0, 0) # Calls "update" to restore failed to match cards to card-backs "🂠"
                turn = turn + 1 # Increase turn value

            os.system('clear')

            display(difficulty)


def update(turn, row, column):
    global card1, card2, c1, r1, c2, r2
    if turn == 1: # If first of two cards
        copy[row][column] = cards[row][column] # Card revealed by replacing the card-back in "copy" with the card's symbol from "cards"
        c1 = column # Update global variables with location of selection
        r1 = row
        card1 = cards[row][column] # Update global variable with symbol of first selection
    elif turn == 2:
        copy[row][column] = cards[row][column] # Card revealed to user by updating "copy" matrix
        c2 = column # Update global variables with location of selection
        r2 = row
        card2 = cards[row][column] # Update global variable with symbol of first card
    else:
        for r, c in [(r1, c1), (r2, c2)]: # Declare list of tuples, assign to "r", "c" in loop
            if turn == 3: # If matching
                copy[r][c] = "✖" # Update two selected cards to "✖"
            elif turn == 4: # If not matching
                copy[r][c] = "🂠" # Restore selected cards to card-back, "🂠"

def match():
    global card1, card2, corrects
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

