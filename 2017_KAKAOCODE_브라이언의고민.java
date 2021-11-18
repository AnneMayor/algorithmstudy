import java.io.InputStream;
import java.util.ArrayDeque;

public class Solution {
    public String solution(String sentence) {
        try {
            String answer = "";
            ArrayDeque<Character> inputs = new ArrayDeque<>();
            int[] use = new int[26];
            for (int i = 0; i < sentence.length(); i++) {
                inputs.add(sentence.charAt(i));
                if (sentence.charAt(i) >= 'a' && sentence.charAt(i) <= 'z') {
                    use[sentence.charAt(i) - 'a']++;
                }
            }

            while (!inputs.isEmpty()) {
                char firstElement = inputs.poll();
                ArrayDeque<Character> word = new ArrayDeque<>();

                // 시작값이 소문자일 때
                if (firstElement >= 'a' && firstElement <= 'z') {
                    if (use[firstElement - 'a'] != 2)
                        return "invalid";
                    if (inputs.peek() >= 'a' && inputs.peek() <= 'z')
                        return "invalid";
                    word.add(inputs.poll());
                    char thirdInput = inputs.poll();
                    if (firstElement != thirdInput && thirdInput >= 'a' && thirdInput <= 'z') {
                        for (int i = 1; i < use[thirdInput - 'a']; i++) {
                            if (inputs.peek() >= 'a' && inputs.peek() <= 'z')
                                return "invalid";
                            word.add(inputs.poll());
                            if (inputs.poll() != thirdInput)
                                return "invalid";
                        }
                        if (inputs.peek() >= 'a' && inputs.peek() <= 'z')
                            return "invalid";
                        word.add(inputs.poll());
                        if (inputs.poll() != firstElement)
                            return "invalid";
                    } else if (firstElement != thirdInput) {
                        // 앞 뒤에만 있는 경우
                        word.add(thirdInput);
                        while (inputs.peek() != firstElement) {
                            if (inputs.peek() >= 'a' && inputs.peek() <= 'z')
                                return "invalid";
                            word.add(inputs.poll());
                        }
                        inputs.poll();
                    }
                } else {
                    // 시작값이 대문자일 때
                    word.add(firstElement);
                    if(inputs.isEmpty()) {
                        while(!word.isEmpty()) {
                            answer += word.poll();
                        }
                        return answer;
                    }

                    char secondInput = inputs.poll();

                    if (secondInput >= 'a' && secondInput <= 'z') {
                        if (use[secondInput - 'a'] == 2)
                            inputs.addFirst(secondInput);
                        else {
                            for (int i = 1; i < use[secondInput - 'a']; i++) {
                                if (inputs.peek() >= 'a' && inputs.peek() <= 'z') 
                                {
                                    return "invalid";
                                }
                                word.add(inputs.poll());
                                if (inputs.poll() != secondInput){
                                    return "invalid";
                                }
                            }

                            if (inputs.peek() >= 'a' && inputs.peek() <= 'z') return "invalid";
                            word.add(inputs.poll());
                        }
                    } else {
                        word.add(secondInput);
                        if(inputs.isEmpty()) {
                            while(!word.isEmpty()) {
                                answer += word.poll();
                            }
                            return answer;
                        }

                        while (inputs.peek() >= 'A' && inputs.peek() <= 'Z') {
                            word.add(inputs.poll());
                            if (inputs.isEmpty())
                                break;
                        }

                        if (!inputs.isEmpty()) {
                            if (use[inputs.peek() - 'a'] != 2)
                                inputs.addFirst(word.pollLast());
                        }
                    }
                }

                while (!word.isEmpty()) {
                    answer += word.poll();
                }

                if (!inputs.isEmpty())
                    answer += " ";
            }

            return answer;
        } catch (Exception e) {
            return "invalid";
        }
    }
}
