#include<iostream>
using namespace std;

int main(){
     // int n;
    // cin>>n;

    // int* arr = new int[n];

    // for (int i = 0; i < n; i++)
    // {
    //    cin>>arr[i];
    // }
    // int totalSum = getSum(arr, n);
    // cout<<totalSum<<endl;
    // delete [] arr;


//CREATING 2D ARRAYS--->

// int n, m;
// cout<<"Enter the row you want to print "<<endl;
// cin>>m;
// cout<<"Enter the column you want to print "<<endl;
// cin>>n;

// int ** arr = new int*[n];

// for (int i = 0; i < n; i++)
// {
//     arr[i] = new int[m];

//     //creation done
// }

// cout<<"Enter the inputs"<<endl;

// for (int i = 0; i < n ; i++)
// {
//     for (int j = 0; j <m; j++)
//     {
//         cin>>arr[i][j];
//     }
    
// }

// for (int i = 0; i < n ; i++)
// {
//     for (int j = 0; j <m; j++)
//     {
//         cout<<" "<<arr[i][j]<<" ";
//     }
//     cout<<endl;
    
// }


// //releasing the memory
// for (int i = 0; i < n; i++)
// {
//     delete [] arr[i];
// }

// delete [] arr;


//CREATING THE JAGGED ARAY [in heap memory]-->

int rows;
cout<<"Enter the  rows you want to print"<<endl;
cin>>rows;
int **arr = new int *[rows];
int *cols = new int [rows];
cout<<"Enter the cols for the each row"<<endl;
for (int i = 0; i < rows; i++)

{
    int col;
    cin>>col;
   arr[i] = new int [col];
   cols[i] = col;
}

//inputs for the jaddged array

cout<<"Enter the input for jagged array"<<endl;
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols[i]; j++)
    {
      cin>>arr[i][j];
    }
    cout<<endl;
    
}

//printing the jagged array;

for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols[i]; j++)
    {
       cout<<" "<<arr[i][j]<<" ";
    }
    cout<<endl;
}

// releasing the memory

for (int i = 0; i < rows; i++)
{
    delete [] arr[i];
}

delete [] arr;
delete [] cols;


}