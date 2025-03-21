class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty() || lists.size() == 0)
        {
            return NULL;
        }

        // This comparator will be used to build MIN HEAP.
        // We use a LAMBDA to define the comparator.
        auto comp = [&](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };

        // This priority queue is our MIN HEAP
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

        /*
        * We iterate the list of LinkedLists and add the head
        * of every list to the heap (the heap becomes of size k)
        */
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                pq.push(lists[i]);
            }
        }

        ListNode dummyHead(0);
        ListNode *tail = &dummyHead;

        // Simply start popping the nodes from the heap and keep adding them to the list;
        while (!pq.empty())
        {
            // Pop the top element and store it in temp
            auto temp = pq.top();
            pq.pop();

            // Add it to the list
            tail->next = temp;
            // Move the tail to the newly added element
            tail = tail->next;

            // if there are more nodes attached to this node in the list
            // Push the next node of the list into the heap
            if (temp->next)
            {
                pq.push(temp->next);
            }
        }

        // Make sure you set the next pointer of the last added node to NULL
        tail->next = NULL;

        // We used the dummyHead to keep track of the start of the list.
        return dummyHead.next;
    }
};
