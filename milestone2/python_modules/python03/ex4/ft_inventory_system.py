import sys
from typing import Dict


class InventoryError(Exception):
    pass


def inventory_system() -> None:
    print("=== Inventory System Analysis ===")
    inventory: Dict[str, int] = dict()
    for item in sys.argv[1:]:
        try:
            pair = item.split(":")
            if len(pair) != 2:
                raise InventoryError(f"Error - invalid parameter '{item}'")
            elif pair[0] in inventory.keys():
                raise InventoryError(f"Redundant item '{pair[0]}' "
                                     " - discarding")
            inventory[pair[0]] = int(pair[1])
        except ValueError as e:
            print(f"Quantity error for '{pair[0]}': {e}")
        except InventoryError as e:
            print(e)
    print(f"Got inventory: {inventory}")
    print(f"Item list: {inventory.keys()}")
    if not inventory:
        print("No inventory items were provided.")
        return
    total_sum = sum(inventory.values())
    print(f"Total quantity of the {len(inventory.values())} "
          f"items: {total_sum}")
    min_item = ("", int(list(inventory.values())[0]))
    max_item = ("", int(list(inventory.values())[0]))
    for name, quantity in inventory.items():
        print(f"item {name} represents "
              f"{round(quantity * 100 / total_sum, 1)}%")
        if quantity <= min_item[1]:
            min_item = (name, quantity)
        if quantity >= max_item[1]:
            max_item = (name, quantity)
    print(f"Item most abundant: {max_item[0]} with quantity {max_item[1]}")
    print(f"Item least abundant: {min_item[0]} with quantity {min_item[1]}")
    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    inventory_system()
