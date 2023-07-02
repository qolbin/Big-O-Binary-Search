#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;  // Return the index if the target is found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {1, 12, 0, 34, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Measure execution time
    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, 0, n - 1, target);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    if (result == -1)
        cout << "Target element not found" << endl;
    else
        cout << "Target element found at index " << result << endl;

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    // Measure space complexity
    int space = sizeof(arr) + sizeof(n) + sizeof(target);
    cout << "Space complexity: " << space << " bytes" << endl;

    return 0;
}

/*Waktu Eksekusi (Time Complexity):
Kasus Terbaik, Rata-rata, dan Terburuk: O(log n) Algoritma Binary Search memiliki waktu eksekusi yang efisien dengan kompleksitas logaritmik O(log n), di mana n adalah jumlah elemen dalam array yang diurutkan. Dalam setiap langkah iterasi, ukuran masukan (array) dibagi menjadi setengah. Hal ini mengurangi ukuran masukan secara eksponensial dan memungkinkan pencarian dengan cepat. Dalam kasus terburuk, algoritma dapat menemukan elemen dalam logaritma basis 2 dari ukuran array.
Penggunaan Memori (Space Complexity):
Algoritma Binary Search hanya menggunakan sedikit memori tambahan selain array yang diberikan untuk penyimpanan elemen.
Space complexity dari Binary Search adalah O(1) karena penggunaan memori tidak tergantung pada ukuran masukan.
Algoritma ini hanya menggunakan beberapa variabel sementara untuk menyimpan indeks awal, indeks akhir, indeks tengah, dan elemen yang dicari.
Jadi, kompleksitas waktu (time complexity) Binary Search adalah O(log n) pada semua kasus, sedangkan kompleksitas ruang (space complexity) adalah O(1). Algoritma Binary Search efisien untuk mencari elemen dalam array terurut dengan cepat.
*/
