using System;
using System.Collections.Generic;

class Program
{
    static int Partition(List<int> arr, int n)
    {
        int size = arr.Count;
        int k = 0;
        int r = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] <= r)
            {
                r -= arr[i];
            }
            else
            {
                k++;
                r = n - arr[i];
            }
        }
        return k;
    }

    static void Main(string[] args)
    {
        int n, k;
        k = int.Parse(Console.ReadLine());
        n = int.Parse(Console.ReadLine());

        List<int> arr = new List<int>();
        int sum = 0;
        int minim = int.MinValue;
        string[] input = Console.ReadLine().Split();
        for (int i = 0; i < input.Length; i++)
        {
            arr.Add(int.Parse(input[i]));
            sum += arr[i];
            minim = Math.Max(minim, arr[i]);
        }
        for (int i = minim; i <= sum; i++)
        {
            if (Partition(arr, i) <= k)
            {
                Console.WriteLine(i * n);
                return;
            }
        }
    }
}