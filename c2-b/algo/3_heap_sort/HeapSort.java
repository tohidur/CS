public class HeapSort {
    public void sort(int arr[]) {
        int n = arr.length;
    }

    void heapify(int arr[], int n, int i) {
    }

    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        int n = arr.length;
        HeapSort ob = new HeapSort();
        ob.sort(arr);
        
        printArray(arr);
    }
}
