import random


def data() -> None:
    print("=== Game Data Alchemist ===")
    player = ['Alice', 'bob', 'Charlie', 'dylan', 'Emma',
              'Gregory', 'john', 'kevin', 'Liam']
    print(f"\nInitial list of players: {player}")
    caps = [name.capitalize() for name in player]
    print(f"New list with all names capitalized: {caps}")
    alrcaps = [name for name in player if name.istitle()]
    print(f"New list of capitalized names only: {alrcaps}")
    score = {name: random.randint(1, 100) for name in caps}
    print(f"Score dict: {score}")
    avg = sum(score.values()) / len(score)
    print(f"Score average is {round((avg), 2)}")
    above_avg = {score[0]: score[1]
                 for score in score.items() if score[1] > avg}
    print(f"High scores: {above_avg}")


if __name__ == "__main__":
    data()
