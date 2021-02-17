public class HeapSort {
    void swap(int arr[], int i, int j) {
        int c = arr[i];
        arr[i] = arr[j];
        arr[j] = c;
    }

    void heapify(int arr[], int last_index) {
        // System.out.println("heapfying: " + last_index);
        int first_parent = (last_index > 1)?((last_index - 1) / 2):0;
        // System.out.println("first parent: " + first_parent);

        for (int i = first_parent; i >= 0; i--) {
            int left_child = 2 * i + 1;
            int right_child = 2 * i + 2;
     
            int parent_tmp = i;
            // System.out.println("starting while loop: ");
            // System.out.println("parent_tmp: "+ parent_tmp);
            // System.out.println("left_child: "+left_child );
            // System.out.println("left_child: "+right_child );

            while (left_child <= last_index || right_child <= last_index) {
                int idx_tmp;

                if (left_child <= last_index && right_child <= last_index) {
                    idx_tmp = (left_child > right_child) ? left_child : right_child;
                } else {
                    idx_tmp = (left_child > last_index) ? right_child : left_child;
                }


                System.out.println("doing comparison: " + arr[parent_tmp] + " " + arr[idx_tmp]);
                if (arr[parent_tmp] < arr[idx_tmp]) {
                    swap(arr, parent_tmp, idx_tmp);
                    printArray(arr);
                    parent_tmp = idx_tmp;
                }

                left_child = 2 * idx_tmp + 1;
                right_child = 2 * idx_tmp + 2;
                // System.out.println(left_child);
                // System.out.println(right_child);
            }
        }
    }

    public void sort(int arr[]) {
        int n = arr.length;

        for (int i = n - 1; i > 0; i--) {
            printArray(arr);
            heapify(arr, i);
            swap(arr, 0, i);
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

