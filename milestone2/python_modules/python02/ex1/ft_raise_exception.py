def input_temperature(temp_str: str):
    temp_int = int(temp_str)
    if temp_int > 40:
        raise ValueError(f"{temp_int}°C is too hot for plants (max 40°C)")
    elif temp_int < 0:
        raise ValueError(f"{temp_int}°C is too cold for plants (min 0°C)")
    else:
        return temp_int


def test_temperature():
    print("=== Garden Temperature Checker ===")
    print()
    temp_str = "25"
    print(f"Input data is '{temp_str}'")
    try:
        result = input_temperature(temp_str)
        print(f"Temperature is now {result}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    temp_str = "abc"
    print(f"Input data is '{temp_str}'")
    try:
        result = input_temperature(temp_str)
        print(f"Temperature is now {result}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    temp_str = "100"
    print(f"Input data is '{temp_str}'")
    try:
        result = input_temperature(temp_str)
        print(f"Temperature is now {result}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
        print()
    temp_str = "-50"
    print(f"Input data is '{temp_str}'")
    try:
        result = input_temperature(temp_str)
        print(f"Temperature is now {result}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
