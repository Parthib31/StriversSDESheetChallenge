class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comp);

        int currWeight = 0;
        double finalValue = 0.0;
        
        for (int i = 0; i < n; i++) {
            
            if(currWeight + arr[i].weight <= W)
            {
                currWeight += arr[i].weight;
                finalValue += (double)arr[i].value;
            }
            else
            {
                int weightRemaining = W - currWeight;
                finalValue += weightRemaining * ((double)arr[i].value / (double)arr[i].weight);
                break;
            }
        }
        return finalValue;
    }
        
};