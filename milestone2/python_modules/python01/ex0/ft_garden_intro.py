if __name__ == "__main__":
    print("=== Welcome to My garden ===")
    name = "Rose"
    print(f"Plant: {name}")
    height = 25
    print(f"Height: {height}cm")
    age = 30
    print(f"Age: {age} days")
    print()
    print("=== End of Program ===")

# When a Python file is run directly (e.g., python script.py), the __name__
# variable is automatically set to the string '__main__'.
# When a file is imported as a module into another script, __name__ is set to
# the name of that module (the filename without the .py extension).
# This behavior is primarily used with the condition if __name__ == '__main__':
#  to ensure that specific code blocks (such as test cases or entry points)
# only execute when the file is run directly, preventing them from running
# unintentionally when the module is imported elsewhere.
