#include <iostream> 
#include <vector>

int main() {
    std::vector<int> arr = {2, 3, 1, 4, 5, 7, 8, 1, 6};

    int temp = 0;

    for (size_t i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] % 2 != 0) {
            temp += arr[i];
        }
    }

    std::cout << "Sum: " << temp << std::endl;

    return 0;
}