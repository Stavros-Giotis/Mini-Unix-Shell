#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

/*
Create a variable x with value 10,call fork()
Handle the three possible return cases.
In the child, change x to 50.
Print the child's PID, parent's PID and x.
In the parent, print its PID, child's PID and x.
Make the parent wait for the child using waitpid().
*/


int main () {
    int x =  10;
    pid_t pid  = fork();

    if(pid < 0) {
        std::cout<< "bad"<<std::endl;
        return 1;
    }
    if(pid == 0) {
        x = 50;
        std::cout<< "inside child ,curr_pid:"<<getpid()<<"parent pid:"<<getppid()<<"x is:"<< x<<std::endl;
        return 0;
    }
    else {
        waitpid(pid,nullptr,0);
        std::cout<< "inside parent, curr_pid:"<<getpid()<<"child pid:"<<pid <<"x is:"<< x<<std::endl;
        return 0;
    }
}