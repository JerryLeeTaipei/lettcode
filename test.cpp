#include <iostream>
#include <cstring>

auto add(int x, int y){

    return(x+y);
}

auto *cat_str(const char *c1, const char *c2){
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
    auto s=123;
    ptr = cat_str("Hello", "World");
    std::cout << "2 + 123= " << add(2, s) << "\n";
    std::cout << ptr << s << "\n";
    free(ptr);
    
    return 0;
}
