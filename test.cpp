#include <iostream>
#include <cstring>

int add(int x, int y){

    return(x+y);
}

char *cat_str(const char *c1, const char *c2){
    char *ptr = NULL;

    ptr = (char *) malloc(strlen(c1)+strlen(c2)+1);
    strncpy(ptr, c1, strlen(c1) );
    strncpy(ptr+ strlen(c2), c2, strlen(c2) );
    ptr[strlen(c1)+strlen(c2)] = 0;
    return ptr;
}

int main()
{
    char *ptr=NULL;
    ptr = cat_str("Hello", "World");
    std::cout << "2 + 3 = " << add(2, 3) << "\n";
    std::cout << ptr << "\n";
    free(ptr);
    
    return 0;
}
