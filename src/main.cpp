//==============================================================================
/*!
\file
\brief  Main program for multi-threaded sum calculator
*/
//==============================================================================

#include <iostream>

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

    // // Display values
    // for (const int val : vals)
    // {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl << std::endl << std::endl;

    // Get user input fot number of threads to use
    std::cout << "How many threads would you like to use? (1-8): ";
    int numThreads;
    std::cin >> numThreads;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl << std::endl;

    // Display number of threads entered
    std::cout << "You chose " << numThreads << " threads..."
              << std::endl << std::endl << std::endl;

    return 0;
}