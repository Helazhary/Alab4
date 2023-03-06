#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <cstdlib>
#include <fstream>

using namespace std;

int bubble_sort_comparisons_count(int [], int);
int insertion_sort_comparisons_count(int[], int);
int selection_sort_comparisons_count(int [], int);
int heapify(int [], int, int);
int heap_sort_comparisons_count(int [], int);
int build_heap(int [], int);

void count_comparisons();
void test_time();
void display_arr(int* arr, int n)
{
	cout<<endl;
	for (int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}



int main() 
{
srand(time(NULL));
ofstream outputt("comparisons.csv");
	outputt << "n" << ',' 
    << "Sorted Heap" << ',' << "Sorted insertion" << ',' << "Sorted Selection" << ',' << "Sorted Bubble" 
    <<"," <<"Inverse Heap" << ',' << "Inverse insertion" << ',' << "Inverse Selection" << ',' << "Inverse Bubble" 
    <<","<< "Rand Heap" << ',' << "Rand insertion" << ',' << "Rand Selection" << ',' << "Rand Bubble" << endl; 

    ofstream outputc("comparisonss.csv");
	outputc << "n" << ',' 
    << "Sorted Heap" << ',' << "Sorted insertion" << ',' << "Sorted Selection" << ',' << "Sorted Bubble" 
    <<"," <<"Inverse Heap" << ',' << "Inverse insertion" << ',' << "Inverse Selection" << ',' << "Inverse Bubble" 
    <<","<< "Rand Heap" << ',' << "Rand insertion" << ',' << "Rand Selection" << ',' << "Rand Bubble" << endl; 
for (int i = 10; i <= 40; i++)
{
  int *best = new int[i];

  int *worst = new int[i];
  int *worst2 = new int[i];
  int *worst3 = new int[i];
  int *worst4 = new int[i];

  int *avg = new int[i];
   int *avg2 = new int[i];
    int *avg3 = new int[i];
     int *avg4 = new int[i];
 
 iota(best, best + i, 1);	//best case array
			
  for (int j = 0; j < i; j++)
  {
    worst[j] = i-j ; //worst case array
    worst2[j] = i-j ; 
    worst3[j] = i-j ; 
    worst4[j] = i-j ; 

   avg[j] = (rand() % 30 + 1); //random values for avg case array approx
   avg2[j] = (rand() % 30 + 1);
   avg3[j] = (rand() % 30 + 1);
   avg4[j] = (rand() % 30 + 1);
  }
  

//   cout<<left<<setw(3)<<i
//      <<"  "<<setw(3)<<bubble_sort_comparisons_count(best, i)
//      <<"  "<<setw(3)<<bubble_sort_comparisons_count(worst, i)
//      <<"  "<<setw(3)<<bubble_sort_comparisons_count(avg, i)

//      <<"  "<<setw(3) <<insertion_sort_comparisons_count(best, i)
//      <<"  "<<setw(3) <<insertion_sort_comparisons_count(worst2, i)
//      <<"  "<<setw(3) <<insertion_sort_comparisons_count(avg2, i)

//      <<"  "<<setw(3) <<selection_sort_comparisons_count(best, i)
//      <<"  "<<setw(3) <<selection_sort_comparisons_count(worst3, i)
//      <<"  "<<setw(3) <<selection_sort_comparisons_count(avg3, i)

//      <<"  "<<setw(3) <<heap_sort_comparisons_count(best, i)
//      <<"  "<<setw(3) <<heap_sort_comparisons_count(worst4, i)
//      <<"  "<<setw(3) <<heap_sort_comparisons_count(avg4, i)
//      <<endl;

//---------------------------

    int start_timebb = clock();bubble_sort_comparisons_count(best, i);
    int end_timebb = clock();
double execution_timebb = (double)(end_timebb - start_timebb) / CLOCKS_PER_SEC;

    int start_timebw = clock();bubble_sort_comparisons_count(worst, i);
    int end_timebw = clock();
double execution_timebw = (double)(end_timebw - start_timebw) / CLOCKS_PER_SEC;

    int start_timeba = clock();bubble_sort_comparisons_count(avg, i);
    int end_timeba = clock();
double execution_timeba = (double)(end_timeba - start_timeba) / CLOCKS_PER_SEC;


     int start_timeib = clock();insertion_sort_comparisons_count(best, i);
     int end_timeib = clock();
double execution_timeib = (double)(end_timeib - start_timeib) / CLOCKS_PER_SEC;

     int start_timeiw = clock();insertion_sort_comparisons_count(worst2, i);
     int end_timeiw = clock();
double execution_timeiw = (double)(end_timeiw - start_timeiw) / CLOCKS_PER_SEC;

     int start_timeia = clock();insertion_sort_comparisons_count(avg2, i);
     int end_timeia = clock();
double execution_timeia = (double)(end_timeia - start_timeia / CLOCKS_PER_SEC);


     int start_timesb = clock();selection_sort_comparisons_count(best, i);
     int end_timesb= clock();
double execution_timesb = (double)(end_timesb - start_timesb) / CLOCKS_PER_SEC;

     int start_timesw = clock();selection_sort_comparisons_count(worst3, i);
     int end_timesw = clock();
double execution_timesw = (double)(end_timesw - start_timesw) / CLOCKS_PER_SEC;

     int start_timesa = clock();selection_sort_comparisons_count(avg3, i);
     int end_timesa = clock();
double execution_timesa = (double)(end_timesa - start_timesa) / CLOCKS_PER_SEC;


     int start_timehb = clock();heap_sort_comparisons_count(best, i);
     int end_timehb = clock();
double execution_timehb = (double)(end_timehb - start_timehb) / CLOCKS_PER_SEC;

     int start_timehw = clock();heap_sort_comparisons_count(worst4, i);
     int end_timehw = clock();
double execution_timehw = (double)(end_timehw - start_timehw) / CLOCKS_PER_SEC;

     int start_timeha = clock();heap_sort_comparisons_count(avg4, i);
     int end_timeha = clock();
double execution_timeha = (double)(end_timeha - start_timeha) / CLOCKS_PER_SEC;






outputt<< i<<","
       <<execution_timehb<<","  << execution_timeib<<","<< execution_timesb<<","<<execution_timebb<<","
       << execution_timehw<<","  << execution_timeiw<<","<< execution_timesw<<","<<execution_timebw<<","
       << execution_timeha<<","  << execution_timeia<<","<< execution_timesa<<","<<execution_timeba<<","<<endl;

 
 iota(best, best + i, 1);	//best case array
			
  for (int j = 0; j < i; j++)
  {
    worst[j] = i-j ; //worst case array
    worst2[j] = i-j ; 
    worst3[j] = i-j ; 
    worst4[j] = i-j ; 

   avg[j] = (rand() % 30 + 1); //random values for avg case array approx
   avg2[j] = (rand() % 30 + 1);
   avg3[j] = (rand() % 30 + 1);
   avg4[j] = (rand() % 30 + 1);
  }
  

outputc << i << ","
     << bubble_sort_comparisons_count(best, i) << ","
     << bubble_sort_comparisons_count(worst, i) << ","
     << bubble_sort_comparisons_count(avg, i) << ","
     << insertion_sort_comparisons_count(best, i) << ","
     << insertion_sort_comparisons_count(worst2, i) << ","
     << insertion_sort_comparisons_count(avg2, i) << ","
     << selection_sort_comparisons_count(best, i) << ","
     << selection_sort_comparisons_count(worst3, i) << ","
     << selection_sort_comparisons_count(avg3, i) << ","
     << heap_sort_comparisons_count(best, i) << ","
     << heap_sort_comparisons_count(worst4, i) << ","
     << heap_sort_comparisons_count(avg4, i)
     << endl;


 
}
}


int bubble_sort_comparisons_count(int arr[], int n) 
{
    int i, j, comp = 0;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++) {
            comp++;
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    return comp;
}

int insertion_sort_comparisons_count(int arr[], int n)
{
    int i, key, j, comp = 0;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        
        comp++;
        while (j >= 0 && arr[j] > key)
        {
            comp++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        if(j<0)
        comp--;
        arr[j + 1] = key;
    }
    return comp;

}
// check how to count comparisons here
int selection_sort_comparisons_count(int arr[], int n) 
{

    

    int i, j, min_idx;
int comp =0;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
			   
                if (++comp && arr[j] < arr[min_idx])
                min_idx = j;
        }

        if(min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
    return comp;

}

int heapify(int arr[], int n, int i) {

 int comp=0;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n) 
    {
       
        if (++comp && arr[l] > arr[largest])
            largest = l;
    }


    if (r < n) 
    {
   
        if (++comp && arr[r] > arr[largest])
            largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
       comp+=heapify(arr, n, largest);
    }

return comp;
   
}

int build_heap(int arr[], int n) {

  int comp=0;
    for (int i = n / 2 - 1; i > 0; i--)
        comp+=heapify(arr, n, i);

    return comp;
}
// check how to count comparisons here
int heap_sort_comparisons_count(int arr[], int n) 
{
   

 int comp = build_heap(arr, n);

    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
         comp+=heapify(arr, i, 0);
    }

return comp;
}



