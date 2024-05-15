#include <iostream>
#include <string>

// C++11
// *************************************
void printAll() {
    std::cout << std::endl;
}

template<typename T, typename... Args>
void printAll(T head, Args... args) {
    std::cout << head << ' ';
    printAll(args...);
}


// C++11
// *************************************
template<typename T>
T sumAll(T last) 
{
    return last;
}
template<typename T, typename... Args>
auto sumAll(T head, Args... args) 
{
    return head + sumAll(args...);
}


// C++17
// *************************************

// fold expression
template<typename... Args>
auto rightUnaryFold(Args... args)
{
    return (args + ...);
}

// return (... + args); -> return (((1 + 2) + 3) + 4) ...
template<typename... Args>
auto leftUnaryFold(Args... args) {
    return (... + args);
}


template<typename... Args>
void binaryFold(Args... args) {
    (std::cout << ... << args) << std::endl;
}


template<typename T, typename... Args>
auto binaryFoldRight(T sum, Args... args) {
    (args += ... += sum);
    return sum;
}

template<typename T, typename... Args>
auto binaryFoldLeft(T sum, Args... args) {
    (sum += ... += args);
    return sum;
}

template<typename... Args>
void binaryFold2(Args... args) {
    std::string result;
    (result += ... += std::to_string(args));
    std::cout << result << std::endl;
}

// -------------------- Main --------------------
int main()
{
    printAll(1, "2", std::string("3"), std::to_string(4), 5.0, 6.0f, 7, 8, 9, 10);

    int sum = sumAll(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    std::cout<<"sum of all elements: "<< sum << std::endl;

    sum = rightUnaryFold(1, 2.0, 3.0f, 4, 5, 6, 7, 8, 9, 10);
    std::cout<<"sum of all elements by using fold: "<< sum << std::endl;

    // ------------- FOLDS -----------
    binaryFold(1, "2", std::string("3"), std::to_string(4), 5.0, 6.0f, 7, 8, 9, 10);

    sum = binaryFoldRight(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    std::cout<<"sum of all elements by using binaryFoldRight: "<< sum << std::endl;

	sum = binaryFoldLeft(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    std::cout<<"sum of all elements by using binaryFoldLeft: "<< sum << std::endl;

    std::cout << "binaryFold2 = ";
    binaryFold2(1, 2, 3.14);
    std::cout << std::endl;

    return 0;
}