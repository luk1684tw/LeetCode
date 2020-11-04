#define min(a, b) (((a) > (b))? (b) : (a))
#define max(a, b) (((a) > (b))? (a) : (b))

int maxArea(int* height, int heightSize)
{
    int start = 0, end = heightSize - 1;
    int maxArea = 0;
    while (start < end)
    {
        maxArea = max(maxArea, min(height[start], height[end]) * (end - start));
        if (height[start] < height[end])
            start++;
        else
            end--;
    }
    return maxArea;
}