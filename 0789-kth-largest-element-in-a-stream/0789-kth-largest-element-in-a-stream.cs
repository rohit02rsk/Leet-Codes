public class KthLargest {
    PriorityQueue<int, int> pq;
    int k;
    
    public KthLargest(int k, int[] nums) {
        this.k = k;
        pq = new PriorityQueue<int, int>();

        foreach (int num in nums) {
            Add(num);
        }
    }
    
    public int Add(int val) {
        pq.Enqueue(val, val);
        
        while (pq.Count > k)
            pq.Dequeue();

        return pq.Peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.Add(val);
 */