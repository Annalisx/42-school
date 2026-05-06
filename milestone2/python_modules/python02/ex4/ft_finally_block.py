class PlantError(Exception):
    pass


def water_plant(plant_name):
    if plant_name != plant_name.capitalize():
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")
    print(f"Watering {plant_name}: [OK]")


def test_watering_system():
    print("=== Garden Watering System ===")
    print("\nTesting valid plants...")
    try:
        print("Opening watering system")
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Carrot")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending test and returning to main")
    finally:
        print("Closing watering system")
    print("\nTesting valid plants...")
    try:
        print("Opening watering system")
        water_plant("Tomato")
        water_plant("lettuce")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending test and returning to main")
    finally:
        print("Closing watering system")
    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
