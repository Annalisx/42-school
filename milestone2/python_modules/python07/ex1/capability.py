from abc import ABC, abstractmethod
from ex0.creature import Creature


class HealCapability(ABC):
    @abstractmethod
    def heal(self, target) -> str:
        pass

class TransformCapability(ABC):
    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass


class Sproutling(Creature, HealCapability):
    def heal(self, target) -> str:
        return f"{self.name} heals itself for a small amount"


class Bloomelle(Creature, HealCapability):
    def heal(self, target) -> str:
        return f"{self.name} heals itself and others for a large amount"


class Shiftling(Creature, TransformCapability):
    def __init__(self, name, type):
        super().__init__(name, type)
        self.evolving = False

    def transform(self) -> str:
        self.evolving = True
        return f"{self.name} shifts into a sharper form!"
    
    def revert(self) -> str:
        self.evolving = False
        return f"{self.name} returns to normal."
    
    def attack(self) -> str:
        if not self.evolving:
            return f"{self.name} attacks normally." 
        else:
            return f"{self.name} performs a boosted strike!"

class Morphagon(Creature, TransformCapability):
    def __init__(self, name, type):
        super().__init__(name, type)
        self.evolving = False

    def transform(self) -> str:
        self.evolving = True
        return f"{self.name} morphs into a dragonic battle form!"
    
    def revert(self) -> str:
        self.evolving = False
        return f"{self.name} stabilizes its form."
    
    def attack(self) -> str:
        if not self.evolving:
            return f"{self.name} attacks normally." 
        else:
            return f"{self.name} unleashes a devastating morph strike!"