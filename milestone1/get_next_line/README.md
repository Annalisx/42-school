*This project has been created as part of the 42 curriculum by acastald*

# get_next_line

## Description
**Get Next Line** is a project at **42 School** that focuses on file I/O operations and static memory management. The goal is to create a function that reads from a file descriptor and returns a single line, one call at a time.

This project challenges students to handle buffers of varying sizes and ensures no memory leaks occur, reinforcing understanding of:
* **File Descriptors:** Reading and managing data streams.
* **Static Variables:** Understanding data persistence across function calls.
* **Memory Management:** Proper allocation (`malloc`) and deallocation (`free`) of heap memory.
* **Macro Definitions:** Using preprocessor macros to define buffer sizes dynamically.

### Algorithm Explanation and Justification
The core challenge of this project is that the `read()` system call reads a fixed number of bytes (`BUFFER_SIZE`) which may contain no newlines, multiple newlines, or a partial line.

### Core Logic
The algorithm is structured in three main steps:

1.  **Reading and Accumulating (The Loop)**
    * **Action:** The function reads from the file descriptor into a temporary buffer. This buffer is then joined with a **static variable** (the "stash").
    * **Condition:** This reading loop continues until a newline character (`\n`) is found within the stash or the End of File (EOF) is reached.
    * **Justification:** A loop is necessary because a single `read` operation might not capture a full line if the `BUFFER_SIZE` is small or the line is long. We must accumulate data until a complete line is formed.

2.  **Extracting the Line**
    * **Action:** Once a newline is detected, the function identifies the substring from the start of the stash up to and including the `\n`. This substring is allocated and prepared to be returned.
    * **Justification:** The project requires returning exactly one line. We isolate this part of the data while keeping the rest safe for future use.

3.  **Updating the Stash (Static Memory)**
    * **Action:** The remaining part of the data (everything *after* the `\n`) is saved back into the static variable. The old stash is freed to prevent leaks.
    * **Justification:** **Static variables** are crucial here. Unlike local variables, which are destroyed when a function returns, a static variable persists. This allows the function to "remember" the leftover data from the previous read operation, ensuring that the next call to `get_next_line` starts exactly where the previous one left off.

---

## Instructions

### Compilation
This function is designed to be compiled alongside a main program. You must define the `BUFFER_SIZE` macro during compilation.

1.  **Create a test file (`main.c`):**
    ```
    #include "get_next_line.h"
    #include <fcntl.h>
    #include <stdio.h>

    int main(void)
    {
        int fd = open("test.txt", O_RDONLY);
        char *line;

        while ((line = get_next_line(fd)))
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
        return (0);
    }
    ```

2.  **Compile:**
    Replace `42` with your desired buffer size.
    ```bash
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
    ```

3.  **Run:**
    ```bash
    ./gnl
    ```

## Resources

During this project, I consulted websites like *Stack Overflow* to understand better the static variables and *GeeksforGeeks* to comprehend how does file descriptor and Input-Output system call works, peers from 42.
AI assisted in structuring and formatting this README file to ensure it meets the required standards.

---

#### Algorithm Choices


Problem → read file line-by-line with unknown line lengths using fixed BUFFER_SIZE reads.\
Solution → dynamic buffer with static variable. 

Why not alternatives?\
Read entire file  → wastes memory \
Fixed buffer only  → fails on long lines 

My approach:\
Read: Concatenate BUFFER_SIZE chunks until \n or the end of file\
Extract: Return line up to \n\
Save: Store remainder in static variable for next call

Key insight: Static variable preserves unread data between calls, avoiding re-reading.
