int repeatingInteger (vector<int> &arr){

    for(int i =0;i<arr.size();i++){

        int index = abs(arr[i]) - 1;

        arr[index] *= -1;

        if(arr[index] > 0){

            return abs(arr[i]);

        }

    }

    return 0;

}

 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)

{

    // Write your code here 

    pair<int, int> res;

    n = arr.size();

    long long sum = 0, expectedSum;

    for(int i = 0; i<n; i++){

        sum = sum + arr[i];

    }

    int repeatingElement = repeatingInteger(arr);

    expectedSum = (n*(n+1))/2;

    long long diff = expectedSum - sum;

 

    

    res.first = repeatingElement + (int)diff;

    res.second = repeatingElement;

    return res;

}