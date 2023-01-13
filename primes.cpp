#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include 

//record any prime numbers
void record(bool check, unsigned long long int(n)){
    if (check == true){
        //open file in append mode
        std::ofstream file("cprime.txt",std::ios::app);
        //print to terminal (because it's more fun that way)
        std::cout << n << '\n';
        //add to csv file
        file << n << '\n';
        //complete writing
        file.close();
        }
}

//check if a number is prime 
void isprime(unsigned long long int num){
    //we have to start with 2, otherwize all numbers would read as prime
    //itterates from 2 to num
    for (unsigned long long int n = 2; n < num ; n++){
        //checks if it is evenly devisable by any number
        if (num % n == 0){
            record(false, num);
            return;
        }
    }
    //if we make it through all the numbers, it is prime, and send it to the function
    record(true, num);
    return;
}

unsigned long long end(){
    //I hope to (eventually) rework this so it reads the file automatically
    int n;
    std::cout << "What is the maximum number to calculate?";
    std::cin >> n;
    return n;
}

int main(){
    //set the number of threads we will be using
    int numthreads = 8; //we will come for you soon, don't you wory
    //lowest starting number that won't confuse things. We won't have 2 which is a bit of a shame, but we shall live
    unsigned long long int nf = end(); //get the starting number
 
    for (unsigned long long int n = 3;n<nf;n++){
            isprime(n);
        }
    return 0;
}
