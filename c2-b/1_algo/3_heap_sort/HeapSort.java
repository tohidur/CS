public class HeapSort {
    void swap(int arr[], int i, int j) {
        System.out.println("swap " + arr[i] + " " + arr[j]);
        int c = arr[i];
        arr[i] = arr[j];
        arr[j] = c;
    }

    void print(int i) {
        System.out.println(i);
    }

    void heapify(int arr[], int i) {
        System.out.println("heapify");
        int fp = (i - 1) / 2;

        for (int j = fp; j >= 0; j--) {

            int l_ch = 2 * j + 1;
            int r_ch = 2 * j + 2;

            int k, l;

            if arr[l_ch] > arr[r_ch] {
                k = l_ch;
                l = j;
                while (k <= arr.length - 1) {
                }
            } else {

            }

            while (true) {
                if (arr[p] < arr[k]) {
                    swap(arr, p, k);
                    k = p;
                }

                if (p == 0)
                    break;

                p = (p > 1) ? (p - 1) / 2 : 0;
            }
        }
        System.out.println("===\n");
    }

    public void sort(int arr[]) {
        for (int i = arr.length - 1; i > 0; i--) {
            heapify(arr, i);
            printArray(arr);
            System.out.println("max out");
            swap(arr, 0, i);
            printArray(arr);
        }
    }

    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = { 7, 11, 6, 5, 13, 12 };

        printArray(arr);
        HeapSort ob = new HeapSort();
        ob.sort(arr);
        System.out.println("After sort:");
        printArray(arr);
        
    }
}
