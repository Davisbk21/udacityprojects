import random

"""This program plays a game of Rock, Paper, Scissors between two Players,
and reports both Player's scores each round."""

moves = ['rock', 'paper', 'scissors']

"""The Player class is the parent class for all of the Players
in this game"""


def play_again():
    response = input("Would you like to play again? (y/n) \n")
    if response == 'y':
        game.play_game()
    elif response == 'n':
        print("Thank you for playing!")
    else:
        print("Not a valid option.")
        play_again()


class Player:
    def move(self):
        return 'rock'

    def learn(self, my_move, their_move):
        pass


class RandomPlayer(Player):
    def move(self):
        return random.choice(moves)

    def learn(self, my_move, their_move):
        pass


class ReflectPlayer(Player):
    def move(self):
        if self.__dict__.keys().__contains__("my_move"):
            return self.my_move
        else:
            return random.choice(moves)

    def learn(self, my_move, their_move):
        self.my_move = their_move
        return self.my_move


class CyclePlayer(Player):
    def move(self):
        if self.__dict__.keys().__contains__("my_move"):
            if self.my_move in moves:
                index = moves.index(self.my_move)
                print(index)
                if index == 2:
                    moves.append(moves[0])
                return moves[index + 1]
        else:
            return random.choice(moves)

    def learn(self, my_move, their_move):
        self.my_move = my_move
        return self.my_move


class HumanPlayer(Player):
    def move(self):
        choice = input("Rock, Paper, or Scissors?\n")
        if choice.lower() in moves:
            return choice
        else:
            print("Not a valid input")
            return self.move()

    def learn(self, my_move, their_move):
        pass


def beats(one, two):
    return ((one == 'rock' and two == 'scissors') or
            (one == 'scissors' and two == 'paper') or
            (one == 'paper' and two == 'rock'))


class Game:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    def play_round(self):
        move1 = self.p1.move()
        move2 = self.p2.move()
        winner = beats(move1, move2)
        print(f"\n You played {move1}")
        print(f"\n Opponet played {move2}")
        self.p1.learn(move1, move2)
        self.p2.learn(move2, move1)
        if move1 == move2:
            print("** It's a tie **")
            print(f"Score: Player One: {self.p1_score}, "
                  f"Player Two: {self.p2_score}")
        elif beats(move1, move2):
            print("** PLAYER ONE WINS **")
            self.p1_score += 1
        else:
            print("** PLAYER TWO WINS **")
            self.p2_score += 1
        print(f"Score: Player One: {self.p1_score}, "
              f"Player Two: {self.p2_score}\n")

    def play_game(self):
        self.p1_score = 0
        self.p2_score = 0
        print("Rock Paper Scissors, Go!")
        for round in range(3):
            print(f"Round {round+1}:")
            self.play_round()
        if self.p1_score == self.p2_score:
            print("It's a draw!")
        elif self.p1_score > self.p2_score:
            print("Player 1 is the winner!!!")
        else:
            print("Player 2 is the winner!!!")
        print("Game over!")
        play_again()


if __name__ == '__main__':
    game = Game(HumanPlayer(), RandomPlayer())
    game.play_game()
