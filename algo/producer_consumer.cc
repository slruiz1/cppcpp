#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

std::binary_semaphore signal_to_consumer{0}, signal_to_producer{1};

const int buff_size= 5;
int buff[buff_size];

void producer() {
    while(true) {
        signal_to_producer.acquire(); // decrements count, 1 => 0

        cout << "Produced = ";
        for (int i=0; i<buff_size; ++i) {
            buff[i] = i*i;
            cout << buff[i] << " " << std::flush;
            std::this_thread::sleep_for(milliseconds(200));
        }
        cout << endl;

        signal_to_consumer.release(); // increments count 0 => 1
    }
}

void consumer() {
    while(true) {
        signal_to_consumer.acquire(); // decrements count, 1 => 0
 
        cout << "Consumed = ";
        for (int i=buff_size-1; i>=0; --i) {
            cout << buff[i] << " " << std::flush;
            buff[i] = 0;
            std::this_thread::sleep_for(milliseconds(200));
        }
        cout << endl << endl;

        signal_to_producer.release(); // increments count 0 => 1
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    cout << "[main] Got the signal!" << endl;
    producer_thread.join();
    consumer_thread.join();
    return 0;
}
