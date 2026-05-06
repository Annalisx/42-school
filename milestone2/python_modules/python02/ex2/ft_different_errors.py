def garden_operations(operation_number: int) -> None:
    match(operation_number):
        case 0:
            int("abc")
        case 1:
            1 / 0
        case 2:
            open("/non/existent/file")
        case 3:
            "abc" + 10  # type: ignore[operator]
        case _: return


def test_error_types():
    print("=== Garden Error Types Demo ===")
    for i in range(5):
        try:
            print(f"Testing operation {i}...")
            garden_operations(i)
        except (ValueError, ZeroDivisionError,
                FileNotFoundError, TypeError) as e:
            print(f"Cought {e.__class__.__name__}: {e}")
    print("Operation completed successfully")
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
