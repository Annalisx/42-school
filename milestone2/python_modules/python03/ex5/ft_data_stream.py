import random
from typing import Any, Generator, Tuple


def get_event() -> Generator[Tuple[str, str], None, None]:
    name = ("Alice", "Bob", "Dylan", "Charlie")
    action = ("run", "eat", "sleep", "grab", "move", "climb",
              "swim", "release")
    while True:
        yield random.choice(name), random.choice(action)


def consume_event(
        listoftuple: list[tuple[str, str]]
) -> Generator[Any, None, None]:
    while listoftuple:
        element_to_remove = random.choice(listoftuple)
        listoftuple.remove(element_to_remove)
        yield element_to_remove


def main() -> None:
    event = get_event()
    print("=== Game Data Stream Processor ===")
    for i in range(1000):
        data = next(event)
        print(f"Event {i}: Player {data[0]} did action {data[1]}")
    tuple_event = get_event()
    listoftuple = [next(tuple_event) for _ in range(10)]
    print(f"Built list of 10 events: {listoftuple}")
    delit = consume_event(listoftuple)
    for tuple_event in delit:
        print(f"Got event from list: {tuple_event}")
        print(f"Remains in list: {listoftuple}")


if __name__ == "__main__":
    main()
