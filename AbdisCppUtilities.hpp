#ifndef CppUtilities
#define CppUtilities

#include <iostream>
#include <string>
#include <random>
#include <ctime>

// print()
void print() {std::cout << std::endl;}
template<typename... Args>
void print(Args... words) {
    ((std::cout << words << ""), ...) << std::endl;
}
//

// input()
std::string input() {
    std::string answer = "";
    std::cin >> answer;
    return answer;
}
template<typename... Args>
std::string input(Args... words) {
    ((std::cout << words << ' '), ...) << std::endl;
    std::string answer = "";
    std::cin >> answer;
    return answer;
}
//

// to_lower()
std::string to_lower(std::string word) {
    std::string final_word = "";
    for (char c : word)
    {
        final_word += tolower(c);
    }
    return final_word;
}
//

// to_higher()
std::string to_upper(std::string word) {
    std::string final_word = "";
    for (char c : word)
    {
        final_word += toupper(c);
    }
    return final_word;
}
//

//
void random_in_range() {}
int random_in_range(int min,int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    /*  
    by jave.web from Stack Overflow link : https://stackoverflow.com/questions/7560114/random-number-c-in-some-range:
        If you wonder "what the hack is mt19937 type?!"
        A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits. 
        It is a "wrapper" for the "mersenne_twister_engine" template 
        (cplusplus.com/reference/random/mersenne_twister_engine) with pre-set params.
    */
    std::uniform_int_distribution<> distr(min, max); // define the range

    int random = distr(gen);

    return random;
}
double random_in_range(double min,double max) {
    //https://stackoverflow.com/questions/14638739/generating-a-random-double-between-a-range-of-values
    //Type of random number distribution
    std::uniform_real_distribution<double> dist(min, max);  //(min, max)

    //Mersenne Twister: Good quality random number generator
    std::mt19937 rng; 
    //Initialize with non-deterministic seeds
    rng.seed(std::random_device{}()); // difference between int randinrange and double randinrange

    double random = dist(rng);

    return random;
}
//

// 
template <typename T>
void print_vector(std::vector<T> list) {
    for (int i = 0;i<size(list);i++) {
        print("[",i,"] : ",list[i]);
    }
}
template <typename T>
void print_vector(std::string type,std::vector<T> list) {
    if (to_lower(type) == "simple" || to_lower(type) == "s") {
        for (int i = 0;i<size(list);i++) {
        print(" - ",list[i]);
        }
    }
}
//

#endif