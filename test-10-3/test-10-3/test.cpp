// ��¥�������п����ʵ����ӻ����������ظ�����
public int f(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    // hasSolvedList ��������һ�� Map��key �� n��value �� f(n)
    if (hasSolvedList.containsKey(n)) {
        return hasSovledList.get(n);
    }

    int ret = f(n - 1) + f(n - 2);
    hasSovledList.put(n, ret);
    return ret;
}
// ð������  
void bubbleSort(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // ����arr[j]��arr[j + 1]  
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ѡ������  
void selectionSort(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // ����arr[i]��arr[minIdx]  
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// ��������  
void insertionSort(int[] arr) {
    int n = arr.length;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // ��arr[i]���뵽�����򲿷�arr[0..i-1]  
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// �鲢����  
void mergeSort(int[] arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // �ݹ���������������  
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // �ϲ������������������  
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
// ��������  
void quickSort(int[] arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        // �ݹ���������������  
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
            // ����arr[i]��arr[j]  
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // ����arr[i + 1]��arr[high] (��pivot)  
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
            // �������Ϊ�ջ�ֻ��һ���ڵ㣬�򲻿����л�  
            return false;
        }
        ListNode slow = head;
        ListNode fast = head;
        // ����ָ�뿪ʼ�ƶ���ֱ�������������ָ�뵽������ĩβ  
        while (fast != null && fast.next != null) {
            slow = slow.next;          // ��ָ��ÿ���ƶ�һ��  
            fast = fast.next.next;     // ��ָ��ÿ���ƶ�����  

            // �������ָ��������˵�������д��ڻ�  
            if (slow == fast) {
                return true;
            }
        }
        // ��ָ�뵽������ĩβ��˵��������û�л�  
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
        // ��ʼ������ָ��  
        ListNode slow = head;
        ListNode fast = head;
        // ��ָ��ÿ���ƶ���������ָ��ÿ���ƶ�һ��  
        while (fast != null && fast.next != null) {
            slow = slow.next;  // ��ָ���ƶ�һ��  
            fast = fast.next.next;  // ��ָ���ƶ�����  
        }

        // ����ָ�뵽������ĩβʱ����ָ��ָ���м�ڵ�  
        return slow;
    }
}
