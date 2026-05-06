#!/usr/bin/python3
class Plant:
    def __init__(self, name: str, height: float, days: int, gw: float) -> None:
        self.name = name
        self.height = height
        self.days = days
        self.gw = gw

    def show(self) -> None:
        print(f"{self.name}: {round(self.height, 2)}cm, {self.days} days old")

    def grow(self) -> None:
        self.height = self.height + self.gw

    def age(self) -> None:
        self.days += 1


if __name__ == "__main__":
    i = 1
    plant1 = Plant("Rose", 25.0, 30, 1.15)
    start = plant1.height
    print("=== Garden Plant Growth ===")
    plant1.show()
    while i in range(1, 8):
        print(f"=== Day {i} ===")
        plant1.grow()
        plant1.age()
        plant1.show()
        i += 1
    total_grow = plant1.height - start
    print(f"Growth this week: {round(total_grow, 2)}cm")
