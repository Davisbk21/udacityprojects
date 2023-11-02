import time
import random


def print_pause(message):
    print(message)
    time.sleep(2)


def intro(items, enemy):
    print_pause("You find yourself standing in an open field, "
                "filled with grass and yellow wildflowers.")
    print_pause(f"Rumor has it that {enemy} is somewhere around "
                "here, and has been terrorizing the village.")
    print_pause("In front of you is a house.")
    print_pause("To your right is a dark cave.")
    print_pause("In your hand you hold your trusty "
                "(but not very effective) dagger.\n")


def play_again():
    print_pause("GAME OVER")
    print_pause("Would you like to play again?")
    response = input("(y/n)\n")
    if 'y' in response:
        print_pause("Excellent! Restarting the game...")
        adventure_game()
    elif 'n' in response:
        print_pause("Thank you for playing!")
    else:
        print_pause("Not a valid response, please re-enter")
        play_again()


def field(items, enemy):
    print_pause("Enter 1 to knock on the door of the house.")
    print_pause("Enter 2 to peer into the cave.")
    print_pause("What would you like to do?")
    response = input("(Please enter 1 or 2)\n")
    if response == '1':
        house(items, enemy)
    elif response == '2':
        cave(items, enemy)
    else:
        print_pause("Not a valid response, please re-enter")
        field(items, enemy)


def stalemate(items, enemy):
    print_pause(f"You and {enemy} cast your spells at the same time "
                "sending sparks and flames shooting everywhere!")
    print_pause("What will you do now?!")
    attack(items, enemy)


def attack(items, enemy):
    response = input("Enter 1 to cast Avada Kedavra \n"
                     "Enter 2 to cast Stupify\n"
                     "Enter 3 to cast Expelliarmus\n")
    if response == '1':
        if 'stupify' and 'expelliarmus' in items:
            print_pause("AVADA KEDAVRA!!!")
            print_pause("A powerful green light bursts from the Elder Wand "
                        f"and strikes {enemy} in the chest!")
            print_pause(f"{enemy} falls to the ground and disintegrates...")
            print_pause(f"You have defeated {enemy} and saved the village!")
            play_again()
        else:
            stalemate(items, enemy)

    elif response == '2':
        print_pause("Stupify!")
        print_pause(f"A quick white flash hits {enemy}, "
                    "resulting in a paralyzing stun!")
        print_pause(f"Hurry! While {enemy} is stunned, make your next move!")
        items.append('stupify')
        attack(items, enemy)
    elif response == '3':
        if "stupify" in items:
            print_pause(f"While {enemy} is still stunned "
                        "you cast your spell, Expelliarmus!")
            print_pause(f"{enemy}'s wand flies out of his hand "
                        "rolling far across the room!")
            items.append('expelliarmus')
            print_pause("What will you do now?!")
            attack(items, enemy)
        else:
            stalemate(items, enemy)
    else:
        print_pause("Not a valid response, please re-enter")
        attack(items, enemy)


def house(items, enemy):
    print_pause("You approach the door of the house.")
    print_pause("You are about to knock when the door "
                f"opens and out steps {enemy}.")
    print_pause(f"Eek! This is the {enemy}'s house!")
    print_pause(f"{enemy} attacks you!")
    if 'wand' in items:
        print_pause("Would you like to (1) fight or (2) run away?")
        response = input("(Please enter 1 or 2)\n")
        if response == '1':
            print_pause(f"As {enemy} moves to attack, you pull "
                        "out the Elder Wand and cast your spell!")
            attack(items, enemy)

        elif response == '2':
            print_pause("You run back into the field. Luckily, "
                        "you don't seem to have been followed.\n")
            field(items, enemy)
        else:
            print_pause("Not a valid response, please re-enter")
            house(items, enemy)
    else:
        print_pause("You feel under-prepared for this, "
                    "what with only having a tiny dagger.")
        print_pause("Would you like to (1) fight or (2) run away?")
        response = input("(Please enter 1 or 2)\n")
        if response == '1':
            print_pause("You do your best...")
            print_pause(f"but your dagger is no match for {enemy}")
            print_pause("You have been defeated!")
            play_again()
        elif response == '2':
            print_pause("You run back into the field. Luckily, "
                        "you don't seem to have been followed.\n")
            field(items, enemy)
        else:
            print_pause("Not a valid response, please re-enter")
            house(items, enemy)


def cave(items, enemy):
    print_pause("You peer cautiously into the cave.")
    if 'wand' in items:
        print_pause("You've been here before, and gotten "
                    "all the good stuff. It's just an empty cave now.")
        print_pause("You walk back out to the field.")
        field(items, enemy)
    else:
        print_pause("It turns out to be only a very small cave.")
        print_pause("Your eye catches a legendary wand "
                    "in the remains of an old friend.")
        print_pause("It's the Elder Wand!")
        print_pause("Your put your dagger away and grab the wand.")
        print_pause("You can feel its power throughout your body!")
        items.append('wand')
    print_pause("You walk back out to the field.")
    field(items, enemy)


def adventure_game():
    enemies = ['Voldemort', 'Bellatrix Lestrange', 'Tom Riddle',
               'Dolores Umbridge', 'Peter Pettigrew', 'Lucius Malfoy']
    enemy = random.choice(enemies)
    items = []
    intro(items, enemy)
    field(items, enemy)


adventure_game()
