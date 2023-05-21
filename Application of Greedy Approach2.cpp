#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent a packet
struct Packet {
    int weight;
    int profit;
    int loss;
};

// Function to compare packets based on their profit-loss ratio in descending order
bool comparePackets(const Packet& p1, const Packet& p2) {
    double ratio1 = static_cast<double>((p1.profit-p1.loss) / p1.weight);
    double ratio2 = static_cast<double>((p2.profit-p2.loss) / p2.weight);
    return ratio1 > ratio2;
}

// Function to find the maximum profit obtained by selecting packets optimally
int findMaxProfit(Packet packets[], int n, int capacity) {
    // Sort the packets based on their profit-loss ratio in descending order
    sort(packets, packets + n, comparePackets);

    int maxProfit = 0;

    for (int i = 0; i < n; ++i) {
        if (packets[i].weight <= capacity) {
            // Take the whole packet as it fits in the capacity
              cout<<"Included Packet index = "<<i+1<<endl;
            maxProfit += packets[i].profit;
            capacity -= packets[i].weight;
        } else {
            break; // No more packets can be accommodated
        }
    }

    return maxProfit;
}


int main() {
    int n;
    cout << "Enter the number of packets: ";
    cin >> n;

    Packet* packets = new Packet[n];

    cout << "Enter the weight, profit, and loss for each packet:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Packet " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> packets[i].weight;
        cout << "Profit: ";
        cin >> packets[i].profit;
        cout << "Loss: ";
        cin >> packets[i].loss;
        cout << endl;
    }

    int capacity;
    cout << "Enter the maximum capacity of the transport: ";
    cin >> capacity;

    int maxProfit = findMaxProfit(packets, n, capacity);

    cout << "The maximum profit obtained is: " << maxProfit << endl;

    delete[] packets;

   return 0;
}
