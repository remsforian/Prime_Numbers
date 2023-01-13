import csv
import os

#set current directory to be the primes folder (only works in unix. Change based on your OS)

os.chdir('/home/solmasters/Documents/Code/Primes')

#check if a number is prime
def isprime (num):
    #begin at 2, because if it is 1, all numbers will read as prime
    n = 2
    while (n<num):
        if (num % n == 0):
            return False
            n = num
        n += 1
    return True

#starting number. Lower numbers will confuse isprime
n = 3

#set starting number to be most recent number in the csvfile
with open('primes.csv','r') as csvfile:
    n = int(csvfile.readlines()[-1])

#open the csv file
with open('primes.csv','a') as csvfile:
    writer = csv.writer(csvfile)
    while (1==1):
        #check if number is prime
        check = isprime(n)
        #if number is prime record it and print to terminal
        if check == True:
            print(n)
            writer.writerow([n])                        
        #itterate
        n += 1


#Nice, we have some functional python code. Now I am going to *try* and reproduce this in c++, and hopefully add multithreading