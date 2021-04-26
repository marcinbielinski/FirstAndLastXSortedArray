#include <iostream>
#include <vector>

class Func {
    static int first_elem (std::vector<int>& a, int x) {
        int n = a.size();
        int first_elem = n;
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (a[mid] >= x) {
                first_elem = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return first_elem;
    }
public:
    static std::vector<int> searchRange(std::vector<int>& a, int x) {
        int first = first_elem(a, x);
        int last = first_elem(a, x + 1) - 1;
        if (first <= last) {
            std::cout << "Pierwszy element: " << first + 1 << " Ostatni element: " << last + 1;
            return {first, last};
        }
        std::cout << "Nie ma takiego elementu.";
        return {-1, -1};
    }
};

int main() {
    std::vector<int> myVec = {1, 2, 2, 4, 4, 5, 6, 7, 7, 7, 9, 10, 15 };
    int num = 7;
    Func::searchRange(myVec, num);

    return 0;
}
