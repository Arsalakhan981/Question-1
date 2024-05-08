#include<stdio.h>


int collatzsequence(int n) {
    int length=1; // Start with length 1 because we always count the starting number

    while (n!=1){
        if (n%2==0){
            n/=2;//This step ensures that we reduce the number to half its value, effectively making it smaller and closer to 1.
            } 
        else
        n=3*n+1; // By multiplying num by 3 and adding 1, we increase its value, ensuring that it eventually becomes even and follows the rule for even numbers.
        length++;
        
    }

    return length; 
}

int main() {
    int n;
    printf("Enter a number: "); 
    scanf("%d",&n); 

    int start=0;
    int maximum_length=0;

    for (int i=2;i<n;i++) {
        int length=collatzsequence(i); 
        if (length>maximum_length) { 
            maximum_length=length; // Update the maximum length
            start = i; // Update the starting number that produces the longest sequence
        }
    }

    printf("The starting number under %d that produces the longest Collatz sequence is: %d with a length of :%d ",n,start,maximum_length); 
 

    return 0;
}
