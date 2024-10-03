// 上楼梯问题中可以适当增加缓存来消除重复计算
public int f(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    // hasSolvedList 可以理解成一个 Map，key 是 n，value 是 f(n)
    if (hasSolvedList.containsKey(n)) {
        return hasSovledList.get(n);
    }

    int ret = f(n - 1) + f(n - 2);
    hasSovledList.put(n, ret);
    return ret;
}
// 冒泡排序  
void bubbleSort(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换arr[j]和arr[j + 1]  
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 选择排序  
void selectionSort(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // 交换arr[i]和arr[minIdx]  
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// 插入排序  
void insertionSort(int[] arr) {
    int n = arr.length;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // 将arr[i]插入到已排序部分arr[0..i-1]  
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// 归并排序  
void mergeSort(int[] arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // 递归排序两个子数组  
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // 合并两个已排序的子数组  
        merge(arr, left, mid, right);
    }
}
void merge(int[] arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int[] L = new int[n1];
    int[] R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// 快速排序  
void quickSort(int[] arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        // 递归排序两个子数组  
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(int[] arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // 交换arr[i]和arr[j]  
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // 交换arr[i + 1]和arr[high] (或pivot)  
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
class ListNode {
    int val;
    ListNode next;
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }

    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            // 如果链表为空或只有一个节点，则不可能有环  
            return false;
        }
        ListNode slow = head;
        ListNode fast = head;
        // 快慢指针开始移动，直到它们相遇或快指针到达链表末尾  
        while (fast != null && fast.next != null) {
            slow = slow.next;          // 慢指针每次移动一步  
            fast = fast.next.next;     // 快指针每次移动两步  

            // 如果快慢指针相遇，说明链表中存在环  
            if (slow == fast) {
                return true;
            }
        }
        // 快指针到达链表末尾，说明链表中没有环  
        return false;
    }
}
class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }

    public ListNode findMiddle(ListNode head) {
        // 初始化快慢指针  
        ListNode slow = head;
        ListNode fast = head;
        // 快指针每次移动两步，慢指针每次移动一步  
        while (fast != null && fast.next != null) {
            slow = slow.next;  // 慢指针移动一步  
            fast = fast.next.next;  // 快指针移动两步  
        }

        // 当快指针到达链表末尾时，慢指针指向中间节点  
        return slow;
    }
}
