#!/usr/bin/python3
class Plant:
    def __init__(self, name: str, h: float, days: int, gw: float) -> None:
        self.name = name
        self.h = h
        self.days = days
        self.gw = gw

    def show(self) -> None:
        print(f"{self.name}: {float(self.h)}cm, {self.days} days old")

    def grow(self) -> None:
        self.h = self.h + self.gw

    def age(self, i: int) -> None:
        self.days += i


class Flower(Plant):
    def __init__(self, name: str, h: float, days: int,
                 gw: float, col: str) -> None:
        super().__init__(name, h, days, gw)
        self.col = col

    def show(self) -> None:
        super().show()
        print(f" Color: {self.col}")

    def bloom(self) -> None:
        self.show()
        print(f" {self.name} has not bloomed yet")
        print(f"[asking the {self.name.lower()} to bloom]")
        self.show()
        print(f"{self.name} is blooming beautifully!")


class Tree(Plant):
    def __init__(self, name: str, h: float, days: int,
                 gw: float, trunk_diameter: float) -> None:
        super().__init__(name, h, days, gw)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter}cm")

    def produce_shade(self) -> None:
        print(f"[asking the {self.name.lower()} to produce shade]")
        print(f"Tree {self.name} now produces a shade of {self.h}"
              f"cm long and {self.trunk_diameter}cm wide.")


class Vegetable(Plant):
    def __init__(self, name: str, h: float, days: int,
                 gw: float, harvest_season: str) -> None:
        super().__init__(name, h, days, gw)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")

    def grow_veg(self, i: int) -> None:
        print(f"[make {self.name.lower()} grow and age for {i} days]")
        self.age(i)
        self.grow()
        self.nutritional_value += i


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower = Flower("Rose", 25, 30, 0, "blue")
    flower.bloom()
    print()
    print("=== Tree")
    tree = Tree("Bonsai", 7.5, 365, 1, 5)
    tree.show()
    tree.produce_shade()
    print()
    print("=== Vegetable")
    vegetable = Vegetable("Onion", 2, 12, 10, "June")
    i = 0
    vegetable.show()
    i = 20
    vegetable.grow_veg(i)
    vegetable.show()
