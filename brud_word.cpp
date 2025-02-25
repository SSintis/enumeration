#include <iostream>
#include <thread>
#include <chrono>

const int MAX_SIZE = 30;

int add_new_char(char*& chstr, char m, int size){
    char temp[size + 1];
    for (int i = 0; i < size; i++){
        temp[i] = chstr[i];
    }
    delete[] chstr;
    chstr = new char[size + 1];
    for (int i = 0; i < size; i++){
        chstr[i] = temp[i];
    }
    chstr[size - 1] = m;
    chstr[size] = '\0';

    return size + 1;
}

int main(){
    int si = 1;
    char str[MAX_SIZE];
    char* str_temp = new char[si];
    char m = 0;
    
    std::cout<<"Enter a word - ";
    std::cin>>str;

    str_temp[0] = '\0';
    int i = 0;
    while (str[i] != '\0'){
        std::cout<<str_temp<<char(m)<<std::endl;
        std::this_thread::sleep_for(std::chrono::nanoseconds(5000000));
        if (str[i] == m){
            i++;
            si = add_new_char(str_temp, m, si);
            m = 0;
        }
        m += 1;
        
    }
}