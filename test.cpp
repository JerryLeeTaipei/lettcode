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
    int nums[5] = {1,2,3,4,5};
    auto s=100;
    ptr = cat_str("Hello", "World");
    for ( int n: nums ){
        s = add(s, n);
        std::cout << s << ' ';
    }
    std::cout << ptr << s << "\n";
    free(ptr);
    
    return 0;
}
