class GardenError(Exception):
    def __init__(self, msg: str = "Unknown plant error") -> None:
        super().__init__(msg)


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


def main():
    print("=== Custom Garden Errors Demo ===")
    try:
        print("\nTesting PlantError...")
        raise PlantError("The tomato plant is wilting!")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    try:
        print("\nTesting WaterError...")
        raise WaterError("Not enough water in the tank!")
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    try:
        print("\nTesting catching all garden errors...")
        raise PlantError("The tomato plant is wilting!")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        raise WaterError("Not enough water in the tank!")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    print("\nAll custom error types work correctly!")


if __name__ == "__main__":
    main()
