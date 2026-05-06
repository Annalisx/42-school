#!/usr/bin/python3
class Plant:
    def __init__(self, name: str, height: float, days: int, gw: float) -> None:
        self._name = name
        self._height = height
        self._days = days
        self._gw = gw

    def show(self) -> None:
        print(f"{self._name}: {float(self._height)}cm, {self._days} days old")

    def set_height(self, new: int) -> None:
        if new < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = new

    def set_age(self, new: int) -> None:
        if new < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._days = new

    def get_height(self):
        return self._height

    def get_age(self):
        return self._days


if __name__ == "__main__":
    plant1 = Plant("Rose", 15, 10, 2)
    print("=== Garden Security System ===")
    print("Plant created:", end=" ")
    plant1.show()
    plant1.set_height(25)
    plant1.get_height()
    plant1.set_age(30)
    plant1.get_age()
    print()
    print(f"Height updated: {plant1.get_height()}")
    print(f"Age updated: {plant1.get_age()}")
    print()
    plant1.set_height(-5)
    plant1.get_height()
    plant1.set_age(-3)
    plant1.get_age()
    print()
    print("Current state:", end=" ")
    plant1.show()


# ENCAPSULATION--PROTECTED CONVENTION: Si usa un singolo trattino basso.
# È una convenzione che segnala che il membro è destinato all'uso
# interno della classe o delle sue sottoclassi, ma non è enforcement
#  rigoroso da parte del linguaggio.
