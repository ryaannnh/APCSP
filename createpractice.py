import os, random, time, datetime
os.system('clear')
# Arrays to store words as strings
beginner=["cat", "dog", "hat", "book", "sun", "moon", "pen", "car", "tree", "chair", "bed", "cup", "ball", "bird", "fish", "egg", "milk", "cake", "shoe", "hand", "nose", "eye", "ear", "mouth", "hair", "leg", "arm", "foot", "finger", "toe", "smile", "happy", "sad", "hot", "cold", "big", "small", "old", "new", "good", "bad", "red", "blue", "green", "yellow", "black", "white", "purple", "pink"]
intermmediate=["science", "history", "politics", "culture", "technology", "environment", "economy", "society", "psychology", "philosophy", "literature", "language", "education", "media", "religion", "health", "energy", "physics", "chemistry", "biology", "geology", "geography", "astronomy", "mathematics", "statistics", "programming", "engineering", "architecture", "transportation", "communication", "management", "leadership", "innovation", "creativity", "entrepreneurship", "globalization", "diversity", "equality", "justice", "ethics", "morality", "aesthetics", "art", "music", "film", "theater", "dance", "fashion", "cuisine"]
advanced=["metaphysics", "epistemology", "ontology", "phenomenology", "hermeneutics", "semiotics", "deconstruction", "postmodernism", "existentialism", "feminism", "postcolonialism", "psychoanalysis", "linguistics", "cognitive", "cybernetics", "robotics", "nanotechnology", "nanoscience", "biotechnology", "biochemistry", "genetics", "microbiology", "virology", "immunology", "pharmacology", "neurobiology", "neurochemistry", "neuroscience", "psychopharmacology", "epidemiology", "biostatistics", "bioinformatics", "genomics", "proteomics", "metabolomics", "glycomics", "transcriptomics", "interactomics", "computational", "informatics", "cybersecurity", "cryptography", "quantum", "astrophysics", "astrobiology"]
history = ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '']
def Menu():
    global lives, count, log, date # Declare global variables that can be used across functions
    count = 0
    log = 0 # Presetting values
    lives = 5
    os.system('clear') # Clear terminal
    # Print menu
    print(" __________________________\n|                          |\n|     W O R D G U E S S    |\n|  ______________________  |\n| pick from the following: |\n|                          |\n|  1. BEGINNER             |\n|  2. INTERMMEDIATE        |\n|  3. ADVANCED             |\n|  4. SCOREBOARD           |\n|  5. INSTRUCTIONS         |\n|  6. EXIT                 |\n|                          |\n ——————————————————————————\n\n")
    selection = input("Input: ") # User input

    if '1' in selection: # If beginner mode selected
        os.system('clear')
        wordselect(beginner) # Pick word out of beginner words (see function)
        printpattern() # Print pattern function for first time, before auto run in loop below

        while (lives > 0) or (count != len(word)): # Continue until either died, or word successfuly guessed
            guessFunction() # Take user guess
            os.system('clear')
            printpattern()
            if (count >= len(word)): # Count tracks the number of correct letters guessed. Player wins when count = wordlength
                os.system('clear')
                print("You are the winner!\n")
                scoreinput(5)
                time.sleep(3)
                input("Hit enter when you are ready to return to the menu: ") # Next line when any input entered
                Menu() # Return to menu if desired
            elif (lives <= 0): # Player loses if out of lives
                os.system('clear')
                print("You died. The correct word was -> ", end = '')
                print(word)
                print("Better luck next time~\n")
                time.sleep(3)
                input("Hit enter when you are ready to return to the menu: ")
                Menu() # Return to menu if desired

    elif '2' in selection:
        os.system('clear')
        wordselect(intermmediate) # Word selection from intermmediate list
        printpattern()
        # See beginners remarks for explanation
        while (lives > 0) or (count != len(word)):
            guessFunction()
            os.system('clear')
            printpattern()
            if (count >= len(word)):
                os.system('clear')
                print("You are the winner!\n")
                scoreinput(10)
                time.sleep(3)
                input("Hit enter when you are ready to return to the menu: ") # Next line when any input entered
                Menu() # Return to menu if desired
            elif (lives <= 0):
                os.system('clear')
                print("You died. The correct word was ->", end = '')
                print(word)
                print("Better luck next time~\n")
                time.sleep(3)
                input("Hit enter when you are ready to return to the menu: ") # Next line when any input entered
                Menu() # Return to menu if desired


    elif '3' in selection:
        os.system('clear')
        wordselect(advanced)
        printpattern()

        while (lives > 0) or (count != len(word)):
            guessFunction()
            os.system('clear')
            printpattern()
            if (count >= len(word)):
                os.system('clear')
                print("You are the winner!\n")
                scoreinput(20)
                time.sleep(3)
                input("Hit enter when you are ready to return to the menu: ") # Next line when any input entered
                Menu() # Return to menu if desired
            elif (lives <= 0):
                os.system('clear')
                print("You died. The correct word was ->", end = '')
                print(word)
                print("Better luck next time~\n")
                time.sleep(3)
                input("Hit enter when you are ready to return to the menu: ") # Next line when any input entered
                Menu() # Return to menu if desired
    elif '4' in selection:
        os.system('clear')
        try:
            with open("scoreBoard.txt", "r") as scorefile:
                lines = scorefile.readlines()
            lines.sort()
            for line in lines:
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

def printpattern():
    os.system('clear')
    # Print prompting dialogue with brackets and symbols based on length of word
    print(" ", end = '') # Print space without new line
    print("^" * (len(word) * 4)) # Print ^ 4 times the wordlength with newline
    print("(", end = '') # Print open bracket without newline
    print(" " * ((len(word) * 4) - 6), end = '') # Print middle spaces without new line, 6 less than top bracket to account for 6 characters lives display
    print("♥ = ", end = '') # Print heart static portion
    print(lives, end = '') # Print value of lives variable
    print(" )") # Closing bracket
    print("(", end = '')
    print(" " * ((len(word)) * 4), end = '')
    print(")")
    print("(", end = '')
    print(" " * (len(word)), end = '')
    for p in range((len(dash))): # Print value in dashes array that changes as game proceeds
        print(dash[p], end = '')
    print(" " * (len(word)), end = '')
    print(")")
    print("(", end = '')
    print(" " * ((len(word)) * 4), end = '')
    print(")")
    print(" ", end = '')
    print("v" * (len(word) * 4)) # Bottom closing v to close dialogue
    return


def wordselect(difficulty):
    global word, dash # Declare global variables
    word = random.choice(difficulty) # Use choice function from random library to pick word out of specific difficulty array

    dash = [' '] * ((len(word))*2) # Initialize dash variable to store dashes
    for l in range((len(word))):
        dash[(l*2)-1] = '_' # Store dashes in the places they should be at



def instructions():
        os.system('clear')
        print("Welcome to WordGuess!\n\n") # Print instructions with break in between lines
        time.sleep (2)
        print("The objective of the game is for you to correctly guess a randomly chosen word.\n\n")
        time.sleep (2)
        print("At the start of the game, blank dashes will be displayed. This shows the length of your word.\n\n")
        time.sleep (2)
        print("Simply enter a letter you believe may be in the word, and hit enter. You may only enter a single letter at once!\n\n")
        time.sleep (2)
        print("But, be careful. You only have a few chances to pick a wrong word.\n\n")
        time.sleep (2)
        print("Your remaining lives are displayed on the top right corner. Every time you make a wrong guess, a life will be deducted.\n\n")
        time.sleep (2)
        print("The game will end when you either fully guess the word, or you run out of lives.\n\n")
        time.sleep (2)
        print("At any time, feel free to enter the number '0' for the menu.\n\n")
        time.sleep (3)
        try:
            input("Hit enter when you are ready to return to the menu: ")
            Menu() # Return to calling function when done with instructions
        except ValueError:
            Menu()

def guessFunction():
    global guess, count, lives, log, history # Global so change will affect all across program, no need return
    check = True # Boolean variable to determine variable valid or not
    while check: # Keep asking user to enter new letter if it is invalid
        try: # Do everything in try so no crash. If anything wrong in try, jump to except
            guess = input("Enter a letter to guess the word: ")
            guess = guess.lower()
            if guess.isalpha() and len(guess)==1:
                check = False # Make check False when input valid, to exit loop
                for k in range(log):
                    if guess == history[k]:
                        check = True # Check if word has already been asked before. If asked, then check = True to keep looping
                        print("You have already entered this letter.") # Error message

            else:
                print("Please enter a valid letter.") # Error message
        except ValueError:
            print("Please enter a valid letter.") # Backup error message

    history[log] = guess
    log = log + 1
    print(log)
    print(history)

    correct = False # Initialize boolean variable
    try: # Do everything in try so can jump to except if anything happens
        for k in range(len(word)): # Loop through and compare to every letter in word
            if word[k] == guess: # If user input matches a letter
                dash[(k*2)+1] = guess # Update dash array to change print dialogue for player visual
                correct = True # Change boolean to true to not reduce lives
                count = count + 1 # Keep count of correct letters guessed to know if win
        if correct == False: # If no matches
            lives = lives - 1 # Lives - 1
            return # Return to calling function
    except ValueError:
        lives = lives - 1 # Backup of reduce lives
        return

def scoreinput(addscore):
    date = datetime.datetime.now() # Store date in 'date' variable
    name = input("What is your name: \n") # User input to get user's name
    scoreLine = str(addscore) + "\t" + name + "\t" + date.strftime('%m/%d/%Y' + '\n') # Convert score to a string and create the output sequence. Score first makes it easiest to sort
    with open("scoreBoard.txt", "a") as file:
        file.write(scoreLine)

Menu() # Running the menu function which is like the main. Must be after all functions.
