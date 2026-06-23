from abc import ABC, abstractmethod

from ex0.creature import Creature
from ex1.capability import TransformCapability, HealCapability


class InvalidCombination(Exception):
    pass


class BattleStrategy(ABC):
    @abstractmethod
    def act(self, type: Creature) -> str:
        pass

    @abstractmethod
    def is_valid(self, type: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def is_valid(self, type: Creature) -> bool:
        return True

    def act(self, type: Creature):
        return type.attack()


class Aggressivestrategy(BattleStrategy):
    def is_valid(self, type: Creature) -> bool:
        if isinstance(type, TransformCapability):
            return True
        else:
            return False

    def act(self, type: Creature):
        if not self.is_valid(type):
            raise InvalidCombination
        assert isinstance(type, TransformCapability)
        return type.transform(), type.attack(), type.revert()


class DefensiveStrategy(BattleStrategy):
    def is_valid(self, type: Creature) -> bool:
        if isinstance(type, HealCapability):
            return True
        else:
            return False

    def act(self, type: Creature):
        if not self.is_valid(type):
            raise InvalidCombination
        assert isinstance(type, HealCapability)
        return type.attack(), type.heal()
