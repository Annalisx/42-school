#!/usr/bin/python3
class Plant:
    def __init__(self, name: str, height: float, days: int, gw: float) -> None:
        self.name = name
        self.height = height
        self.days = days
        self.gw = gw

    def show(self) -> None:
        print(f"{self.name}: {float(self.height)}cm, {self.days} days old")


if __name__ == "__main__":
    plant1 = Plant("Rose", 25, 30, 1.15)
    plant2 = Plant("Tulips", 12, 12, 12)
    plant3 = Plant("Bonsai", 7.5, 365, 0.01)
    plant4 = Plant("Jasmine", 5, 19, 2)
    plant5 = Plant("Poppy", 80, 1, -20)
    print("=== Plant  Factory Output ===")
    print("Created:", end=" ")
    plant1.show()
    print("Created:", end=" ")
    plant2.show()
    print("Created:", end=" ")
    plant3.show()
    print("Created:", end=" ")
    plant4.show()
    print("Created:", end=" ")
    plant5.show()
