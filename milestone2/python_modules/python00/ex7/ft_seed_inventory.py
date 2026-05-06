def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    seed = seed_type[0].upper() + seed_type[1:]
    if unit == "packets":
        print(f"{seed} seeds: {quantity} {unit} available")
    elif unit == "grams":
        print(f"{seed} seeds: {quantity} {unit} total")
    elif unit == "area":
        print(f"{seed} seeds: cover {quantity} square meters")
    else:
        print("Unknown unit type")
