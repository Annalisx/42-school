import math


def ft_split(s: str, divisor: str) -> list[str]:
    result = list()
    word = ""
    for char in s:
        if (char == divisor):
            result.append(word)
            word = ""
        else:
            word += char
    result.append(word)
    return result


def get_coords() -> tuple[float, ...] | None:
    try:
        s = ft_split(input("Enter new coordinates as floats in "
                           "formats 'x,y,z': "), ",")
        coords = (float(s[0]), float(s[1]), float(s[2]))
        return tuple(coords)
    except (IndexError):
        print("Invalid syntax")
    except ValueError as e:
        param = ft_split(str(e), ":")[-1]
        print(f"Error on parameter {param}: {e}")
    return None


def get_player_pos() -> None:
    print("=== Game Coordinates System ===")
    print("\nGet a first set of coordinates")
    coords = None
    while coords is None:
        coords = get_coords()
    print(f"Got a first tuple: {coords}")
    print(f"It includes: X={coords[0]}, Y={coords[1]}, Z={coords[2]}")
    pit1 = math.sqrt(coords[0]**2 + coords[1]**2 + coords[2]**2)
    print(f"Distance to center: {round(pit1, 4)}")
    print("\nGet a second set of coordinates")
    coords2 = None
    while coords2 is None:
        coords2 = get_coords()
    pit = math.sqrt((coords[0]-coords2[0])**2 + (coords[1]
                    - coords2[1])**2 + (coords[2] - coords2[2])**2)
    print(f"Distance between the 2 sets of coordinates: {round(pit, 4)}")


if __name__ == "__main__":
    get_player_pos()
