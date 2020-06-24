#include <bits/stdc++.h>
using namespace std;

void update(int index, int val, int n, int feed[], int arr[])
{
    int blocksize = ceil(sqrt(n));
    int feed_pointer = index / blocksize;
    feed[feed_pointer] = min(val, feed[feed_pointer]);
    arr[index] = val;
}

int query(int l, int r, int n, int feed[], int arr[])
{
    int min_in_range = INT_MAX;
    int blocksize = ceil(sqrt(n));

    while (l < r && l % blocksize != 0 && l != 0)
    {
        // traversing first block in range
        if (arr[l] < min_in_range)
        {
            min_in_range = arr[l];
        }
        l++;
    }
    while (l + blocksize <= r)
    {
        // traversing completely overlapped blocks in range
        if (feed[l / blocksize] < min_in_range)
        {
            min_in_range = feed[l / blocksize];
        }
        l += blocksize;
    }
    while (l <= r)
    {
        // traversing last block in range
        if (arr[l] < min_in_range)
        {
            min_in_range = arr[l];
        }
        l++;
    }
    return min_in_range;
}


void Build(int input[], int n, int arr[], int feed[])
{


    int feed_pointer = -1;

// calculating size of block
    int blocksize = ceil(sqrt(n));

// building the decomposed array
    for (int i = 0; i < n; i++)
    {
        arr[i] = input[i];
        if (i % blocksize == 0)
        {
            // entering next block
            // incementing block pointer
            feed_pointer++;
            feed[feed_pointer] = arr[i];
        }

        feed[feed_pointer] = min(feed[feed_pointer], arr[i]);

    }
}
int main()
{
    int input[] = {8, 5, 12, 4, 6, 1, 14 , 7, 7, 10};
    int n = sizeof(input) / sizeof(input[0]);
    int arr[n], feed[n];
    Build(input, n, arr, feed);
    cout << "query(7,9) : Before update" << "\t" << query(7, 9, n, feed, arr) << endl;
    update(8, 0, n, feed, arr); //update 8 index by 0
    cout << "query(7,9) : After update" << "\t" << query(7, 9, n, feed, arr) << endl;
    return 0;
}