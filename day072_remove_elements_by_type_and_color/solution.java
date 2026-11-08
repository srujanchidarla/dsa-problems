import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class SolutionBruteForce {
    // O(n^2) time | O(n) space — rescan from the start after every removal.
    public boolean canRemoveAll(int[] types, int[] colors, int[] groupSize) {
        List<Integer> t = new ArrayList<>();
        List<Integer> c = new ArrayList<>();
        for (int x : types) t.add(x);
        for (int x : colors) c.add(x);
        while (true) {
            boolean removed = false;
            int i = 0;
            while (i < t.size()) {
                int j = i;
                while (j < t.size() && t.get(j).equals(t.get(i))
                        && c.get(j).equals(c.get(i))) j++;
                if (j - i >= groupSize[t.get(i)]) {
                    int k = groupSize[t.get(i)];
                    for (int d = 0; d < k; d++) { t.remove(i); c.remove(i); }
                    removed = true;
                    break;
                }
                i = j;
            }
            if (!removed) return t.isEmpty();
        }
    }
}

class Solution {
    // O(n) time | O(n) space — one pass with a stack of runs.
    public boolean canRemoveAll(int[] types, int[] colors, int[] groupSize) {
        Deque<int[]> stack = new ArrayDeque<>(); // {type, color, count}
        for (int i = 0; i < types.length; i++) {
            int t = types[i], c = colors[i];
            if (!stack.isEmpty() && stack.peek()[0] == t && stack.peek()[1] == c) {
                stack.peek()[2]++;
            } else {
                stack.push(new int[]{t, c, 1});
            }
            if (stack.peek()[2] == groupSize[t]) stack.pop();
        }
        return stack.isEmpty();
    }
}
