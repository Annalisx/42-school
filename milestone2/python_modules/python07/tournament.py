from ex2.strategy import (
    BattleStrategy,
    NormalStrategy,
    Aggressivestrategy,
    DefensiveStrategy,
    InvalidCombination,
)
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex0 import CreatureFactory, FlameFactory, AquaFactory, factory


def battle(opponent: list[tuple[CreatureFactory, BattleStrategy]]):
    print("Tournament 0 (basic)")
    print(print_opp(opponent))
    print("*** Tournament ***")

def print_opp(opponent: list[tuple[CreatureFactory, BattleStrategy]]):
    res = "[" + ", ".join(
        f"({fact.create_base().name}+{strat.__class__.__name__.replace('Strategy', '')})"
            for fact, strat in opponent
        ) + "]"
    return res
    


if __name__ == "__main__":
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()
    normal_strat = NormalStrategy()
    defendive_strat = DefensiveStrategy()
    aggressive_strat = Aggressivestrategy()
    tournament0 = [
        (flame_factory, normal_strat),
        (healing_factory, defendive_strat)
    ]
    battle(tournament0)
