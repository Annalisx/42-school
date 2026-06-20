import sys


def ancient_text() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
    else:
        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file '{sys.argv[1]}'")
        filename = sys.argv[1]
        try:
            file = open(sys.argv[1], "r")
            print("---")
            contenuto = file.read()
            print(f"\n{contenuto}")
            print("---")
            file.close()
            print(f"File '{sys.argv[1]}' closed.")
        except FileNotFoundError as e:
            print(f"Error opening file '{filename}': {e}")
        except PermissionError as e:
            print(f"Error opening file '{filename}': {e}")


if __name__ == "__main__":
    ancient_text()


# python3 ft_ancient_text.py /etc/shadow per permessi Linuc
