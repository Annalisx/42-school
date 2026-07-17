try:
    from pydantic import BaseModel, Field, ValidationError, model_validator
    from datetime import datetime
    from enum import Enum
except ModuleNotFoundError as e:
    print(f"{e} Install pydantic")


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field("planned")
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def data_validator(self) -> "SpaceMission":
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")
        leader: bool = False
        for member in self.crew:
            if (
                member.rank == Rank.COMMANDER or
                member.rank == Rank.CAPTAIN
            ):
                leader = True
                break
        if not leader:
            raise ValueError("Mission must have at least one Commander"
                             " or Captain")
        if self.duration_days > 365:
            experienced_count = sum(
                member.years_experience >= 5
                for member in self.crew
            )

            if experienced_count < len(self.crew) / 2:
                raise ValueError("Long missions (> 365 days) need 50%"
                                 " experienced crew (5+ years)")
        for member in self.crew:
            if not member.is_active:
                raise ValueError("All crew members must be active")
        return (self)


def main() -> None:
    print("Space Mission Crew Validation")
    print("========================================")
    try:
        print("Validation mission created:")
        cadet = CrewMember(
            member_id="C001",
            name="Qui",
            rank=Rank.CADET,
            age=42,
            specialization="Navigation",
            years_experience=1
        )
        officer = CrewMember(
            member_id="C003",
            name="Mio",
            rank=Rank.OFFICER,
            age=30,
            specialization="Engineering",
            years_experience=5
        )
        lieutenant = CrewMember(
            member_id="C003",
            name="Mao",
            rank=Rank.LIEUTENANT,
            age=27,
            specialization="Navigation",
            years_experience=2
        )
        captain = CrewMember(
            member_id="C002",
            name="Quo",
            rank=Rank.CAPTAIN,
            age=27,
            specialization="Mission Command",
            years_experience=7,
        )
        commander = CrewMember(
            member_id="C002",
            name="Qua",
            rank=Rank.COMMANDER,
            age=42,
            specialization="Mission Command",
            years_experience=7,
            is_active=True
        )
        test_mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime.now(),
            duration_days=900,
            crew=[commander, lieutenant, officer],
            mission_status="planned",
            budget_millions=2500.0,
        )
        print(f"Mission: {test_mission.mission_name}")
        print(f"ID: {test_mission.mission_id}")
        print(f"Destination: {test_mission.destination}")
        print(f"Budget: ${test_mission.budget_millions}M")
        print(f"Crew Size: {len(test_mission.crew)}")
        print("Crew Members:")
        for member in test_mission.crew:
            print(f"- {member.name} ({member.rank.value}) -"
                  f" {member.specialization}")
        print("\n========================================")
        _ = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime.now(),
            duration_days=900,
            crew=[cadet, lieutenant, captain],
            mission_status="planned",
            budget_millions=2500.0
        )
    except ValidationError as e:
        print("Expected validation error:")
        print(e)


if __name__ == "__main__":
    main()
