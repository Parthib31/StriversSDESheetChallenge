bool f = false;
        int breakPoint;
        int n = nums.size();
        for(int i = n-2 ; i >= 0 ; i--)
        {
            if(nums[i] < nums[i+1])
            {
                breakPoint = i;
                f = 1;
                break;
            }
        }
        if(f == 0) 
            reverse(nums.begin(), nums.end());
        else
        {
            for(int i = n-1 ; i >= breakPoint+1 ; i--)
            {
                if(nums[i] > nums[breakPoint])
                {
                    swap(nums[breakPoint], nums[i]);
                    reverse(nums.begin() + breakPoint + 1, nums.end());
                    break;
                }
            }
        }
        return;