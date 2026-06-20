import sys


def score_analystics() -> None:
    print("=== Player Score Analystics ===")
    list = (sys.argv[1:])
    if len(list) == 0:
        print(f"No scores provided. Usage: python3 {sys.argv[0]}"
              " <score1> <score2> ...")
    values = []
    for item in sys.argv[1:]:
        try:
            arg = int(item)
            values.append(arg)
        except ValueError:
            print(f"Invalid parameter: '{item}'")
    if len(values) != 0:
        print(f"Scores processed: {values}")
        print(f"Total players: {len(sys.argv[1:])}")
        print(f"Total score: {sum(values)}")
        print(f"Average score: {(sum(values) / len(sys.argv)) - 1}")
        print(f"High score: {max(values)}")
        print(f"Low score: {min(values)}")
        print(f"Score range: {max(values) - min(values)}")


if __name__ == "__main__":
    score_analystics()
