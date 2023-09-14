#include <stdio.h>

///I will choose the second problem from the set that states :
///a. Generate the first n prime numbers (n is a given natural number).
///b.Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.

int Checkprime(int n)
///function to check if a number is prime
///returns true if it is false otherwise
///the number to be checked is input
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int gcd(int a, int b)
///gcd -> calculates the greatest common divisor of two numbers
///input : the two desired numbers
///output : the greatest common divisor
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int relativePrime(int firstelement, int secondelement)
///checks if two numbers are relatively prime between them
///input : the 2 numbers to be checked
///output : 1 if they are relatively prime , 0 if not
{
    if (gcd(firstelement, secondelement) == 1)
        return 1;
    return 0;

}

void readArray(int* arr, int nr)
///function that reads an array from keyboard
///input parameters : from the main; the array and the number of elements in it
{
    for (int i = 0; i < nr; i++)
        scanf("%d", &arr[i]);
}

void printings()
///just some printings for the console
{
    printf("\n1.Read an array\n");
    printf("2.Solve the first requirement\n");
    printf("3.Solve the second requirement\n");
    printf("4.Exit\n");
}

void firstprimenr(int nrPrime)
///void function => does not return anything
///a number is read and decremented for each prime number found
///when the specific number is 0 the run stops and the first n prime numbers will have already been printed
{
    int swit1 = 1;
    int i = 2;
    while (swit1 == 1)
    {
        if(Checkprime(i) == 1)
        {
            printf("%d ", i);
            nrPrime--;
        }
        i = i + 1;
        if(nrPrime == 0)
            swit1 = 0;
    }
}

void dynamical(int* array, int nrElem)
///function that solves the second requirement through a dynamical approach
///input : the array where the maximum subsequence is determined and its number of elements
///prints the corresponding subsequence, looking at the minimum and maximum position
{
    int globalmax = 0;
    int pozmin = 0;
    int lgmax = 0;
    int lgcurr = 1;

    for (int i = 1; i < nrElem; i++) {
        if (relativePrime(array[i], array[i - 1]))
        {
            if (lgcurr == 1)
                pozmin = i - 1;
            lgcurr++;

            if (lgcurr >= lgmax) {
                lgmax = lgcurr;
                globalmax = i;
            }
        }
        else
            lgcurr = 1;
    }
    for(int i = 0 ; i < nrElem; i++)
    {
        if(i >= pozmin && i <= globalmax)
            printf("%d ", array[i]);
    }
}

void run()
///function to run the program with no input or output parameters, just executes functionalities
///the user chooses an input(option), and depending on its value the program will execute certain things
{
    int option;
    int swit = 1;
    int nrPrime;
    while (swit == 1) {
        printings();
        scanf("%d", &option);

        if (option == 4) {
            return;
        }

        int array[10001];
        int nrElem;

        if (option == 1)
        {
            scanf("%d", &nrElem);
            readArray(array, nrElem);
            printf("The array elements are : \n");
            for(int i = 0 ; i < nrElem ; i++)
                printf("%d ", array[i]);
            printf("\n");
        }

        if (option == 2) {
            scanf("%d", &nrPrime);
            printf("The first n prime numbers are : \n");
            firstprimenr(nrPrime);
        }

        if (option == 3) {
            printf("The longest subsequence of relative prime is : \n");
            dynamical(array, nrElem);
        }


        if (option != 1 && option != 2 && option != 3 && option != 4) {
            printf("The option is invalid, options are 1-4.\n");
            run();
        }
    }
}

int main()
///the main function of the program
{
    run();
    return 0;
}
