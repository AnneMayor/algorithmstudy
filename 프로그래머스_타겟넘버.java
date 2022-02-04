public class 프로그래머스_타겟넘버 {

    public int solution(int[] numbers, int target) {
        
        int answer = recursiveSearch(numbers, target, 0, 0);
        return answer;
    }

    public int recursiveSearch(int[] numbers, int target, int count, int sum) {
        // 여기 진짜 조심하자...제발...ㅠㅠ조건 잘보기...!ㅠㅠ
        if(count >= numbers.length) {
            if(target == sum) return 1;
            return 0;
        }

        return recursiveSearch(numbers, target, count+1, sum+numbers[count]) + recursiveSearch(numbers, target, count+1, sum-numbers[count]);
    }
}
