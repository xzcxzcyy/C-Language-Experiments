/*
 * 斐波那契
 */

#include <stdio.h>

/* 
 * 为了避免重复计算，应当使用数组 f[] 进行记忆化
 */
long long f[10000];

int main(void)
{
    f[1] = f[2] = 1;
    int i, k;
    /* 为了扩大数据范围，应当使用 long long 类型保存 sum ，
     * 并将 fabonacci() 函数返回值类型也改为 long long 
     */

    long long sum = 0, fabonacci(int n);
    printf("Input n:");
    scanf("%d", &k); //输入5， sum 此时为0， k 此时为5
    for (i = 1; i <= k; i++)
    {
        sum += fabonacci(i);
        printf("i = %d\tthe sum is %lld\n", i, sum);
    }
    return 0;
}

/*
 * 由于 k 和 sum 是 main() 的局部变量，故它们在 main() 以外之处不可见
 */
long long fabonacci(int n)
{
    /* 如果 f[n] 已经被计算过，就直接返回 */
    if (f[n])
    {
        return f[n];
    }
    else
    {
        /* 否则就更新其值并返回 */
        f[n] = fabonacci(n - 1) + fabonacci(n - 2);
        return f[n];
    }
}
