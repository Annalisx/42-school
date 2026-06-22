from ex0.factory import CreatureFactory, FlameFactory, AquaFactory


def testing(factory: CreatureFactory) -> None:
    print("Testing factory")
    


def fight(flame_factory: FlameFactory, aqua_factory: AquaFactory) -> None:
    pass


if __name__ == "__main__":
    testing(FlameFactory())
