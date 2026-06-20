def gen_player_achievements() -> None:
    print("=== Achievement Tracker System ===\n")
    alice = {'Crafting Genious', 'World Saviour', 'Master Explorer',
             'Collector Supreme', 'Untouchable', 'Boss Slayer'}
    bob = {'Crafting Genious', 'Strategist', 'World Saviour',
           'Master Explorer', 'Unstoppable', 'Collector Supreme',
           'Untouchable'}
    charlie = {'Strategist', 'Speed Runner', 'Survivor', 'Master Explorer',
               'Treasure Hunter', 'First Steps', 'Collector Supreme',
               'Untouchable', 'Sharp Mind'}
    dylan = {'Strategist', 'Speed Runner', 'Unstoppable', 'Untouchable',
             'Boss Slayer'}
    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")
    print()
    print(f"All distinct achivements: {charlie | dylan | bob | alice}")
    print()
    print(f"Common achivements: {charlie & dylan & bob & alice}")
    print()
    print(f"Only Alice has: {alice - dylan - bob - charlie}")
    print(f"Only Bob has: {bob - dylan - alice - charlie}")
    print(f"Only Charlie has: {charlie - dylan - alice - bob}")
    print(f"Only Dylan has: {dylan - bob - alice - charlie}")
    print()
    print(f"Alice is missing: {(charlie | bob | dylan) - alice}")
    print(f"Bob is missing: {(charlie | alice | dylan) - bob}")
    print(f"Charlie is missing: {(alice | bob | dylan) - charlie}")
    print(f"Dylan is missing: {(charlie | bob | alice) - dylan}")


if __name__ == "__main__":
    gen_player_achievements()
