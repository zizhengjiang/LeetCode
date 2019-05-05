class MedianFinder {
    private Queue<Integer> minHeap = new PriorityQueue(), maxHeap = new PriorityQueue();
    /** initialize your data structure here. */
    public void addNum(int num) {
        maxHeap.add(num);
        minHeap.add(-maxHeap.poll());
        
        if (maxHeap.size() < minHeap.size())
            maxHeap.add(-minHeap.poll());
    }
    
    public double findMedian() {
        return maxHeap.size() > minHeap.size() ? maxHeap.peek() : (maxHeap.peek() - minHeap.peek()) * 0.5;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */