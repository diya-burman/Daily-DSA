long long int binarySearch(int num)
{
    int s = 0;
    int e = num;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        long long int sq = mid * mid;
        if (sq == num)
        {
            return mid;
        }
        if (sq < num)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int floorSqrt(int n)
{
    return binarySearch(n);
}
