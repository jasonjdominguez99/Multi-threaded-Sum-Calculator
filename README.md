# Multi-threaded Sum Calculator

## Background
Me: "Write the specification for a beginner C++ multi-threaded project" and this is the project it came up with.

ChatGPT: "Certainly! Here's a simplified specification for a beginner C++ multithreaded project. This project will create a basic multi-threaded application that simulates a simple task distribution system, where multiple threads work together to perform a common task: calculating the sum of elements in an array concurrently.

**Project Title:** Multi-threaded Sum Calculator

**Objective:** The objective of this project is to create a C++ application that calculates the sum of elements in an array concurrently using multiple threads.

**Features:**

1. **User Input:**
    - The user will be prompted to enter the size of the array and the elements of the array.
2. **Thread Creation:**
    - The program will create a user-specified number of threads (e.g., 2 to 4 threads).
3. **Task Division:**
    - The array of elements will be divided equally among the threads for concurrent processing. Each thread will work on its portion of the array.
4. **Sum Calculation:**
    - Each thread will calculate the sum of its portion of the array concurrently.
5. **Thread Synchronization:**
    - Proper synchronization mechanisms (e.g., mutex or atomic operations) will be used to prevent race conditions while accessing shared resources, such as the result sum variable.
6. **Result Display:**
    - After all threads have completed their calculations, the program will display the final sum of all elements in the array.
7. **Result Display:**
    - After all threads have completed their calculations, the program will display the final sum of all elements in the array.

**Requirements:**

1. The project should use C++11 or later for multithreading support.</li>
2. Proper error handling should be implemented for user input validation.</li>
3. The user should have the option to specify the number of threads to be created.</li>
4. Thread management and synchronization should be done using C++ standard library facilities (e.g., `std::thread`, `std::mutex`, `std::atomic`, etc.).</li>
5. The program should be well-documented with comments explaining the purpose of each function and section of code.

**Example Workflow:**

1. User runs the program.
2. User enters the size of the array (e.g., 10) and the array elements (e.g., [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]).
3. User specifies the number of threads (e.g., 4).
4. Threads are created, and the array is divided into chunks for each thread.
5. Threads calculate the sum of their respective chunks concurrently.
6. Threads synchronize to update the final sum.
7. The program displays the final sum (e.g., Sum: 55).

**Optional Enhancements:**

1. Implement a timer to measure the execution time of the multithreaded vs. single-threaded versions of the program.
2. Create a more advanced task distribution system, such as distributing tasks to threads dynamically based on workload.
3. Allow users to choose between different synchronization mechanisms and compare their performance.
4. Implement error handling and graceful termination of threads in case of exceptions."
