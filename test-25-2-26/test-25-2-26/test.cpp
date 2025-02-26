
//求助｜字节面试 - 小于n的最大数
//呆头贴
//发起于 2024 - 08 - 06
//最近编辑于 2024 - 08 - 06
//来自中国
//题目
//给定一个数n，如23121，给定一组数字a, 如｛2，4，9｝，求a中元素组成的小于n的最大数，如小于23121的最大数为22999
//
//面试的时候没做出来，后来想了一下思路上可能有问题，整理一下现在的思路是先比较第一位数，如果a中不存在比当前这位数小的，直接放弃，比较下一个数，如果下一个数找到了比这位数小的，继续比较下下位数，将下下位数的所有数字组合和当前这个数字组合拼在一起比较
//
//具体来说就是：
//
//该算法首先对给定的数字列表 a 进行降序排序。然后，通过递归函数 generate_combinations 生成所有可能的数字组合。在递归函数中，对于输入数字 n 的每一位，遍历数字列表 a ，如果找到小于当前位数字的数字，就以该数字为开头继续递归生成下一位的数字组合；如果找不到小于当前位的数字，则从数字列表 a 的末尾开始选择数字进行递归。当生成的数字组合长度与输入数字 n 的长度相同时，将其添加到候选列表 candidates 中。
//
//最后，对候选列表进行降序排序，并遍历找到小于输入数字 n 的最大数字。如果没有找到这样的数字，则返回 - 1 。
//
//时间复杂度分析：
//
//对数字列表 a 进行排序的时间复杂度为 O(len(a) * log(len(a))) 。
//
//生成数字组合的递归过程中，对于数字 n 的每一位都要遍历数字列表 a ，所以总的递归次数与数字 n 的位数 m 和数字列表 a 的长度 k 有关，大致为 k ^ m 。
//
//对候选列表进行排序的时间复杂度为 O(len(candidates) * log(len(candidates))) ，由于候选列表的长度取决于数字 n 和数字列表 a ，最坏情况下可能接近 k ^ m ，所以排序的时间复杂度也接近 O(k ^ m * log(k ^ m)) 。
//
//综合起来，整个算法的时间复杂度主要由生成数字组合和对候选列表排序决定，大致为 O(k ^ m * log(k ^ m)) 。
//



//常规解法
def find_max_number_less_than_n(n, a) :
    a.sort(reverse = True)
    num_str = str(n)
    candidates = []

    def generate_combinations(digit_index, current_candidate) :
    if digit_index == len(num_str) :
        candidates.append(int(current_candidate))
        return

        current_digit = int(num_str[digit_index])
        found_smaller = False

        for num in a :
if num < current_digit :
    generate_combinations(digit_index + 1, current_candidate + str(num))
    found_smaller = True

    elif num == current_digit :
    generate_combinations(digit_index + 1, current_candidate + str(num))

    if not found_smaller :
        for num in a[:: - 1] :
            generate_combinations(digit_index + 1, current_candidate + str(num))

            generate_combinations(0, "")

            candidates.sort(reverse = True)
            for candidate in candidates :
if candidate < n :
    return candidate

    return -1

    n = 23121
    a = [2, 4, 9]
    print(find_max_number_less_than_n(n, a))

 


    //2.优化：最大堆

import heapq

    def find_max_number_less_than_n(n, a) :
    a.sort(reverse = True)
    num_str = str(n)
    max_heap = []

    def generate_combinations(digit_index, current_value) :
    if current_value > n:
return
if digit_index == len(num_str) :
    heapq.heappush(max_heap, (-current_value, current_value))  # 使用负数来实现最大堆
    return

    current_digit = int(num_str[digit_index])
    found_smaller = False

    for num in a :
if num < current_digit :
    generate_combinations(digit_index + 1, current_value * 10 + num)
    found_smaller = True

    elif num == current_digit :
    generate_combinations(digit_index + 1, current_value * 10 + num)

    if not found_smaller :
        for num in a[:: - 1] :
            generate_combinations(digit_index + 1, current_value * 10 + num)

            generate_combinations(0, 0)

            if max_heap :
                return max_heap[0][1]
            else:
return -1

n = 23121
a = [2, 4, 9]
print(find_max_number_less_than_n(n, a))
