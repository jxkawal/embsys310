

void swap(char* first, char* second) {
    char temp = *first;
    *first = *second;
    *second = temp;
}

void swap_pointer(int** ptr1, int** ptr2) {
    int* temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int sqrAsm(int val);
void swapCharsAsm(char* ptr1, char* ptr2);
//const char* myCstr = "\nHello from assembly! ";

int main()
{
    //int x = 1;
    //int y = 2;
    //int* xPtr = &x;
    //int* yPtr = &y;
    
    //swap_pointer(&xPtr, &yPtr);
    
    char one = '5';
    char two = '6';
    swap(&one, &two);
    
    char cOne = 'A';
    char cTwo = 'B';
    swapCharsAsm(&cOne, &cTwo);
    
    
    //int sqrResult = sqrAsm(5);
    
    return 0;
}
