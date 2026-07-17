try:
    from pydantic import BaseModel, Field, ValidationError
    from datetime import datetime
except ModuleNotFoundError as e:
    print(f"{e}: Install pydantic")


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    notes: str | None = Field(default=None, max_length=200)


def main() -> None:
    print("Space Station Data Validation")
    try:
        stat: SpaceStation = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=6,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance=datetime.now()
            )
        print("========================================")
        print("Valid SpaceStation created")
        print(f"ID: {stat.station_id}")
        print(f"Name: {stat.name}")
        print(f"Crew: {stat.crew_size}")
        print(f"Power: {stat.power_level}%")
        print(f"Oxygen: {stat.oxygen_level}%")
        print(f"Last maintenance: {stat.last_maintenance}")
        if stat.is_operational:
            print("Status: Operational")
        else:
            print("Status: Not Operational")
        print("\n========================================")
        _: SpaceStation = SpaceStation(
                                        station_id="ISS001",
                                        name="Invalid station",
                                        crew_size=25,
                                        power_level=85.5,
                                        oxygen_level=92.3,
                                        last_maintenance=datetime.now())
    except ValidationError as e:
        print("Expected validation error:")
        print(e)


if __name__ == "__main__":
    main()
