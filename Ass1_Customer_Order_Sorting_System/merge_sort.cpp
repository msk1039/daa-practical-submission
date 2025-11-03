#include <iostream>
#include <vector>
using namespace std;


class CustomerOrder {
public:
    long long timestamp;
    string customername;


    CustomerOrder() : timestamp(0), customername("") {}

    CustomerOrder(long long timestamp, string customername) {
        this->timestamp = timestamp;
        this->customername = customername;
    }
};

class MergeSort {
public:
    void sort(vector<CustomerOrder> &orders) {

        if (orders.size() <= 1) return;

        mergesort(orders, 0, orders.size() - 1);
    }

private:
    void mergesort(vector<CustomerOrder> &orders, int left, int right) {

        if (left >= right) return;

        int mid = left + (right - left) / 2;


        mergesort(orders, left, mid);
        mergesort(orders, mid + 1, right);

        merge(orders, left, mid, right);
    }

    void merge(vector<CustomerOrder> &orders, int left, int mid, int right) {

        int n1 = mid - left + 1;

        int n2 = right - mid;

        vector<CustomerOrder> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = orders[left + i];

        for (int j = 0; j < n2; j++)
            R[j] = orders[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i].timestamp <= R[j].timestamp) {
                orders[k++] = L[i++];
            } else {
                orders[k++] = R[j++];
            }
        }

        while (i < n1) {
            orders[k++] = L[i++];
        }

        while (j < n2) {
            orders[k++] = R[j++];
        }
    }
};

int main() {
    vector<CustomerOrder> orders = {
        CustomerOrder(1678901234, "A"),
        CustomerOrder(1678801111, "B"),
        CustomerOrder(1678956789, "C"),
        CustomerOrder(1678704321, "D")
    };

    MergeSort s;
    s.sort(orders);
    cout << "Sorted Orders by Timestamp:\n";
    for (auto &o : orders) {
        cout << o.timestamp << " - " << o.customername << endl;
    }

    return 0;
}
