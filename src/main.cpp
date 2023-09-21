//==============================================================================
/*!
\file
\brief  Main program for multi-threaded sum calculator
*/
//==============================================================================

#include <iostream>
#include <mutex>
#include <numeric>
#include <thread>
#include <vector>

// Mutex used to synchronize shared access to sum
std::mutex m;

void sum(
    const std::vector<int> & vals,
    const int start,
    const int end,
    int & sum,
    const int threadNum
);

void displayThreadSumOutput(
    const std::vector<int> & vals,
    const int start,
    const int end,
    const int threadNum,
    const int partialSum
);

int main()
{
    // Welcome user
    std::cout << "Welcome to the Multi-threaded Sum Calculator"
              << std::endl << std::endl << std::endl;

    // Get user input and initialize values to be summed
    std::cout << "Enter the size of the array: ";
    int size;
    std::cin >> size;

    std::vector<int> vals(size);

    std::cout << std::endl
              << "Enter the elements of the array "
                 "(separated by spaces, press enter to continue):"
              << std::endl << std::endl;
    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> vals[i];
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl << std::endl;

    // Get user input fot number of threads to use
    std::cout << "How many threads would you like to use? (1-8): ";
    int numThreads;
    std::cin >> numThreads;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl << std::endl;

    std::cout << "Calculating the sum of elements using "
              << numThreads
              << " threads..."
              << std::endl << std::endl << std::endl;

    // Compute number of elements to assign to each thread
    const int numValsPerThread = size/numThreads;

    // Create threads and calculate sum in parallel
    int totalSum = 0;

    std::vector<std::thread> threads;
    threads.reserve(size);

    for (size_t i = 0; i < numThreads; ++i)
    {
        auto subStart = i * numValsPerThread;
        auto subEnd = (i + 1) * numValsPerThread;
        if (i == numThreads - 1)
        {
            // assign all remaining values to final thread
            subEnd = size;
        }

        threads.emplace_back(
            sum,
            std::ref(vals),
            subStart,
            subEnd,
            std::ref(totalSum),
            i
        );
    }

    for (auto & thread : threads)
    {
        thread.join();
    }

    std::cout << "Final Sum: " << totalSum << std::endl << std::endl;

    return 0;
}

void sum(
    const std::vector<int> & vals,
    const int start,
    const int end,
    int & sum,
    const int threadNum
)
{
    int partialSum = 0;
    for (size_t i = start; i < end; ++i)
    {
        partialSum += vals[i];
    }
    
    std::lock_guard<std::mutex> lock(m);

    displayThreadSumOutput(vals, start, end, threadNum, partialSum);
    sum += partialSum;
}

void displayThreadSumOutput(
    const std::vector<int> & vals,
    const int start,
    const int end,
    const int threadNum,
    const int partialSum
)
{
    std::cout << "Thread " << threadNum << ": "
              << "Calculating sum for elements "
              << "[";
    for (size_t i = start; i < end; ++i)
    {
        std::string delimiter = i + 1 == end ? "]" : ", ";
        std::cout << vals[i] << delimiter;
    }
    std::cout << std::endl;

    std::cout << "Thread " << threadNum << ": "
              << "Sum = " << partialSum << std::endl;
}
