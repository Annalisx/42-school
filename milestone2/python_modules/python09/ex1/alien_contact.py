try:
    from pydantic import BaseModel, Field, ValidationError, model_validator
    from datetime import datetime
    from enum import Enum
except ModuleNotFoundError as e:
    print(f"{e} Install pydantic")


class ContactType(str, Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode='after')
    def data_validator(self) -> "AlienContact":
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")
        if not self.is_verified and self.contact_type == ContactType.PHYSICAL:
            raise ValueError("Physical contact reports must be verified\n")
        if (
            self.witness_count < 3 and
            self.contact_type == ContactType.TELEPATHIC
        ):
            raise ValueError("Telepathic contacts requires at least 3 "
                             "witnesses\n")
        if self.signal_strength > 7.0 and self.message_received is None:
            raise ValueError("Strong signals should include received messages")
        return self


def main() -> None:
    print("Alien Contact Log Validation")
    try:
        test: AlienContact = AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime.now(),
            location="Area 51, Nevada",
            contact_type=ContactType.RADIO,
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            message_received="Greetings from Zeta Reticuli",
            is_verified=True
            )
        print("========================================")
        print("Valid contact report:")
        print(f"ID:  {test.contact_id}")
        print(f"Type: {test.contact_type.value}")
        print(f"Location: {test.location}")
        print(f"Signal: {test.signal_strength}/10")
        print(f"Duration: {test.duration_minutes} minutes")
        print(f"Witnesses: {test.witness_count}")
        print(f"Message: {test.message_received}")
        print("\n========================================")
        _: AlienContact = AlienContact(
                                        contact_id="AC-ISS001",
                                        timestamp=datetime.now(),
                                        location="Area 51, Nevada",
                                        contact_type=ContactType.TELEPATHIC,
                                        signal_strength=8.5,
                                        duration_minutes=45,
                                        witness_count=2,
                                        is_verified=True)
    except ValidationError as e:
        print("Expected validation error:")
        print(e)


if __name__ == "__main__":
    main()
