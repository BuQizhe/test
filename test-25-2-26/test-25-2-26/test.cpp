
//�������ֽ����� - С��n�������
//��ͷ��
//������ 2024 - 08 - 06
//����༭�� 2024 - 08 - 06
//�����й�
//��Ŀ
//����һ����n����23121������һ������a, ���2��4��9������a��Ԫ����ɵ�С��n�����������С��23121�������Ϊ22999
//
//���Ե�ʱ��û����������������һ��˼·�Ͽ��������⣬����һ�����ڵ�˼·���ȱȽϵ�һλ�������a�в����ڱȵ�ǰ��λ��С�ģ�ֱ�ӷ������Ƚ���һ�����������һ�����ҵ��˱���λ��С�ģ������Ƚ�����λ����������λ��������������Ϻ͵�ǰ����������ƴ��һ��Ƚ�
//
//������˵���ǣ�
//
//���㷨���ȶԸ����������б� a ���н�������Ȼ��ͨ���ݹ麯�� generate_combinations �������п��ܵ�������ϡ��ڵݹ麯���У������������� n ��ÿһλ�����������б� a ������ҵ�С�ڵ�ǰλ���ֵ����֣����Ը�����Ϊ��ͷ�����ݹ�������һλ��������ϣ�����Ҳ���С�ڵ�ǰλ�����֣���������б� a ��ĩβ��ʼѡ�����ֽ��еݹ顣�����ɵ�������ϳ������������� n �ĳ�����ͬʱ��������ӵ���ѡ�б� candidates �С�
//
//��󣬶Ժ�ѡ�б���н������򣬲������ҵ�С���������� n ��������֡����û���ҵ����������֣��򷵻� - 1 ��
//
//ʱ�临�Ӷȷ�����
//
//�������б� a ���������ʱ�临�Ӷ�Ϊ O(len(a) * log(len(a))) ��
//
//����������ϵĵݹ�����У��������� n ��ÿһλ��Ҫ���������б� a �������ܵĵݹ���������� n ��λ�� m �������б� a �ĳ��� k �йأ�����Ϊ k ^ m ��
//
//�Ժ�ѡ�б���������ʱ�临�Ӷ�Ϊ O(len(candidates) * log(len(candidates))) �����ں�ѡ�б�ĳ���ȡ�������� n �������б� a �������¿��ܽӽ� k ^ m �����������ʱ�临�Ӷ�Ҳ�ӽ� O(k ^ m * log(k ^ m)) ��
//
//�ۺ������������㷨��ʱ�临�Ӷ���Ҫ������������ϺͶԺ�ѡ�б��������������Ϊ O(k ^ m * log(k ^ m)) ��
//



//����ⷨ
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

 


    //2.�Ż�������

import heapq

    def find_max_number_less_than_n(n, a) :
    a.sort(reverse = True)
    num_str = str(n)
    max_heap = []

    def generate_combinations(digit_index, current_value) :
    if current_value > n:
return
if digit_index == len(num_str) :
    heapq.heappush(max_heap, (-current_value, current_value))  # ʹ�ø�����ʵ������
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
