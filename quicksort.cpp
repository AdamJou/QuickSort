#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <ctime>
#include <conio.h>

using namespace std;

ofstream out;

int partition(int arr[], int low, int high);



int med3(int tab[], long left, long right)
{
    if (right - left < 3) return tab[left];
    else
    {
        int* med = new int[3];
        med[0] = tab[left];
        med[1] = tab[left + ((right - left) / 2)];
        med[2] = right;
        sort(med, med + 3);
        int ans = med[1];
        delete[] med;
        return ans;
    }
}


int med5(int tab[], long left, long right)
{
    if (right - left < 5) return med3(tab, left, right);
    else
    {
        int* med = new int[5];
        med[0] = tab[left];
        med[1] = tab[left + ((right - left) / 5)];
        med[2] = tab[left + ((right - left) / 2)];
        med[3] = tab[right - ((right - left) / 5)];
        med[4] = right;
        sort(med, med + 5);
        int ans = med[2];
        delete[] med;
        return ans;
    }
}

int med7(int tab[], long left, long right)
{
    if (right - left < 7) return med5(tab, left, right);
    else
    {
        int* med = new int[7];
        med[0] = tab[left];
        med[1] = tab[left + ((right - left) / 7)];
        med[2] = tab[(left + ((right - left) / 7) * 2)];
        med[3] = tab[left + ((right - left) / 2)];
        med[4] = tab[(right - ((right - left) / 7) * 2)];
        med[5] = tab[right - ((right - left) / 7)];
        med[6] = right;
        sort(med, med + 7);
        int ans = med[3];
        delete[] med;
        return ans;
    }
}

int partition_r(int arr[], int low, int high)
{

    srand(time(NULL));
    int random = low + rand() % (high - low);


    //swap(arr[random], arr[low]);

    return arr[random];
}





int partition( int arr[], int low, int high)
{
    int pivot = partition_r(arr,low,high);
    int i = low - 1, j = high + 1;
    
    while (true) {

   
        do {
            i++;
        } while (arr[i] < pivot);

       
        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
    
   
}











void quickSort(int arr[], int low, int high)


{
    if (low < high) {
      
        int pi = partition(arr, low , high);

       
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}










void printArray(int arr[], long long int size)
{
     int i;
    for (i = 0; i < size; i++)
        out << arr[i] << endl;
    cout << endl;
}


int main()
{

    int start;
    int stop;
    ifstream in;
    int tmp = 0; 
    int ilosc = 10000;
    out.open("Random_pivot_oversize.txt");
    string plik;
    string xd;
    while (ilosc < 1010000)
    {

        plik = to_string(ilosc) + ".txt";
        xd = "dane" + plik;
       cout <<xd<< endl;

        in.open(xd);

       int* arr = new  int[ilosc];
        for (long long int i = 0; i < ilosc; i++)
        {
            in >> tmp;

            arr[i] = tmp;
          //  cout << arr[i] << endl;
           
        }
        in.close();

        start = clock();
       quickSort(arr, 0, ilosc - 1);
       
       stop = (clock() - start) ;
   out << ilosc << ";" << stop << endl;

  //printArray(arr, ilosc);

        delete[] arr;
        ilosc = ilosc + 10000;
    }

    out.close();

    return 0;

}
